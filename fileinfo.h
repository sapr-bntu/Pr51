#ifndef FILEINFO_H
#define FILEINFO_H
#include <QString>
#include <QObject>

class fileInfo
{

public:
    fileInfo(QString path);

private:
    int m_mark;
    QString m_comment;
    QString m_path;
public:
    int GetMark();
    QString GetComment();
    QString GetPath();
    void SetMark(int mark);
    void SetComment(QString comment);

};

#endif // FILEINFO_H
