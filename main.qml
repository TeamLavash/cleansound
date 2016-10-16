import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 360
    height: 400
    title: qsTr("Clean Sound")

    MainForm {
        mouseArea1.onClicked: {
            console.log(qsTr('Clicked on button 1'))
        }

        mouseArea2.onClicked: {
            console.log(qsTr('Clicked on button 2'))
        }


        anchors.fill: parent
    }
}
