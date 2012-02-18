#ifndef APPLICATION_H
#define APPLICATION_H
#include <QString>
#include <../model/fileinfo.h>
#include <../Services/folderservice.h>
#include <../Services/fileservice.h>
#include <QFileInfo>
#include <QDir>

class Application
{

public:
    Application();

private:
    QString currentFile;
    FolderService *folderService;
    FileService fileService;

public:
    QString MoveNext();
    QString MovePrevious();
    fileInfo GetFileInfo();
    void OpenFile(QString filePath);

};

#endif // APPLICATION_H

