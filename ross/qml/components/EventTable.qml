import QtQuick 2.15
import QtQuick.Layouts 1.15

import ross.styles 0.1

import "../items" as Items


Rectangle {
    id: root

    implicitWidth: layout.implicitWidth
    implicitHeight: layout.implicitHeight

    border {
        width: 1
        color: RossStyles.activeColor
    }

    radius: 10

    color: "transparent"

    ColumnLayout {
        id: layout

        anchors {
            fill: parent
            margins: 5
        }

        Items.RText {
            Layout.fillWidth: true

            horizontalAlignment: Text.AlignHCenter

            text: "Events"
        }

        TableView {
            id: table

            Layout.fillWidth: true
            Layout.fillHeight: true

            columnSpacing: 2
            rowSpacing: 2
            clip: true

            model: paths.events

            delegate: Items.RText {
                text: path
            }
        }
    }


}


