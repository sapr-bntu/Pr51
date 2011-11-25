#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qscrollbar.h"
#include "qdir.h"
#include <QtSql>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    double scaleFactor;
    Ui::MainWindow *ui;
    void updateActions();
    void adjustScrollBar(QScrollBar *scrollBar, double factor);
    void scaleImage(double factor);
    void openImg(QString fileName);
    QStringList fnlist;
    QStringList namefilter;
    QDir *pdr;
    QLineEdit *lineEdit;
    QSqlDatabase db;
    int ci;

private slots:

    void openfile();
    void aboutProg();
    void help();
    void exitApp();
    void zoomIn();
    void zoomOut();
    void fitToWindow();
    void normalSize();
    void next();
    void prev();
    void updateData();

};

#endif // MAINWINDOW_H
