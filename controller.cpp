#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent) {}

Controller::~Controller() {}

void Controller::compute() {
  computeThread();

  // Compute QRunnable
  // Restart timer
  QElapsedTimer timer2;
  timer2.start();
  // Create M*P QRunnables

  // Join M*P QRunnables

  // stop timer

  // emit notifyComputeComplete(x, y)

  /*
  for (size_t i = 0; i < size; i++) {
      multiply  *t = new multiply(data);
      QThreadPool globalInstance()->start(+);
      globalInstance->notifyDone(xy)
          emit qRunnbleCompleted
    }*/
  emitQRunnableProgress(100);

  int time = timer2.elapsed();
  emitPthreadTime(time);
}

void Controller::computeThread() {
  pthread_t controllerThread;
  struct PathArgs *computeStruct = new PathArgs();

  computeStruct->controller = this;

  pthread_create(&controllerThread, NULL, computeThreads,
                 (void *)computeStruct);
  pthread_join(controllerThread, NULL);
  delete computeStruct;
}

QString Controller::getMatrixAPath() { return filePathA; }

QString Controller::getMatrixBPath() { return filePathB; }

QString Controller::getMatrixCPath() { return filePathC; }

int Controller::getPThreadProgress() { return TotalPThreadProgress; }

void Controller::emitRWError(QString errorMessage) {
  emit readWriteError(errorMessage);
}

void Controller::emitPthreadTime(int PThreadTime) {
  TotalPThreadTime = PThreadTime;
  emit notifyComputeCompleted(PThreadTime, TotalQRunnableTime);
}

void Controller::emitQRunnableTime(int QRunnableTime) {
  TotalQRunnableTime = QRunnableTime;
  emit notifyComputeCompleted(QRunnableTime, TotalQRunnableTime);
}

void Controller::emitPThreadProgress(int PThreadProgress) {
  TotalPThreadProgress = PThreadProgress;
  emit notifyProgressCompleted(TotalPThreadProgress, TotalQRunnableProgress);
}

void Controller::emitQRunnableProgress(int QRunnableProgress) {
  TotalQRunnableProgress = QRunnableProgress;
  emit notifyProgressCompleted(TotalPThreadProgress, TotalQRunnableProgress);
}

void Controller::getPaths(QString pathA, QString pathB, QString pathC) {
  filePathA = pathA;
  filePathB = pathB;
  filePathC = pathC;
}

// *************THREADING ***************** //
void *Controller::computeThreads(void *arg) {
  // Start timer
  QElapsedTimer timer;
  timer.start();

  struct PathArgs *computeStruct = (struct PathArgs *)arg;

  // Create 2 read threads
  pthread_t readA, readB;

  struct ReadArgs readStructA, readStructB;

  readStructA.filepath = computeStruct->controller->getMatrixAPath();
  readStructB.filepath = computeStruct->controller->getMatrixBPath();

  pthread_create(&readA, NULL, read, (void *)&readStructA);
  pthread_create(&readB, NULL, read, (void *)&readStructB);

  // Join for both
  pthread_join(readA, NULL);
  pthread_join(readB, NULL);

  // Handling for individual error found during read
  if (readStructA.error) {
    computeStruct->controller->emitRWError(readStructA.errorMessage);
    pthread_exit(0);
  }

  if (readStructB.error) {
    computeStruct->controller->emitRWError(readStructB.errorMessage);
    pthread_exit(0);
  }

  if (readStructA.type != readStructB.type) {
    computeStruct->controller->emitRWError(
        "Data format disagreement between matrices");
    pthread_exit(0);
  }

  MATRIX_TYPE type = readStructA.type;

  // Check for inter-matrices dimension mismatch
  // A's columns  has to be equal to B's rows
  // Total threads = total output elements (A's row times B's column)
  //                  + 2 read + 1 write
  int totalThreads = 3;
  if (type == INT) {
    if (readStructA.intMatrix[0].size() != readStructB.intMatrix.size()) {
      computeStruct->controller->emitRWError("Matrix inner dimension mismatch");
      pthread_exit(0);
    }
    totalThreads +=
        readStructA.intMatrix.size() * readStructB.intMatrix[0].size();
  } else if (type == DOUBLE) {
    if (readStructA.decMatrix[0].size() != readStructB.decMatrix.size()) {
      computeStruct->controller->emitRWError("Matrix inner dimension mismatch");
      pthread_exit(0);
    }
    totalThreads +=
        readStructA.decMatrix.size() * readStructB.decMatrix[0].size();
  }

  // Emit to update progress bar
  int PThreadProgress = 2 / totalThreads;
  computeStruct->controller->emitPThreadProgress(PThreadProgress);

  // Create write struct for multiply and write
  pthread_t writer;
  struct WriteArgs writeStruct;

  writeStruct.filepath = computeStruct->controller->getMatrixCPath().trimmed();
  writeStruct.type = type;
  writeStruct.decMatrixA = readStructA.decMatrix;
  writeStruct.decMatrixB = readStructB.decMatrix;
  writeStruct.intMatrixA = readStructA.intMatrix;
  writeStruct.intMatrixB = readStructB.intMatrix;

  if (type == INT) {
    for (int i = 0; i < writeStruct.intMatrixA.size(); i++) {
      QVector<int> row;
      for (int j = 0; j < writeStruct.intMatrixB[0].size(); j++) {
        row.append(0);
      }
      writeStruct.intMatrixC.append(row);
      writeStruct.locks.append(
          QBitArray(writeStruct.intMatrixB[0].size(), false));
    }
  } else if (type == DOUBLE) {
    for (int i = 0; i < writeStruct.decMatrixA.size(); i++) {
      QVector<double> row;
      for (int j = 0; j < writeStruct.decMatrixB[0].size(); j++) {
        row.append(0);
      }
      writeStruct.decMatrixC.append(row);
      writeStruct.locks.append(
          QBitArray(writeStruct.decMatrixB[0].size(), false));
    }
  }

  // Create M * P threads

  int totalItems = totalThreads - 3;
  pthread_t multiplies[totalItems];
  int count = 0;
  if (type == INT) {
    for (int i = 0; i < writeStruct.intMatrixA.size(); i++) {
      for (int j = 0; j < writeStruct.intMatrixB[0].size(); j++) {
        struct MultArgs multStruct;
        multStruct.write = &writeStruct;
        multStruct.i = i;
        multStruct.j = j;
        multStruct.totalThreads = totalThreads;
        pthread_create(&multiplies[count], NULL, multiply, (void *)&multStruct);
        count++;
      }
    }

    // Join M * P threads
    for (int i = 0; i < totalItems; i++) {
      pthread_join(multiplies[i], NULL);
    }
  } else if (type == DOUBLE) {
    for (int i = 0; i < writeStruct.decMatrixA.size(); i++) {
      for (int j = 0; j < writeStruct.decMatrixB[0].size(); j++) {
        struct MultArgs multStruct;
        multStruct.write = &writeStruct;
        multStruct.paths = computeStruct;
        multStruct.totalThreads = totalItems;
        multStruct.i = i;
        multStruct.j = j;
        pthread_create(&multiplies[count], NULL, multiply, (void *)&multStruct);
        count++;
      }
    }

    // Join M * P threads
    for (int i = 0; i < totalItems; i++) {
      // TODO: Distinguish between QRunnable and PThread
      // Update progress bar incrementally
      int currentProgress = computeStruct->controller->getPThreadProgress();
      int increment = (1 / (totalThreads));
      computeStruct->controller->emitPThreadProgress(currentProgress +
                                                     increment);
      pthread_join(multiplies[i], NULL);
    }
  }

  // Create write thread
  pthread_create(&writer, NULL, write, (void *)&writeStruct);

  // Join write thread
  pthread_join(writer, NULL);

  // Set max progress bar
  computeStruct->controller->emitPThreadProgress(100);

  // Set elapsed time
  int PThreadTime = timer.elapsed();
  computeStruct->controller->emitPthreadTime(PThreadTime);

  pthread_exit(0);
}

void *Controller::read(void *arg) {
  struct ReadArgs *readStruct = (struct ReadArgs *)arg;
  QString path = readStruct->filepath;

  // Open
  QFile datFile(path);
  datFile.open(QIODevice::ReadOnly);

  QString line;
  QStringList dataList;

  // Read until end of file
  while (!datFile.atEnd()) {
    line = datFile.readLine().trimmed();

    // Add the line to private list
    dataList << line;
  }
  QVector<QStringList> test;

  for (int i = 0; i < dataList.size(); i++) {
    QStringList list =
        dataList[i].split(QRegExp("\\s+"), QString::SkipEmptyParts);

    test << list;
  }

  // Handling for empty matrix
  if (test.size() == 0) {
    readStruct->error = true;
    readStruct->errorMessage = "Empty matrix is not acceptable";
    pthread_exit(0);
  }

  // To keep track of data consistency within matrix
  int intCount = 0;
  int doubleCount = 0;
  int totalConversions = 0;

  // Conversion things + Data format checks
  bool okInt = false, okDouble = false;

  // This regex checks if the decimal number has 4 decimal values
  QRegularExpression doubleMatch("^-?[0-9]\\d*(\\.\\d{1,4})$",
                                 QRegularExpression::CaseInsensitiveOption);
  QRegularExpressionMatch match;

  for (int i = 0; i < test.size(); i++) {
    // Temp rows for insertions
    IntegerRow rowi;
    DecimalRow rowd;
    for (int j = 0; j < test[i].size(); j++) {
      rowi.append(test[i][j].toInt(&okInt));

      //^-?[0-9]\d*(\.\d{1,4})$
      match = doubleMatch.match(test[i][j]);
      okDouble = match.hasMatch();

      double toAppend = okDouble ? test[i][j].toDouble() : 0.0;
      rowd.append(toAppend);

      // Increment for each successful conversion
      intCount = okInt ? intCount + 1 : intCount;
      doubleCount = okDouble ? doubleCount + 1 : doubleCount;

      // Increment for each attempted conversions
      totalConversions++;
    }
    // Insert into vectors
    readStruct->decMatrix.append(rowd);
    readStruct->intMatrix.append(rowi);
  }

  // Data format check based on count variables
  if (!((intCount == totalConversions && doubleCount == 0) ||
        (doubleCount == totalConversions && intCount == 0))) {
    readStruct->error = true;
    readStruct->errorMessage = "Data format disagreement within matrix";
    pthread_exit(0);
  }

  // Determine readStruct->type of Matrix
  readStruct->type = intCount == totalConversions ? INT : DOUBLE;

  // Check for multiple-length rows for a single matrix
  // Row length consistency comparisons with first row length
  int currentRowCount = 0;
  int firstRowCount = 0;
  bool consistency = true;

  if (readStruct->type == INT) {
    firstRowCount = readStruct->intMatrix.first().size();
    for (int i = 0; i < readStruct->intMatrix.size(); i++) {
      currentRowCount = readStruct->intMatrix.at(i).size();
      consistency = consistency && (currentRowCount == firstRowCount);
    }
  } else if (readStruct->type == DOUBLE) {
    firstRowCount = readStruct->decMatrix.first().size();
    for (int i = 0; i < readStruct->decMatrix.size(); i++) {
      currentRowCount = readStruct->decMatrix.at(i).size();
      consistency = consistency && (currentRowCount == firstRowCount);
    }
  }

  // Error for the consistency flag
  if (!consistency) {
    readStruct->error = true;
    readStruct->errorMessage = "Multiple-length rows for a single matrix";
  }

  pthread_exit(0);
}

void *Controller::write(void *arg) {
  struct WriteArgs *writeStruct = (struct WriteArgs *)arg;

  QString path = writeStruct->filepath;

  QFile out(path);

  out.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);

  // Open as textstream
  QTextStream outs(&out);
  if (writeStruct->type == DOUBLE) {
    // For decimals
    outs.setRealNumberPrecision(4);
    outs.setRealNumberNotation(QTextStream::FixedNotation);

    for (int i = 0; i < writeStruct->decMatrixC.size(); i++) {
      for (int j = 0; j < writeStruct->decMatrixC[i].size(); j++) {
        outs << writeStruct->decMatrixC[i][j] << " ";
      }
      outs << "\n";
    }
  } else if (writeStruct->type == INT) {
    for (int i = 0; i < writeStruct->intMatrixC.size(); i++) {
      for (int j = 0; j < writeStruct->intMatrixC[i].size(); j++) {
        outs << writeStruct->intMatrixC[i][j] << " ";
      }
      outs << "\n";
    }
  }

  out.close();
  pthread_exit(0);
}

void *Controller::multiply(void *arg) {
  struct MultArgs *multStruct = (struct MultArgs *)arg;

  int total = 0;
  if (multStruct->write->type == INT) {
    for (int i = 0; i < multStruct->write->intMatrixA[0].size(); i++) {
      total += multStruct->write->intMatrixA[multStruct->i][i] *
               multStruct->write->intMatrixB[i][multStruct->j];
    }
    multStruct->write->intMatrixC[multStruct->i][multStruct->j] = total;
  } else if (multStruct->write->type == DOUBLE) {
    for (int i = 0; i < multStruct->write->decMatrixA[0].size(); i++) {
      total += multStruct->write->decMatrixA[multStruct->i][i] *
               multStruct->write->decMatrixB[i][multStruct->j];
    }
    multStruct->write->decMatrixC[multStruct->i][multStruct->j] = total;
  }

  // Set QBitArray to indicate success
  multStruct->write->locks[multStruct->i][multStruct->j] = true;
  pthread_exit(0);
}
