import QtQuick 2.15

import "../items" as Items

Items.RButton {
    id: root

    text: currentText

    property string frontText: "Start"
    property string backText: "Stop"

    readonly property string currentText: [frontText, backText][+active]

    property bool active: false

    signal switched()

    onClicked: {
        active = !active
        root.switched()
    }
}
