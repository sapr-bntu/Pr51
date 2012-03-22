#include "ifileinforepository.h"

bool IFileInfoRepository::HasFileInfo(QString path)
{
    throw "must be overrided";
}

fileInfo IFileInfoRepository::GetFileInfo(QString path)
{
    throw "must be overrided";
}

void IFileInfoRepository::SaveFileInfo(fileInfo fileInfo)
{
    throw "must be overrided";
}



