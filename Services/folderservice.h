#ifndef FOLDERSERVICE_H
#define FOLDERSERVICE_H
#include <../model/fileinfo.h>

class FolderService
{
public:
    FolderService();
    QString GetNextFile(QString fileName);
    QString GetPreviousFile(QString fileName);
    QString GetFirstFile();
};

#endif // FOLDERSERVICE_H
