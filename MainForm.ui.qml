import QtQuick 2.5
import QtQuick.Controls 2.0
import Qt.labs.calendar 1.0

Rectangle {
    id: rectangle1

    width: 360
    height: 400
    property alias youtubePath2: youtubePath2
    property alias youtubePath1: youtubePath1
    property alias comboBox1: comboBox1
    property alias mouseAreaPlay2: mouseAreaPlay2
    property alias mouseAreaPlay1: mouseAreaPlay1
    property alias mouseArea1: mouseArea1
    property alias mouseArea3: mouseArea3
    property alias mouseArea2: mouseArea2
    gradient: Gradient {
        GradientStop {
            id: gradientStop1
            position: 0
            color: "#ffffff"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
    }
    border.width: 1

    Text {
        id: textAppName
        x: 36
        y: 8
        width: 283
        height: 87
        text: qsTr("CleanSound")
        z: 1
        font.bold: true
        style: Text.Outline
        styleColor: "#ffffff"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: "Times New Roman"
        font.pixelSize: 46
    }

    Rectangle {
        id: buttonStart
        x: 124
        y: 320
        width: 112
        height: 38
        radius: 5
        opacity: mouseArea3.containsMouse ? 0.95 : 0.8
        scale: mouseArea3.containsMouse ? 1.02 : 1.0
        z: 1
        visible: true
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#0066ff"
            }

            GradientStop {
                position: 1
                color: "#001433"
            }
        }
        Text {
            id: textStart
            x: 8
            y: 8
            width: 96
            height: 22
            text: qsTr("START")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 18
            font.bold: true
        }

        MouseArea {
            id: mouseArea3
            x: 0
            y: 0
            width: 112
            height: 38
            property bool ongoing: false
            hoverEnabled: true
        }
        border.width: 1
    }

    Image {
        id: image1
        anchors.fill: parent
        z: 0
        source: "res/soundwaves.jpg"

        Text {
            id: text1
            x: 225
            y: 374
            width: 128
            height: 18
            color: "#3c3535"
            text: window.version
            verticalAlignment: Text.AlignBottom
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 10
        }

        ComboBox1 {
            id: comboBox1
            x: 125
            y: 180
        }

        Label {
            id: label5
            x: 132
            y: 364
            width: 87
            height: 20
            color: "#ff0000"
            text: qsTr("COMPLETED!")
            visible: window.finished
            topPadding: -1
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 11
        }
    }

    LocalContainer {
        id: localContainer
        x: 18
        y: 205
        width: 319
        height: 109
        visible: comboBox1.currentText == "Local"

        Rectangle {
            id: buttonVideo1
            x: 19
            y: 15
            width: 112
            height: 38
            radius: 5
            opacity: mouseArea1.containsMouse ? 0.95 : 0.8
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#0066ff"
                }

                GradientStop {
                    position: 1
                    color: "#001433"
                }
            }
            border.color: "#000000"
            scale: mouseArea1.containsMouse ? 1.02 : 1.0
            smooth: true
            Text {
                id: textButton1
                x: 8
                y: 8
                width: 96
                height: 22
                text: qsTr("ADD 1")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 18
                font.bold: true
            }

            MouseArea {
                id: mouseArea1
                x: 0
                y: 0
                width: 112
                height: 38
                hoverEnabled: true
                visible: true
            }
            z: 1
            visible: true
        }

        Rectangle {
            id: buttonVideo2
            x: 182
            y: 15
            width: 112
            height: 38
            radius: 5
            opacity: mouseArea2.containsMouse ? 0.95 : 0.8
            scale: mouseArea2.containsMouse ? 1.02 : 1
            z: 1
            visible: true
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#0066ff"
                }

                GradientStop {
                    position: 1
                    color: "#001433"
                }


                GradientStop {
                    position: 1
                    color: "#001433"
                }
            }
            Text {
                id: textButton2
                x: 8
                y: 8
                width: 96
                height: 22
                text: qsTr("ADD 2")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 18
                font.bold: true
            }

            MouseArea {
                id: mouseArea2
                x: 0
                y: 0
                width: 112
                height: 38
                hoverEnabled: true
                visible: true
            }
            border.width: 1
        }

        Label {
            id: label1
            x: 19
            y: 59
            width: 111
            height: 38
            color: "#ff0000"
            text: window.localPath1
            wrapMode: Text.WrapAnywhere
            visible: window.file1Chosen
        }

        Label {
            id: label2
            x: 180
            y: 59
            width: 111
            height: 38
            color: "#ff0000"
            text: window.localPath2
            font.pointSize: 9
            topPadding: 1
            wrapMode: Text.WrapAnywhere
            visible: window.file2Chosen
        }
    }

    YoutubeContainer {
        id: youtubeContainer
        x: 18
        y: 206
        visible: comboBox1.currentText == "YouTube"

        TextField {
            id: youtubePath1
            x: 113
            y: 14
            color: "#cdd2ff"
            text: qsTr("Text Field")
            font.bold: true
            font.pointSize: 12
            z: 1
        }

        TextField {
            id: youtubePath2
            x: 113
            y: 60
            color: "#cdd2ff"
            text: qsTr("Text Field")
            font.bold: true
            font.pointSize: 12
            z: 1
        }

        Label {
            id: label3
            x: 15
            y: 14
            width: 86
            height: 40
            color: "#71737f"
            text: qsTr("File 1")
            z: 1
            font.pointSize: 24
            textFormat: Text.RichText
        }

        Label {
            id: label4
            x: 15
            y: 60
            width: 86
            height: 39
            color: "#71737f"
            text: qsTr("File 2")
            z: 1
            font.pointSize: 24
        }

        Rectangle {
            id: rectangle2
            x: 15
            y: 14
            width: 86
            height: 40
            color: "#001433"
            radius: 5
            opacity: 0.8
        }

        Rectangle {
            id: rectangle3
            x: 15
            y: 60
            width: 86
            height: 39
            color: "#001433"
            radius: 5
            opacity: 0.8
        }

        Rectangle {
            id: rectangle4
            x: 113
            y: 14
            width: 200
            height: 40
            color: "#001433"
            radius: 5
            opacity: 0.8
        }

        Rectangle {
            id: rectangle5
            x: 113
            y: 60
            width: 200
            height: 40
            color: "#001433"
            radius: 5
            opacity: 0.7
        }
    }

    Connections {
        target: mouseArea3
        onClicked: mouseArea3.ongoing=true
    }

    Rectangle {
        id: buttonPlay1
        x: 36
        y: 320
        width: 71
        height: 38
        radius: 5
        visible: false
        z: 1
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#0066ff"
            }

            GradientStop {
                position: 1
                color: "#001433"
            }
        }
        Text {
            id: textPlay1
            x: 8
            y: 8
            width: 55
            height: 22
            text: qsTr("▻")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 18
            font.bold: true
        }

        MouseArea {
            id: mouseAreaPlay1
            x: 0
            y: 0
            width: 71
            height: 38
            hoverEnabled: true
        }
        scale: mouseAreaPlay1.containsMouse ? 1.02 : 1.0
        border.width: 1
        opacity: mouseAreaPlay1.containsMouse ? 0.95 : 0.8
    }

    Rectangle {
        id: buttonPlay2
        x: 248
        y: 320
        width: 71
        height: 38
        color: "#0066ff"
        radius: 5
        visible: false
        z: 1
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#0066ff"
            }

            GradientStop {
                position: 1
                color: "#001433"
            }
        }
        Text {
            id: textPlay2
            x: 8
            y: 8
            width: 55
            height: 22
            text: qsTr("▻")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            font.pixelSize: 18
        }

        MouseArea {
            id: mouseAreaPlay2
            x: 0
            y: 0
            width: 71
            height: 38
            hoverEnabled: true
        }
        scale: mouseAreaPlay2.containsMouse ? 1.02 : 1.0
        border.width: 1
        opacity: mouseAreaPlay2.containsMouse ? 0.95 : 0.8
    }



}
