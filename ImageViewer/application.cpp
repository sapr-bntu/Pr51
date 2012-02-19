#include "application.h"

Application::Application()
{
    fileService=NULL;
    folderService=NULL;
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
    folderService = new FolderService(filePath);
}
