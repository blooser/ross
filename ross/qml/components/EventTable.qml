import QtQuick 2.15
import QtQuick.Layouts 1.15
import Qt.labs.qmlmodels 1.0

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
            margins: 10
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

            columnSpacing: 1
            rowSpacing: 1
            clip: true

            model: paths.events

            columnWidthProvider: (column) => {
                return [100, 500, 100, 100][column]
            }

            delegate: Rectangle {


                color: "transparent"

                border {
                    width: 1
                    color: RossStyles.firstColor
                }

                Items.RText {
                    text: display
                }
            }
        }
    }
}


