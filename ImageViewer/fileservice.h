#ifndef FILESERVICE_H
#define FILESERVICE_H
#include <fileinfo.h>
#include <QImage>

#include <ifieinforepositoryfactory.h>
#include <ifileinforepository.h>

class FileService {
private:
    QString m_Path;

public:
    FileService(QString path);
    fileInfo GetFileInfo();
    QImage GetImage();
    void SaveFileInfo(fileInfo fileInfoToSave);
    QString GetCurrentPath();
    bool HasInfo();
};

#endif // FILESERVICE_H
