#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "qmessagebox.h"
#include "qdebug.h"


//comment for first commit (Frigik)
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    scaleFactor=1.0;
    ui->setupUi(this);

    //////////////////
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("project_DB.s3db");
    db.open();


    ui->label->setBackgroundRole(QPalette::Base);
    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label->setScaledContents(true);

    ui->scrollArea->setWidget(ui->label);
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    //setCentralWidget(ui->scrollArea);

    setWindowTitle(tr("Image Viewer"));
        resize(500, 400);

    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openfile()));
    connect(ui->actionAbout_Program, SIGNAL(triggered()), this, SLOT(aboutProg()));
    connect(ui->actionHelp, SIGNAL(triggered()), this, SLOT(help()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exitApp()));
    connect(ui->actionZoomIn, SIGNAL(triggered()), this, SLOT(zoomIn()));
    connect(ui->actionZoomOut, SIGNAL(triggered()), this, SLOT(zoomOut()));
    connect(ui->actionNormal_Size, SIGNAL(triggered()), this, SLOT(normalSize()));
    connect(ui->actionFitToWindow, SIGNAL(triggered()), this, SLOT(fitToWindow()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(zoomOut()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(next()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(prev()));


    ui->actionFitToWindow->setEnabled(false);
    ui->actionFitToWindow->setCheckable(true);
    ui->actionFitToWindow->setShortcut(tr("Ctrl+F"));

    ui->actionNormal_Size->setShortcut(tr("Ctrl+S"));
    ui->actionNormal_Size->setEnabled(false);

    ui->actionZoomOut->setShortcut(tr("Ctrl+-"));
    ui->actionZoomOut->setEnabled(false);

    ui->actionZoomIn->setShortcut(tr("Ctrl++"));
    ui->actionZoomIn->setEnabled(false);

    ui->actionExit->setShortcut(tr("Ctrl+Q"));

    ui->actionOpen->setShortcut(tr("Ctrl+O"));

    namefilter.append("*.png");
    namefilter.append("*.jpg");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::next()
{
    QSqlQuery query;

    query.prepare("SELECT ID FROM Images WHERE Name = :name");
    query.bindValue(":name", fnlist[ci]);
    query.exec();
    query.first();;

    if (query.first())
    {
    int ID = query.value(0).toInt();
    query.prepare("UPDATE Images SET Mark=:mark,Tag=:tag WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.bindValue(":mark", ui->spinBox->value());
    query.bindValue(":tag", ui->lineEdit->text());
    query.exec();
    }

    else
    {
    query.prepare("INSERT INTO Images (Name,Mark, Tag) VALUES (:name,:mark,:tag)");
    query.bindValue(":name", fnlist[ci]);
    query.bindValue(":mark", ui->spinBox->value());
    query.bindValue(":tag", ui->lineEdit->text());
    query.exec();
    }

    ci++;
    if (ci>=fnlist.count())
    {
        ci=0;
    }
    openImg(fnlist[ci]);
}

void MainWindow::prev()
{
    QSqlQuery query;

    query.prepare("SELECT ID FROM Images WHERE Name = :name");
    query.bindValue(":name", fnlist[ci]);
    query.exec();
    query.first();

    if (query.first())
    {
    int ID = query.value(0).toInt();
    query.prepare("UPDATE Images SET Mark=:mark,Tag=:tag WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.bindValue(":mark", ui->spinBox->value());
    query.bindValue(":tag", ui->lineEdit->text());
    query.exec();
    }

    else
    {
    query.prepare("INSERT INTO Images (Name,Mark, Tag) VALUES (:name,:mark,:tag)");
    query.bindValue(":name", fnlist[ci]);
    query.bindValue(":mark", ui->spinBox->value());
    query.bindValue(":tag", ui->lineEdit->text());
    query.exec();
    }

    ci--;
    if (ci<0)
    {
        ci=fnlist.count()-1;
    }
    openImg(fnlist[ci]);
}

void MainWindow::openImg(QString fileName)
{
    QImage image(fileName);
    if (image.isNull()) {
        QMessageBox::information(this, tr("Image Viewer"),
                                 tr("Cannot load %1.").arg(fileName));
        return;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    scaleFactor = 1.0;
    sh=image.height();
    sw=image.width();

    ui->actionFitToWindow->setEnabled(true);
    updateActions();

    if (!ui->actionFitToWindow->isChecked())
        ui->label->adjustSize();
    fitToWindow();



    QFileInfo *fi=new QFileInfo(fileName);
    pdr=new QDir(fi->absoluteDir());


    fnlist=pdr->entryList(namefilter);
    for (int i=0;i<fnlist.count();i++)
    {
        fnlist[i]=pdr->absoluteFilePath(fnlist[i]);
    }
    ci=fnlist.indexOf(fileName);

    QSqlQuery query;
    query.prepare("SELECT Mark,Tag FROM Images WHERE Name = :name");
    query.bindValue(":name", fnlist[ci]);
    query.exec();
    query.first();
    int mark = query.value(0).toInt();
    QString tag = query.value(1).toString();    
    ui->lineEdit->setText(tag);
    ui->spinBox->setValue(mark);
}

void MainWindow::openfile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                         tr("Open File"), QDir::currentPath());
         if (!fileName.isEmpty()) {
             openImg(fileName) ;
         }
}

void MainWindow::updateActions()
 {
     ui->actionZoomIn->setEnabled(!ui->actionFitToWindow->isChecked());
     ui->actionZoomOut->setEnabled(!ui->actionFitToWindow->isChecked());
     ui->actionNormal_Size->setEnabled(!ui->actionFitToWindow->isChecked());
 }

void MainWindow::adjustScrollBar(QScrollBar *scrollBar, double factor)
 {
     scrollBar->setValue(int(factor * scrollBar->value()
                             + ((factor - 1) * scrollBar->pageStep()/2)));
 }

void MainWindow::scaleImage(double factor)
 {
     Q_ASSERT(ui->label->pixmap());
     scaleFactor *= factor;
     ui->label->resize(scaleFactor * ui->label->pixmap()->size());

     adjustScrollBar(ui->scrollArea->horizontalScrollBar(), factor);
     adjustScrollBar(ui->scrollArea->verticalScrollBar(), factor);

     ui->actionZoomIn->setEnabled(scaleFactor < 3.0);
     ui->actionZoomOut->setEnabled(scaleFactor > 0.333);
 }

void MainWindow::aboutProg()
 {
     QMessageBox::about(this, tr("About Project51"),
             tr("<p>The <b>Project51</b> </p>"));
 }

void MainWindow::help()
 {
     QMessageBox::about(this, tr("Project51 Help"),
             tr("<p>The <b>Project51 Help</b> </p>"));
 }

void MainWindow::exitApp()
 {
    QApplication::exit();
 }

void MainWindow::fitToWindow()
 {
     bool fitToWindow = ui->actionFitToWindow->isChecked();
     ui->scrollArea->setWidgetResizable(fitToWindow);
     ui->scrollArea->setWidgetResizable(false);
     if (!fitToWindow) {
         normalSize();
     }
     else
     {
         double ssh=sh*scaleFactor;
         double ssw=sh*scaleFactor;
         double sch=ui->scrollArea->height();
         double scw=ui->scrollArea->width();
         double mh=sch/ssh;
         double mw=scw/ssw;
         if (mh<mw)
         {
             scaleImage(mh);
         }
         else
         {
             scaleImage(mw);
         }
     }
     updateActions();
}

void MainWindow::normalSize()
 {
     ui->label->adjustSize();
     scaleFactor = 1.0;
 }

void MainWindow::zoomIn()
 {
 if( ui->actionFitToWindow->isChecked() == true)
    {
       ui->actionFitToWindow->setChecked(false);
       //fitToWindow();
    }
    scaleImage(1.05);

 }

 void MainWindow::zoomOut()
 {
 if( ui->actionFitToWindow->isChecked() == true)
    {
       ui->actionFitToWindow->setChecked(false);
       //fitToWindow();
    }
     scaleImage(0.95);
 }



