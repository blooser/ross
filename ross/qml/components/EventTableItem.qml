import QtQuick 2.15
import QtQuick.Layouts 1.15

import "../items" as Items

Item {
    id: root

    implicitWidth: layout.implicitWidth
    implicitHeight: layout.implicitHeight

    property string event
    property string path
    property string isFolder
    property string timestamp

    ColumnLayout {
        id: layout

        spacing: 5

        anchors {
            fill: parent
            margins: 5
        }

        Items.RText {
            font.pixelSize: 11

            text: root.event
        }

        Items.RText {
            font.pixelSize: 11

            text: root.path
        }

        Items.RText {
            font.pixelSize: 11

            text: root.isFolder
        }
    }
}
