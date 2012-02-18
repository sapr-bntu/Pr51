#ifndef FOLDERSERVICE_H
#define FOLDERSERVICE_H
#include <../model/fileinfo.h>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFileInfo>

class FolderService
{
private:
    QString folderPath;
    QStringList fileNameList;
    int currentIndex;
public:
    FolderService(QString path);
    QString GetNextFile(QString fileName);
    QString GetPreviousFile(QString fileName);
    QString GetFirstFile();
};

#endif // FOLDERSERVICE_H
