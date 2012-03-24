#ifndef APPLICATION_H
#define APPLICATION_H
#include <QString>
#include <fileinfo.h>
#include <folderservice.h>
#include <fileservice.h>
#include <QFileInfo>
#include <QDir>
/////
class Application:public QObject
{
Q_OBJECT
public:

    explicit Application(QObject *parent = 0);
private:
    //QString currentFile;
    FolderService* folderService;
    FileService* fileService;

public:

    Q_INVOKABLE void OpenFile(QString filePath);
    Q_INVOKABLE FolderService* GetFolderService();
    Q_INVOKABLE FileService* GetFileService();
    Q_INVOKABLE void MoveNext();
    Q_INVOKABLE void MovePrev();
    Q_INVOKABLE QString GetCurrentFile();
    Q_INVOKABLE bool RunOpenFile();
    Q_INVOKABLE int ImageW();
    Q_INVOKABLE int ImageH();
    Q_INVOKABLE QString GetCurrentPath();
    Q_INVOKABLE void SaveFileInfo(QString path, int mark, QString comment);
    Q_INVOKABLE QString GetMark();
    Q_INVOKABLE QString GetComment();

};

#endif // APPLICATION_H

