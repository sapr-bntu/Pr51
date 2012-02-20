#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>
#include <fileinfo.h>
#include <folderservice.h>
#include <application.h>
#include <ifieinforepositoryfactory.h>


class Qwe37TestsTest : public QObject
{
    Q_OBJECT
    
public:
    Qwe37TestsTest();
    
private Q_SLOTS:

    void fileInfoConstructorTest();
    void fileInfoSetCommentTest();
    void SetCommentExceptionTest();
    void FolderServiceConstructorTets();
    void ApplicationOpenFileTest();
    void ApplicationConstructor1();
    void ApplicationConstructor2();
    void FileFilter();
    void FileFilterCount();
    void FactoryTest();
};

Qwe37TestsTest::Qwe37TestsTest()
{
}

void Qwe37TestsTest::FactoryTest()
{
    if (IFieInfoRepositoryFactory::GetRepository()==NULL)
        QCOMPARE(true,false);

}

void Qwe37TestsTest::FileFilterCount()
{
    FolderService fs=FolderService("qew");
    QCOMPARE(fs.GetNameFilter().count(),2);
}

void Qwe37TestsTest::FileFilter()
{
    FolderService fs=FolderService("qew");
    QString f= fs.GetNameFilter().at(0);
    QCOMPARE(f,QString("*.png"));
}

void Qwe37TestsTest::FolderServiceConstructorTets()
{
    FolderService* fs=new FolderService("qwse");
    QCOMPARE(fs->CurrentFileIndex(),-1);
}

void Qwe37TestsTest::ApplicationOpenFileTest()
{
    Application* app=new Application();
    app->OpenFile("qwe");
}

void Qwe37TestsTest::ApplicationConstructor1()
{
    Application* app=new Application();
    FileService* fs= app->GetFileService();
    if (fs!=NULL)
        QCOMPARE(true,false);

}

void Qwe37TestsTest::ApplicationConstructor2()
{
    Application* app=new Application();
    FolderService* fs=app->GetFolderService();
    if (fs!=NULL)
        QCOMPARE(true,false);

}

void Qwe37TestsTest::SetCommentExceptionTest()
{
    fileInfo *fi = new fileInfo("qwe");
    bool ok=true;
    try
    {
        fi->SetComment("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
    }
    catch(char* str)
    {
        ok=false;
    }
    QCOMPARE(ok,false);
}

void Qwe37TestsTest::fileInfoConstructorTest()
{
    fileInfo *fi = new fileInfo("qwe");
    QCOMPARE(fi->GetPath(),QString("qwe"));
}

void Qwe37TestsTest::fileInfoSetCommentTest()
{
    fileInfo *fi = new fileInfo("qwe");
    fi->SetComment("comment");
    QCOMPARE(fi->GetComment(),QString("comment"));
}

QTEST_MAIN(Qwe37TestsTest)

#include "tst_qwe37teststest.moc"
