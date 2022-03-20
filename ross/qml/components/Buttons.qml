import QtQuick 2.15
import QtQuick.Layouts 1.15

import "../items" as Items

import ross.styles 0.1

Item {
    id: root

    implicitWidth: layout.implicitWidth
    implicitHeight: layout.implicitHeight

    signal clear()
    signal stop()
    signal start()

    RowLayout {
        id: layout

        anchors {
            fill: parent
            margins: 5
        }

        Items.RButton {
            Layout.preferredWidth: 75

            text: "Clear"

            onClicked: root.clear()
        }

        Items.RButton {
            Layout.preferredWidth: 75

            text: "Start"

            onClicked: root.start()
        }
    }
}
