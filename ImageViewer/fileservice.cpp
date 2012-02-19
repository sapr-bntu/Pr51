#include "fileservice.h"



FileService::FileService(QString path)
{
    m_Path=path;
}
fileInfo FileService::GetFileInfo()
{
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
