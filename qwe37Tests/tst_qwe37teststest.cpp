#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>
#include <fileinfo.h>
class Qwe37TestsTest : public QObject
{
    Q_OBJECT
    
public:
    Qwe37TestsTest();
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void fileInfoConstructorTest();
    void fileInfoSetCommentTest();
};

Qwe37TestsTest::Qwe37TestsTest()
{
}

void Qwe37TestsTest::initTestCase()
{
}

void Qwe37TestsTest::cleanupTestCase()
{
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
