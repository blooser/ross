import QtQuick 2.15
import QtQuick.Layouts 1.15

import "../items" as Items

import ross.styles 0.1

Item {
    id: root

    implicitWidth: layout.implicitWidth
    implicitHeight: layout.implicitHeight

    RowLayout {
        id: layout

        anchors {
            fill: parent
            margins: RossStyles.smallMargin
        }

        Items.RButton {
            Layout.preferredWidth: 75

            text: "Clear"

            onClicked: paths.events.clear()
        }

        SwitchButton {
            Layout.preferredWidth: 75

            onSwitched: paths.watching = active
        }
    }
}
