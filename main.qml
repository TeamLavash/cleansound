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
    property string localPath1: ""
    property bool file1Chosen: false
    property string localPath2: ""
    property bool file2Chosen: false
    property string version: "UNKNOWN VERSION"
    property bool finished: false
    property string sourceType: "Local"
    property string youtubeFile1: ""
    property string youtubeFile2: ""

    signal qmlSignal(string buttonClicked)

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            if (window.fileChoose == 1) {
                window.localPath1 = fileDialog.fileUrl
                window.file1Chosen = true
            } else if (window.fileChoose == 2) {
                window.localPath2 = fileDialog.fileUrl
                window.file2Chosen = true
            }
            window.qmlSignal("ch" + window.fileChoose)
            window.fileShow = false
        }
        onRejected: {
            console.log("Canceled")
            window.fileShow = false
        }
        visible: window.fileShow
    }

    MainForm {
        youtubePath1.onDisplayTextChanged: {
            window.youtubeFile1 = youtubePath1.text
        }
        youtubePath2.onDisplayTextChanged: {
            window.youtubeFile2 = youtubePath2.text
        }
        comboBox1.onDisplayTextChanged: {
            window.sourceType = comboBox1.currentText
        }

        mouseAreaPlay1.onClicked: {
            window.qmlSignal("pl1")
        }

        mouseAreaPlay2.onClicked: {
            window.qmlSignal("pl2")
        }

        mouseArea1.onClicked: {
            //window.qmlSignal("req1")
            window.fileChoose = 1
            window.fileShow = true
        }

        mouseArea2.onClicked: {
            //window.qmlSignal("req2")
            window.fileChoose = 2
            window.fileShow = true
        }

        mouseArea3.onClicked: {
            window.qmlSignal("start")
        }

        anchors.fill: parent
    }
}
