import QtQuick 2.5
import QtQuick.Controls 2.0
import Qt.labs.calendar 1.0

ComboBox {
    id: comboBox1
    width: 120
    height: 20
    textRole: qsTr("")
    model: [ "Local", "YouTube" ]
}
