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

        Header {
            Layout.fillWidth: true
            text: "Watched paths"
        }

        ListView {
            id: list

            Layout.fillWidth: true
            Layout.fillHeight: true

            boundsBehavior: Flickable.StopAtBounds

            model: paths.watched
            spacing: 5

            add: Transition {
                OpacityAnimator {
                    from: 0; to: 1; duration: 250
                }
            }

            remove: Transition {
                OpacityAnimator {
                    from: 1; to: 0; duration: 250
                }
            }

            delegate: WatchedPathListItem {
                width: list.width // NOTE: Without this, sizing is ridiculous...

                path: watchedPath

                onRemove: paths.unwatch(watchedPath) // NOTE: Use delegate item's value to get maximum compatibility
            }
        }
    }
}

