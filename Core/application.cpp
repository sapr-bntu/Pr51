#include "application.h"

Application::Application()
{
    //fileService=new FileService();
}

fileInfo Application::GetFileInfo()
{
    return fileService.GetFileInfo(currentFile);
}

QString Application::MoveNext()
{
    return folderService->GetNextFile();
}
QString Application::MovePrevious()
{
    return folderService->GetPreviousFile();
}

void Application::OpenFile(QString filePath)
{
    currentFile=filePath;
    folderService = new FolderService(filePath);
}
