#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qscrollbar.h"
#include "qdir.h"
#include <../ImageViewer/application.h>


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
    Application app;
    int ci;
    int sh;
    int sw;

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
    //void updateData();

};

#endif // MAINWINDOW_H
