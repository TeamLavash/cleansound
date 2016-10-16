import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

Window {
    id: window
    visible: true
    width: 360
    height: 400
    title: qsTr("Clean Sound")

    signal qmlSignal(string buttonClicked)

    MainForm {
        mouseArea1.onClicked: {
            window.qmlSignal("1")
        }

        mouseArea2.onClicked: {
            window.qmlSignal("2")
        }

        mouseArea3.onClicked: {
            window.qmlSignal("3")
        }

        anchors.fill: parent
    }
}
