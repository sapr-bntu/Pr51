#include "fileinfo.h"


fileInfo::fileInfo(QString path)
{
    m_path=path;
}

int fileInfo::GetMark()
{
    return m_mark;
}

QString fileInfo::GetComment()
{
    return m_comment;
}

QString fileInfo::GetPath()
{
    return m_path;
}

void fileInfo::SetMark(int mark)
{
    if (mark>5) throw "argException";
    if (mark<0) throw "argException";
}

void fileInfo::SetComment(QString comment)
{
    if (comment.length()>50)
        throw "argException";
}
