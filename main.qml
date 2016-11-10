import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.0

Window {
    id: window
    visible: true
    width: 360
    height: 400
    title: qsTr("Clean Sound")

    property bool fileShow: false
    property int fileChoose: 0
    property double progress: 0.0
    property string file1Name: ""
    property bool file1Chosen: false
    property string file2Name: ""
    property bool file2Chosen: false
    property string version: "UNKNOWN VERSION"

    signal qmlSignal(string buttonClicked)

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            if (window.fileChoose == 1) {
                window.file1Name = fileDialog.fileUrl
                window.file1Chosen = true
            } else if (window.fileChoose == 2) {
                window.file2Name = fileDialog.fileUrl
                window.file2Chosen = true
            }
            window.fileShow = false
        }
        onRejected: {
            console.log("Canceled")
            window.fileShow = false
        }
        visible: window.fileShow
    }

    MainForm {
        mouseArea1.onClicked: {
            window.qmlSignal("1")
            window.fileChoose = 1
            window.fileShow = true
        }

        mouseArea2.onClicked: {
            window.qmlSignal("2")
            window.fileChoose = 2
            window.fileShow = true
        }

        mouseArea3.onClicked: {
            window.qmlSignal("3")
        }

        anchors.fill: parent
    }
}
