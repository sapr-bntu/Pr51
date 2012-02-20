#include "fileservice.h"
#include "QDebug.h"


FileService::FileService(QString path)
{
    m_Path=path;
}
fileInfo FileService::GetFileInfo()
{
    qDebug()<<"FileService::GetFileInfo";
    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();
    return repository->GetFileInfo(m_Path);
}
void FileService::SaveFileInfo(fileInfo fileInfoToSave)
{
    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();
    repository->SaveFileInfo(fileInfoToSave);
}
QImage FileService::GetImage()
{
    QImage image(m_Path);
    if (image.isNull()) {
        throw "ArgumentException";
    }
    return image;
}
QString FileService::GetCurrentPath()
{
    return m_Path;
}

bool FileService::HasInfo()
{
    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();
    return repository->HasFileInfo(m_Path);
}
