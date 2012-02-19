#ifndef SQLFILEINFOREPOSITORY_H
#define SQLFILEINFOREPOSITORY_H

#include <fileinfo.h>
#include <ifileinforepository.h>

class SQLFileInfoRepository:public IFileInfoRepository
{
public:
    SQLFileInfoRepository();

    virtual fileInfo GetFileInfo(QString path);
    virtual bool HasFileInfo(QString path);
    virtual void SaveFileInfo(fileInfo fileInfo);
};

#endif // SQLFILEINFOREPOSITORY_H
