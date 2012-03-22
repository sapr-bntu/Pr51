#include "folderservice.h"


#include <QDebug>

FolderService::FolderService(QString path)
{

    QFileInfo *fi=new QFileInfo(path);
    QDir *pdr=new QDir(fi->absoluteDir());
    folderPath = pdr->dirName();

    m_NameFilter.append("*.png");
    m_NameFilter.append("*.jpg");

    fileNameList=pdr->entryList(m_NameFilter);

    for (int i=0;i<fileNameList.count();i++)
       {
          fileNameList[i]=pdr->absoluteFilePath(fileNameList[i]);         
       }   
    currentIndex=fileNameList.indexOf(path);
}

QStringList FolderService::GetNameFilter()
{
    return m_NameFilter;
}

QString FolderService::GetNextFile()
{    

    if (fileNameList.count()==0)
    {
        throw "There is no files";
    }
    if (currentIndex<fileNameList.count()-1)
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

