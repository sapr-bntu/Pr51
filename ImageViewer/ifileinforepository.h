#ifndef IFILEINFOREPOSITORY_H
#define IFILEINFOREPOSITORY_H

#include <fileinfo.h>
class IFileInfoRepository
{
public:
    virtual bool HasFileInfo(QString path);
    virtual fileInfo GetFileInfo(QString path);
    virtual void SaveFileInfo(fileInfo fileInfo);
};

#endif // IFILEINFOREPOSITORY_H
