#ifndef FOLDERSERVICE_H
#define FOLDERSERVICE_H
#include <fileinfo.h>
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
    QStringList m_NameFilter;
public:
    FolderService(QString path);
    QString GetNextFile();
    QString GetPreviousFile();
    QString CurrentFile();
    int CurrentFileIndex();
    QStringList GetNameFilter();
};

#endif // FOLDERSERVICE_H
