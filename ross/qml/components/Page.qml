import QtQuick 2.15
import QtQuick.Layouts 1.15

import "../items" as Items

Item {
    implicitWidth: mainLayout.implicitWidth
    implicitHeight: mainLayout.implicitHeight

    anchors {
        fill: parent
        margins: 25
    }

    ColumnLayout {
        id: mainLayout

        anchors.fill: parent

        spacing: 5

        PathButton {
            Layout.alignment: Qt.AlignHCenter

            onPathSelected: paths.watch(path)
        }

        WatchedPathsList {
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

    }
}
