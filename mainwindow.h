#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controller.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QMainWindow>
#include <QMessageBox>
#include <QObject>
#include <QString>
#include <QTextStream>
#include <QVector>
#include <pthread.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

signals:
  // Send the filepath names
  void sendPaths(QString pathA, QString pathB, QString pathC);

public slots:
  // Display completion message box
  void allThreadsCompleted();

  // Update progress bar value
  void progressDone(int PThreadProgress, int QRunnableProgress);

  // Update the timer (ms)
  void computeDone(int PThreadTime, int QRunnableTime);

  // Display error message boxes
  void errorReceived(QString errorMessage);

private slots:
  // Buttons click/edit
  void on_MatrixAButton_clicked();

  void on_MatrixBButton_clicked();

  void on_MatrixCButton_clicked();

  void on_MatrixCLineEdit_editingFinished();

  void on_ComputeButton_clicked();

  // Progress Bars updates
  void updatePThreadProgressBar(int value);

  void updateQRunnableProgressBar(int value);

private:
  Ui::MainWindow *ui;

  QString filenameA, filenameB, filenameC;

  // Error handling for paths validation
  bool filenameCheck(const QString filename) const;

  Controller m_controller;
};

#endif // MAINWINDOW_H
