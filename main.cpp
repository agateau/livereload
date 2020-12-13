#include "Config.h"

#include <QApplication>
#include <QLabel>

#include <QSettings>

static void configureLabel(QLabel* label, Config* config) {
    QFont font;
    font.setPixelSize(config->fontSize);
    label->setFont(font);

    QPalette palette;
    palette.setColor(QPalette::WindowText, config->color);
    label->setPalette(palette);
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Config config("config.ini");

    QLabel label("Hello World");
    configureLabel(&label, &config);
    label.resize(320, 120);
    label.setWindowTitle("Reload (QWidget)");

    QObject::connect(
        &config, &Config::changed, &label, [&label, &config] { configureLabel(&label, &config); });

    label.show();

    return app.exec();
}
