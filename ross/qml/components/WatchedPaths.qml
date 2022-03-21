import QtQuick 2.15
import QtQuick.Layouts 1.15

import "../items" as Items

import ross.styles 0.1


Item {
    id: root

    implicitWidth: mainLayout.implicitWidth
    implicitHeight: mainLayout.implicitHeight

    ColumnLayout {
        id: mainLayout

        spacing: RossStyles.smallMargin

        anchors {
            fill: parent
            margins: RossStyles.smallMargin
        }

    }
}
