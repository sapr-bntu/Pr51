#ifndef SQLFILEINFOREPOSITORY_H
#define SQLFILEINFOREPOSITORY_H

#include <../model/fileinfo.h>
#include <../interfaces/ifileinforepository.h>

class SQLFileInfoRepository:public IFileInfoRepository
{
public:
    SQLFileInfoRepository();

    fileInfo GetFileInfo(QString path);
    bool HasFileInfo(QString path);
    void SaveFileInfo(fileInfo fileInfo);
};

#endif // SQLFILEINFOREPOSITORY_H
