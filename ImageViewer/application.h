#ifndef APPLICATION_H
#define APPLICATION_H
#include <QString>
#include <fileinfo.h>
#include <folderservice.h>
#include <fileservice.h>
#include <QFileInfo>
#include <QDir>
/////
class Application
{

public:
    Application();

private:
    //QString currentFile;
    FolderService *folderService;
    FileService* fileService;

public:
    void OpenFile(QString filePath);
    FolderService* GetFolderService();
    FileService* GetFileService();
    void MoveNext();
    void MovePrev();
};

#endif // APPLICATION_H

