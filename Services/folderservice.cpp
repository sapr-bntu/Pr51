#include "folderservice.h"
#include <../model/fileinfo.h>


FolderService::FolderService(QString path)
{
    QFileInfo *fi=new QFileInfo(path);
    QDir *pdr=new QDir(fi->absoluteDir());
    folderPath = pdr->dirName();

    QStringList namefilter;
    namefilter.append("*.png");
    namefilter.append("*.jpg");

    fileNameList=pdr->entryList(namefilter);
    for (int i=0;i<fileNameList.count();i++)
       {
          fileNameList[i]=pdr->absoluteFilePath(fileNameList[i]);
       }
    currentIndex=fileNameList.indexOf(path);
}
QString FolderService::GetNextFile(QString fileName)
{    
    throw "notimpl";    
}
QString FolderService::GetPreviousFile(QString fileName)
{
    throw "notimpl";
}
QString FolderService::GetFirstFile()
{
    throw "motimpl";
}

