#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <radare/iradare.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    using namespace amika::radare;
    Radare radare;
    radare.OpenFile("/home/ncyellow/CLionProjects/untitled/cmake-build-debug/untitled");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
