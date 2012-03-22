#ifndef IFIEINFOREPOSITORYFACTORY_H
#define IFIEINFOREPOSITORYFACTORY_H

#include <ifileinforepository.h>
#include <sqlfileinforepository.h>
#include <QObject>

class IFieInfoRepositoryFactory
{

public:
    IFieInfoRepositoryFactory();
    static  IFileInfoRepository* GetRepository();
};

#endif // IFIEINFOREPOSITORYFACTORY_H
