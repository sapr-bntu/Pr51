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
    void HasFileInfoTest();
    void HasFileInfoExceptionTest();
    void SaveFileInfoInsertTest();
    void SaveFileInfoUpdateTest();
    void SetMarkTest();
    void SetMarkExceptionTest();
    void FolderServiceCurrentFile();
    void CurrentFileIndex();
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
    fileInfo fInfo = fileInfo("C:/Users/Public/Pictures/Sample Pictures/Desert.jpg");
    fInfo.SetComment("asdf");
    fInfo.SetMark(4);
    repository->SaveFileInfo(fInfo);
    fInfo = repository->GetFileInfo("C:/Users/Public/Pictures/Sample Pictures/Desert.jpg");
    QCOMPARE(fInfo.GetMark(),4);
}

void MordSythTestsTest::GetFileInfoExceptionTest()
{
    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();
    fileInfo fInfo = repository->GetFileInfo("wrong path");
    QCOMPARE(fInfo.GetMark(),0);
}

void MordSythTestsTest::HasFileInfoTest()
{
    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();
    QCOMPARE(repository->HasFileInfo("C:/Users/Public/Pictures/Sample Pictures/Desert.jpg"),true);
}

void MordSythTestsTest::HasFileInfoExceptionTest()
{
    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();
    QCOMPARE(repository->HasFileInfo("wrong path"),false);
}

void MordSythTestsTest::SaveFileInfoInsertTest()
{
    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();
    fileInfo fInfo = fileInfo("C:/Users/Public/Pictures/Sample Pictures/Chrysanthemum.jpg");
    fInfo.SetComment("asdf");
    fInfo.SetMark(5);
    repository->SaveFileInfo(fInfo);
    fInfo = repository->GetFileInfo("C:/Users/Public/Pictures/Sample Pictures/Chrysanthemum.jpg");
    QCOMPARE(fInfo.GetMark(),5);
}

void MordSythTestsTest::SaveFileInfoUpdateTest()
{
    IFileInfoRepository *repository = IFieInfoRepositoryFactory::GetRepository();
    fileInfo fInfo = fileInfo("C:/Users/Public/Pictures/Sample Pictures/Chrysanthemum.jpg");
    fInfo.SetComment("asdf");
    fInfo.SetMark(3);
    repository->SaveFileInfo(fInfo);
    fInfo = repository->GetFileInfo("C:/Users/Public/Pictures/Sample Pictures/Chrysanthemum.jpg");
    QCOMPARE(fInfo.GetMark(),3);
}

void MordSythTestsTest::SetMarkTest()
{
    fileInfo *fi = new fileInfo("new file");
    fi->SetMark(4);
    QCOMPARE(fi->GetMark(),4);
}

void MordSythTestsTest::SetMarkExceptionTest()
{
    fileInfo *fi = new fileInfo("new file");
    bool exc = false;
    try
    {
        fi->SetMark(-1);
    }
    catch (char* str)
    {
        exc = true;
    }
    QCOMPARE(exc,true);
}

void MordSythTestsTest::FolderServiceCurrentFile()
{
    FolderService *fs=new FolderService("C:/Users/Public/Pictures/Sample Pictures/Chrysanthemum.jpg");
    QString current;
    current = fs->CurrentFile();
    QCOMPARE(current,QString("C:/Users/Public/Pictures/Sample Pictures/Chrysanthemum.jpg"));
}

void MordSythTestsTest::CurrentFileIndex()
{
    FolderService *fs=new FolderService("C:/Users/Public/Pictures/Sample Pictures/Chrysanthemum.jpg");
    int current;
    current = fs->CurrentFileIndex();
    QCOMPARE(current,0);
}

QTEST_APPLESS_MAIN(MordSythTestsTest)

#include "tst_mordsythteststest.moc"
