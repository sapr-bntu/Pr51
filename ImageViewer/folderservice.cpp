#include "folderservice.h"


#include <QDebug>

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
QString FolderService::GetNextFile()
{    
    if (fileNameList.count()==0)
    {
        throw "There is no files";
    }
    if (currentIndex<fileNameList.count())
    {       
        currentIndex++;
        return fileNameList[currentIndex];
    }
    else
    {
        currentIndex=0;
        return fileNameList[currentIndex];
    }

}
QString FolderService::GetPreviousFile()
{
    if (fileNameList.count()==0)
    {
        throw "There is no files";
    }
    if (currentIndex>0)
    {
        currentIndex--;
        return fileNameList[currentIndex];
    }
    else
    {
        currentIndex=fileNameList.count()-1;
        return fileNameList[currentIndex];
    }
}

QString FolderService::CurrentFile()
{
    return fileNameList[currentIndex];
}

int FolderService::CurrentFileIndex()
{
    return currentIndex;
}

