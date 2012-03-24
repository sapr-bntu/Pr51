#include "application.h"
#include "qfiledialog.h"


Application::Application(QObject *parent):
     QObject(parent)
{
    folderService=NULL;
    fileService=NULL;
}

FileService* Application::GetFileService()
{
    return fileService;
}

FolderService* Application::GetFolderService()
{
    return folderService;
}

void Application::MoveNext()
{
    fileService=new FileService(folderService->GetNextFile());

}
void Application::MovePrev()
{
    fileService=new FileService(folderService->GetPreviousFile());
}

void Application::OpenFile(QString filePath)
{
    //currentFile=filePath;
    fileService=new FileService(filePath);
    folderService =new FolderService(filePath);
}

QString Application:: GetCurrentFile()
{
    QString rezult=QString("file:///");
    rezult.append(fileService->GetCurrentPath());
    return rezult;
}

bool Application:: RunOpenFile()
{

    QString fileName = QFileDialog::getOpenFileName(NULL,
                                                 "Open File", QDir::currentPath());
       if (!fileName.isEmpty()) {
            OpenFile(fileName);
            return true;
       }
       else
       {
           return false;
       }


}

int Application::ImageW()
{
    return this->fileService->GetImage().width();
}

int Application::ImageH()
{
    return this->fileService->GetImage().height();
}
QString Application::GetCurrentPath()
{
return fileService->GetCurrentPath();
}
void Application::SaveFileInfo(QString path, int mark, QString comment)
{
    fileInfo fi = fileInfo(path);
    fi.SetComment(comment);
    fi.SetMark(mark);
    fileService->SaveFileInfo(fi);
}
QString Application::GetMark()
{
  fileInfo fi = fileService->GetFileInfo();
  int mark =fi.GetMark();
  QString result ;
  result.append(QString("%1").arg(mark));
  qDebug()<< result;
  return result;
}
QString Application::GetComment()
{
    fileInfo fi = fileService->GetFileInfo();
    return fi.GetComment();
}
