import QtQuick 2.15
import QtQuick.Layouts 1.15

import "../items" as Items

import ross.styles 0.1


Item {
    id: root

    implicitWidth: layout.implicitWidth
    implicitHeight: layout.implicitHeight

    property string text: ""

    ColumnLayout {
        id: layout

        anchors.fill: parent

        Items.RText {
            Layout.fillWidth: true

            horizontalAlignment: Text.AlignHCenter

            style: Text.Sunken
            styleColor: RossStyles.styleColor

            text: root.text
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: RossStyles.lineWidth

            color: RossStyles.activeColor
        }
    }
}
