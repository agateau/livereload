import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Window {
    width: 320
    height: 120
    visible: true
    title: "Reload (QML)"

    Label {
        text: "Hello World"
        anchors.centerIn: parent
        color: config.color
        font.pixelSize: config.fontSize
    }
}
