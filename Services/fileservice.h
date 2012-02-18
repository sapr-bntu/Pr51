#ifndef FILESERVICE_H
#define FILESERVICE_H
#include <../model/fileinfo.h>
#include <QImage>

class FileService {
public:
    FileService();   
    fileInfo GetFileInfo(QString path);
    QImage GetImage(QString path);
    void SaveFileInfo(fileInfo file);
};

#endif // FILESERVICE_H
