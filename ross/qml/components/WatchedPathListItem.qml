import QtQuick 2.15
import QtQuick.Layouts 1.15

import "../items" as Items

Item {
    id: root

    implicitWidth: layout.implicitWidth
    implicitHeight: layout.implicitHeight

    property url path: undefined

    signal remove(url path)

    RowLayout {
        id: layout

        anchors {
            fill: parent
            margins: 5
        }

        Items.RText {
            Layout.fillWidth: true

            text: root.path
        }

        Items.RButton {
            Layout.alignment: Qt.AlignRight

            text: "Remove"

            onClicked: root.remove(root.path)

        }
    }
}
