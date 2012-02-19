#ifndef FILESERVICE_H
#define FILESERVICE_H
#include <fileinfo.h>
#include <QImage>

#include <ifieinforepositoryfactory.h>
#include <ifileinforepository.h>

class FileService {

public:
    FileService();   
    fileInfo GetFileInfo(QString path);
    QImage GetImage(QString path);
    void SaveFileInfo(fileInfo fileInfoToSave);
};

#endif // FILESERVICE_H
