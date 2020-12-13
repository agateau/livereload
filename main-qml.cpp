#include "TempConfig.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    TempConfig config("config.ini");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("config", &config);
    engine.load("qrc:/main.qml");

    return app.exec();
}
