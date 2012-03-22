#include "ifieinforepositoryfactory.h"


IFieInfoRepositoryFactory::IFieInfoRepositoryFactory()
{
}

IFileInfoRepository* IFieInfoRepositoryFactory::GetRepository()
{
    return new SQLFileInfoRepository();
}
