#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>
#include <fileinfo.h>
#include <QDebug>
#include <fileservice.h>
#include <QImage>

class FrigikFileInfoTest : public QObject
{
    Q_OBJECT
    
public:
    FrigikFileInfoTest();
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void GetMarkTest();
    void GetWrongMarkTest();
    void GetException();
    void FileServiceGetImage_Exception();
};

FrigikFileInfoTest::FrigikFileInfoTest()
{
}

void FrigikFileInfoTest::initTestCase()
{
}

void FrigikFileInfoTest::cleanupTestCase()
{
}

void FrigikFileInfoTest::GetMarkTest()
{
    fileInfo *file = new fileInfo("test");
    file->SetMark(4);
    QCOMPARE(file->GetMark(),4);
}
void FrigikFileInfoTest::GetWrongMarkTest()
{//
    fileInfo *file = new fileInfo("test");
    file->SetMark(4);
    bool success;
            if (file->GetMark()>4||file->GetMark()<4)
    {
        success=false;
    }
    else
            {
                success=true;
            }

    QCOMPARE(success,true);
}
void FrigikFileInfoTest::GetException()
{
    fileInfo *file = new fileInfo("test");
    bool isException;
    try{

    file->SetMark(6);
    isException=false;
    }
    catch(char* a)
    {
        isException=true;        
    }
    QCOMPARE(isException,true);
}
void FrigikFileInfoTest::FileServiceGetImage_Exception()
{
    FileService *service = new FileService(QString("test"));
    bool success;
    try
    {
       QImage img = service->GetImage();
        success=false;
    }
    catch(char*)
    {
        success=true;
    }
    QCOMPARE(success,true);
}
QTEST_MAIN(FrigikFileInfoTest)

#include "tst_frigikfileinfotest.moc"
