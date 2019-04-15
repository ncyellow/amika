#include <QtTest>
#include "radareclient.h"

namespace arc = amika::radare_client;

class TestRadarClient : public QObject
{
    Q_OBJECT

public:
    TestRadarClient();
    ~TestRadarClient();

private slots:
    void test_openFile();

};

TestRadarClient::TestRadarClient()
{

}

TestRadarClient::~TestRadarClient()
{

}

void TestRadarClient::test_openFile()
{
    {
        arc::RadareClient radare;
        QCOMPARE(radare.OpenFile("/home/ncyellow/CLionProjects/untitled/cmake-build-debug/untitled"), true);
    }

    {
        arc::RadareClient radare;
        QCOMPARE(radare.OpenFile("/home/ncyellow/CLionProjects/untitled/cmake-build-debug/untitled1"), false);
    }
}

QTEST_APPLESS_MAIN(TestRadarClient)

#include "tst_testradarclient.moc"
