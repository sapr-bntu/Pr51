#include "application.h"
#include <QString>
#include <../Services/folderservice.h>


Application::Application()
{
    fileService=new FileService();
    folderService = new FolderService();
    currentFile = folderService.GetFirstFile();
}

QString Application::GetFileInfo()
{

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
