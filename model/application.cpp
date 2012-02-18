#include "application.h"

Application::Application()
{
    fileService=new FileService();
}

QString Application::GetFileInfo()
{
return fileService.GetFileInfo(currentFile);
}
void Application::SetCurrentFolder(QString path)
{
    currentFolder=path;
}
QString Application::MoveNext()
{
    return folderService.GetNextFile();
}
QString Application::MovePrevious()
{
    return folderService.GetPreviousFile();
}

void Application::OpenFile(QString filePath)
{
    QFileInfo *fi=new QFileInfo(fileName);
    QDir pdr=new QDir(fi->absoluteDir());
    currentFolder = pdr.dirName();

    folderService = new FolderService(filepath);

}
