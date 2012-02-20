#include "sqlfileinforepository.h"




SQLFileInfoRepository::SQLFileInfoRepository()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("project_DB.s3db");
}

fileInfo SQLFileInfoRepository::GetFileInfo(QString path)
{
    fileInfo fInfo =  fileInfo(path);
    m_db.open();
    QSqlQuery query;
    query.prepare("SELECT Mark, Tag FROM Images WHERE Path = :path");
    query.bindValue(":path", path);
    query.exec();
    query.first();
    fInfo.SetMark(query.value(0).toInt());
    fInfo.SetComment(query.value(1).toString());
    m_db.close();
    return fInfo;
}

bool SQLFileInfoRepository::HasFileInfo(QString path)
{
    m_db.open();
    QSqlQuery query;
    query.prepare("SELECT Mark, Tag FROM Images WHERE Path = :path");
    query.bindValue(":path", path);
    query.exec();
    query.first();
    m_db.close();
    if (query.value(0)== NULL && query.value(1)==NULL)
        return false;
    else return true;
}

void SQLFileInfoRepository::SaveFileInfo(fileInfo fInfo)
{
    m_db.open();
    QSqlQuery query;
    query.prepare("UPDATE Images SET Mark=:mark,Tag=:tag WHERE Path = :path");
    query.bindValue(":mark", fInfo.GetMark());
    query.bindValue(":tag", fInfo.GetComment());
    query.bindValue(":path", fInfo.GetPath());
    query.exec();
    m_db.close();
}
