import QtQuick 2.15
import QtQuick.Layouts 1.15

import "../items" as Items

import ross.styles 0.1


Rectangle {
    id: root

    implicitWidth: layout.implicitWidth
    implicitHeight: layout.implicitHeight

    radius: 10

    border {
        width: 1
        color: RossStyles.activeColor

    }

    color: "transparent"

    ColumnLayout {
        id: layout

        anchors {
            fill: root
            margins: 5
        }

        Items.RText {
            text: "Watched paths"

        }

        ListView {
            id: list

            Layout.fillWidth: true
            Layout.fillHeight: true

            model: paths.watching
            spacing: 5

            delegate: WatchedPathListItem {
                width: list.width // FIXME: Without this sizing is ridiculous.

                path: watchedPath

                onRemove: {
                    console.log("Remove", path)
                }
            }
        }
    }
}

