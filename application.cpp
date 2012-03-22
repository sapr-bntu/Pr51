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

QString Application:: RunOpenFile()
{

    QString fileName = QFileDialog::getOpenFileName(NULL,
                                                 "Open File", QDir::currentPath());
       if (!fileName.isEmpty()) {
            OpenFile(fileName);
       }

    return fileName;
}

int Application::ImageW()
{
    return this->fileService->GetImage().width();
}

int Application::ImageH()
{
    return this->fileService->GetImage().height();
}
