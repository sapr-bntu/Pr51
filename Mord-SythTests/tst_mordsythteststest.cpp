#include <QtCore/QString>
#include <QtTest/QtTest>
#include <fileinfo.h>
#include <folderservice.h>
#include <application.h>
#include <ifieinforepositoryfactory.h>
#include <sqlfileinforepository.h>

class MordSythTestsTest : public QObject
{
    Q_OBJECT
    
public:
    MordSythTestsTest();
    
private Q_SLOTS:
    void testCase1();
    void GetFileInfoTest();
    void GetFileInfoExceptionTest();
};

MordSythTestsTest::MordSythTestsTest()
{
}

void MordSythTestsTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void MordSythTestsTest::GetFileInfoTest()
{
    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();    
    fileInfo fInfo = repository->GetFileInfo("C:/Users/Public/Pictures/Sample Pictures/Desert.jpg");
    QCOMPARE(fInfo.GetMark(),4);
}

void MordSythTestsTest::GetFileInfoExceptionTest()
{
    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();
    fileInfo fInfo = repository->GetFileInfo("wrong path");
    QCOMPARE(fInfo.GetMark(),0);
}

QTEST_APPLESS_MAIN(MordSythTestsTest)

#include "tst_mordsythteststest.moc"
