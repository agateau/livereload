#pragma once

#include <QColor>
#include <QObject>

class Config : public QObject {
    Q_OBJECT
    Q_PROPERTY(QColor color MEMBER color NOTIFY changed)
    Q_PROPERTY(int fontSize MEMBER fontSize NOTIFY changed)
public:
    explicit Config(const QString& path, QObject* parent = nullptr);

    void load();

    QColor color;
    int fontSize;

signals:
    void changed();

private:
    QString mPath;
};
