#ifndef SQLFILEINFOREPOSITORY_H
#define SQLFILEINFOREPOSITORY_H

#include <fileinfo.h>
#include <ifileinforepository.h>
#include <QtSql>

class SQLFileInfoRepository:public IFileInfoRepository
{
private:
    QSqlDatabase m_db;
public:
    SQLFileInfoRepository();

    virtual fileInfo GetFileInfo(QString path);
    virtual bool HasFileInfo(QString path);
    virtual void SaveFileInfo(fileInfo fInfo);
};

#endif // SQLFILEINFOREPOSITORY_H
