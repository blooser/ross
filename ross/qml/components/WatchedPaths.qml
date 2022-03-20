import QtQuick 2.15
import QtQuick.Layouts 1.15

import "../items" as Items

Item {
    id: root

    implicitWidth: mainLayout.implicitWidth
    implicitHeight: mainLayout.implicitHeight

    ColumnLayout {
        id: mainLayout

        spacing: 5

        anchors {
            fill: parent
            margins: 5
        }

    }
}
