#include "mainwindow.h"
#include "controller.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  this->setWindowTitle("Matrix Multiplier");

  // Connect the path send functions
  QObject::connect(this, SIGNAL(sendPaths(QString, QString, QString)),
                   &m_controller, SLOT(getPaths(QString, QString, QString)));

  // Connect the error handlers
  QObject::connect(&m_controller, SIGNAL(readWriteError(QString)), this,
                   SLOT(errorReceived(QString)));

  // Connect the compute notifications
  QObject::connect(&m_controller, SIGNAL(notifyComputeCompleted(int, int)),
                   this, SLOT(computeDone(int, int)));
  QObject::connect(&m_controller, SIGNAL(notifyProgressCompleted(int, int)),
                   this, SLOT(progressDone(int, int)));

  // Connect the final thread
  QObject::connect(&m_controller, SIGNAL(notifyTotalThreads(void)), this,
                   SLOT(allThreadsCompleted(void)));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::allThreadsCompleted() {
  QMessageBox::information(this, "Done", "Done compute");
}

void MainWindow::progressDone(int PThreadProgress, int QRunnableProgress) {
  ui->QRunnableProgressBaR->setValue(QRunnableProgress);
  ui->pThreadProgressBar->setValue(PThreadProgress);
}

void MainWindow::computeDone(int PThreadTime, int QRunnableTime) {
  ui->pThreadValueLabel->setText(QString::number(PThreadTime));
  ui->QRunnableValueLabel->setText(QString::number(QRunnableTime));
}

void MainWindow::errorReceived(QString errorMessage) {

  QMessageBox::critical(this, "Error", errorMessage);
}

void MainWindow::on_MatrixAButton_clicked() {
  // Get path from file selection dialog
  filenameA = QFileDialog::getOpenFileName(this, "/home");

  // Set field text to selected path
  ui->MatrixALineEdit->setText(filenameA);
}

void MainWindow::on_MatrixBButton_clicked() {
  // Get path from file selection dialog
  filenameB = QFileDialog::getOpenFileName(this, "/home");

  // Set field text to selected path
  ui->MatrixBLineEdit->setText(filenameB);
}

void MainWindow::on_MatrixCButton_clicked() {
  // Defaults to home if empty field already
  QString filepath = filenameC == "" ? "/home" : filenameC;

  // Get path from file selection dialog
  QString newFilenameC = QFileDialog::getOpenFileName(this, filepath);

  // Keep the existing text in the LineEdit when a file is not selected
  // Else replace with the new path selected from the file dialog
  filenameC = newFilenameC == "" ? filenameC : newFilenameC;

  // Set field text to selected or existing path
  ui->MatrixCLineEdit->setText(filenameC);
}

void MainWindow::on_MatrixCLineEdit_editingFinished() {
  // Set path to field text if user typed in path
  filenameC = ui->MatrixCLineEdit->text();
}

void MainWindow::on_ComputeButton_clicked() {
  // Reset progresses
  ui->pThreadProgressBar->setValue(0);
  ui->QRunnableProgressBaR->setValue(0);
  ui->pThreadValueLabel->setText(0);
  ui->QRunnableValueLabel->setText(0);

  // Check each file for existance and readability
  if (!(filenameCheck(filenameA) && filenameCheck(filenameB) &&
        filenameCheck(filenameC))) {
    QMessageBox::critical(this, "File I/O Error",
                          "Unopenable, unreadable, or unwritable files");
    return;
  }

  // Send the paths
  emit sendPaths(filenameA, filenameB, filenameC);

  // Make controller compute
  m_controller.compute();
}

void MainWindow::updatePThreadProgressBar(int value) {
  ui->pThreadProgressBar->setValue(value);
}

void MainWindow::updateQRunnableProgressBar(int value) {
  ui->QRunnableProgressBaR->setValue(value);
}

bool MainWindow::filenameCheck(const QString filename) const {
  QFileInfo checkFilename(filename);

  bool ok = false;

  // Check if file exist, is it a file and openable
  if (checkFilename.exists() && checkFilename.isFile()) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
      ok = true;
      file.close();
    }
  }

  return ok;
}
