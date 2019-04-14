#include "mainwindow.h"
#include <QApplication>

//#include "radareclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    using namespace amika::radare_client;
//    RadareClient radare;
//    radare.OpenFile("/home/ncyellow/CLionProjects/untitled/cmake-build-debug/untitled");

    MainWindow w;
    w.show();

    return a.exec();
}
