import QtQuick 2.5
import QtQuick.Controls 2.0

Rectangle {
    id: rectangle1

    width: 360
    height: 400
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
        id: buttonVideo2
        x: 207
        y: 214
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
            hoverEnabled: true
        }
        border.width: 1
    }

    Image {
        id: image1
        anchors.fill: parent
        z: 0
        source: "res/soundwaves.jpg"
    }

    Rectangle {
        id: buttonVideo1
        x: 44
        y: 214
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
}
