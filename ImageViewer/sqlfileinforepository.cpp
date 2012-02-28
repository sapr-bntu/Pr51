#include "sqlfileinforepository.h"




SQLFileInfoRepository::SQLFileInfoRepository()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("project_DB.db");
    if (!m_db.open()) {
            QMessageBox::critical(0, qApp->tr("Cannot open database"),
                                  qApp->tr("Unable to establish a database connection.\n"
                                           "This example needs SQLite support. Please read "
                                           "the Qt SQL driver documentation for information how "
                                           "to build it.\n\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

        }
    QSqlQuery query("select name from sqlite_master where type='table' and name='Marks'", m_db);

    if (!query.first())
        {
            QSqlQuery query;
            //query.exec("create table books (id integer PRIMARY KEY,title varchar(20), author varchar(20),genre varchar(20),year int,rating int)");
            query.exec("create table Marks (comment varchar(50), mark int,path varchar(50))");
//            query.exec("insert into Marks values('asd', '2', 'Programing')");
//            query.exec("insert into Marks values('w4eewf', '3', 'Pqwdqwdqing')");
        }
}

fileInfo SQLFileInfoRepository::GetFileInfo(QString path)
{
    fileInfo fInfo =  fileInfo(path);
    m_db.open();
    QSqlQuery query;
    query.prepare("SELECT mark, comment FROM Marks WHERE path = :path");
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
    query.prepare("SELECT mark, comment FROM Marks WHERE path = :path");
    query.bindValue(":path", path);
    query.exec();
    query.first();
    m_db.close();
    if (query.value(0)== 0 && query.value(1).isNull())
        return false;
    else return true;
}

void SQLFileInfoRepository::SaveFileInfo(fileInfo fInfo)
{
    m_db.open();
    QSqlQuery query;
    query.prepare("SELECT path FROM Marks WHERE path = :path");
    query.bindValue(":path", fInfo.GetPath());
    query.exec();
    if (!query.first())
    {
        query.prepare("INSERT INTO Marks values(:tag, :mark, :path)");
        query.bindValue(":mark", fInfo.GetMark());
        query.bindValue(":tag", fInfo.GetComment());
        query.bindValue(":path", fInfo.GetPath());
        query.exec();
    }
else{
    query.prepare("UPDATE Marks SET mark=:mark,comment=:tag WHERE path = :path");
    query.bindValue(":mark", fInfo.GetMark());
    query.bindValue(":tag", fInfo.GetComment());
    query.bindValue(":path", fInfo.GetPath());
    query.exec();
    }
    m_db.close();
}
