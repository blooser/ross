import QtQuick 2.15
import QtQuick.Controls 2.15
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

        Header {
            Layout.fillWidth: true

            text: "Events"
        }

        HorizontalHeaderView {
            id: header

            Layout.fillWidth: true

            syncView: table
            model: paths.events

            readonly property var headers: (column) => {
                return ["Event", "Path", "Folder", "Timestamp"][column]
            }

            delegate: Items.RText {
                text: header.headers(column)
                font.bold: true
            }
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
                return [300, 800, 300, 500][column]
            }

            delegate: Rectangle {
                color: "transparent"

                clip: true

                border {
                    width: 1
                    color: RossStyles.firstColor
                }

                Items.RText {
                    text: display
                }
            }

            Behavior on height {
                PropertyAnimation {
                    duration: 50
                }
            }
        }
    }
}


