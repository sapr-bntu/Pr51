#ifndef IFIEINFOREPOSITORYFACTORY_H
#define IFIEINFOREPOSITORYFACTORY_H

#include <../interfaces/ifileinforepository.h>

class IFieInfoRepositoryFactory {
public:
    IFieInfoRepositoryFactory();
    static  IFileInfoRepository GetRepository();
};

#endif // IFIEINFOREPOSITORYFACTORY_H
