#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QBitArray>
#include <QElapsedTimer>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QList>
#include <QMessageBox>
#include <QObject>
#include <QRegExp>
#include <QRegularExpression>
#include <QRunnable>
#include <QString>
#include <QTextStream>
#include <QThreadPool>
#include <QVector>
#include <pthread.h>

typedef QVector<QList<QString>> StringMatrix;
typedef QVector<QVector<int>> IntegerMatrix;
typedef QVector<QVector<double>> DecimalMatrix;
typedef QVector<int> IntegerRow;
typedef QVector<double> DecimalRow;

enum MATRIX_TYPE { NONE, INT, DOUBLE };

class Controller : public QObject {
  Q_OBJECT
public:
  explicit Controller(QObject *parent = nullptr);
  ~Controller();
  // Handle threads
  void compute();
  void computeThread();

  QString getMatrixAPath();
  QString getMatrixBPath();
  QString getMatrixCPath();
  int getPThreadProgress();

  // Help emit signals
  void emitRWError(QString errorMessage);
  void emitPthreadTime(int PThreadTime);
  void emitQRunnableTime(int QRunnableTime);
  void emitPThreadProgress(int PThreadProgress);
  void emitQRunnableProgress(int QRunnableProgress);
signals:
  void notifyTotalThreads();
  void notifyPThreadCompleted();
  void notifyQRunnableCompleted();
  // Most important
  void notifyComputeCompleted(int PThreadTime, int QRunnableTime);
  void notifyProgressCompleted(int PThreadProgress, int QRunnableProgress);
  void readWriteError(QString errorMessage);

public slots:
  void getPaths(QString pathA, QString pathB, QString pathC);

private:
  // Parsing + error handling
  static void *computeThreads(void *arg);
  static void *read(void *arg);
  static void *write(void *arg);
  static void *multiply(void *arg);

  // Variables
  QString filePathA, filePathB, filePathC;
  int TotalPThreadTime = 0;
  int TotalQRunnableTime = 0;
  int TotalQRunnableProgress = 0;
  int TotalPThreadProgress = 0;
  MATRIX_TYPE type = NONE;
};

struct PathArgs {
  Controller *controller;

  // Deallocate ???
  ~PathArgs() {
    controller = nullptr;
    delete controller;
  }
};

struct ReadArgs {
  QString filepath;
  MATRIX_TYPE type = NONE;
  IntegerMatrix intMatrix;
  DecimalMatrix decMatrix;
  bool error = false;
  QString errorMessage = "";
};

struct WriteArgs {
  QString filepath;
  MATRIX_TYPE type = NONE;
  IntegerMatrix intMatrixA;
  DecimalMatrix decMatrixA;
  IntegerMatrix intMatrixB;
  DecimalMatrix decMatrixB;
  IntegerMatrix intMatrixC;
  DecimalMatrix decMatrixC;
  bool error = false;
  QString errorMessage = "";
  QList<QBitArray> locks;
};

struct MultArgs {
  WriteArgs *write;
  PathArgs *paths;
  int i;
  int j;
  int totalThreads;
};

#endif // CONTROLLER_H
