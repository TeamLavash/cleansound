import QtQuick 2.5
import QtGraphicalEffects.private 1.0

Rectangle {

    width: 360
    height: 400
    property alias mouseArea2: mouseArea2
    property alias mouseArea1: mouseArea1
    property alias buttonVideo1: buttonVideo1
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#0000ff"
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
        font.bold: true
        style: Text.Outline
        styleColor: "#ffffff"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: "Times New Roman"
        font.pixelSize: 46
    }

    Rectangle {
        id: buttonVideo1
        x: 36
        y: 214
        width: 112
        height: 38
        radius: 5
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
        border.width: 1

        Text {
            id: textButton1
            x: 8
            y: 8
            width: 96
            height: 22
            text: qsTr("ADD 1")
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 18
        }

        MouseArea {
            id: mouseArea1
            x: 0
            y: 0
            width: 112
            height: 38
        }
    }

    Rectangle {
        id: buttonVideo2
        x: 207
        y: 214
        width: 112
        height: 38
        radius: 5
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
        }
        border.width: 1
    }
}
