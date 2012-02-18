#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>

class Pr51unittestsTest : public QObject
{
    Q_OBJECT
    
public:
    Pr51unittestsTest();
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

Pr51unittestsTest::Pr51unittestsTest()
{
}

void Pr51unittestsTest::initTestCase()
{
}

void Pr51unittestsTest::cleanupTestCase()
{
}

void Pr51unittestsTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_MAIN(Pr51unittestsTest)

#include "tst_pr51unitteststest.moc"
