#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>
#include <fileinfo.h>
#include <QDebug>

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
{
    fileInfo *file = new fileInfo("test");
    file->SetMark(4);
    QCOMPARE(file->GetMark(),3);
}
void FrigikFileInfoTest::GetException()
{
    fileInfo *file = new fileInfo("test");
    bool isException;
    try{
        qDebug()<<"false";
    file->SetMark(6);
    isException=false;
    }
    catch(char* a)
    {
        isException=true;
         qDebug()<<"true";
    }
    QCOMPARE(isException,true);
}

QTEST_MAIN(FrigikFileInfoTest)

#include "tst_frigikfileinfotest.moc"
