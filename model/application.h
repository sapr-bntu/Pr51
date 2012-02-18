#ifndef APPLICATION_H
#define APPLICATION_H
#include <QString>
#include <fileinfo.h>
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
    QString currentFolder;
    FolderService *folderService;
    FileService fileService;

public:
    QString MoveNext();
    QString MovePrevious();
    fileInfo GetFileInfo();
    void SetCurrentFolder(QString path);
    void OpenFile(QString filePath);

};

#endif // APPLICATION_H
