#include "fileservice.h"



FileService::FileService()
{
}
fileInfo FileService::GetFileInfo(QString path)
{
    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();
    return repository->GetFileInfo(path);
}
void FileService::SaveFileInfo(fileInfo fileInfoToSave)
{

    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();
    repository->SaveFileInfo(fileInfoToSave);
}
QImage FileService::GetImage(QString path)
{
    QImage image(path);
    if (image.isNull()) {
        throw "ArgumentException";
    }
    return image;
}
