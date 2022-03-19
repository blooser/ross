import QtQuick 2.14
import QtQuick.Layouts 1.15
import QtQuick.Window 2.14

import ross.styles 0.1

import "items" as Items
import "components" as Components

Window {
    id: root

    title: Qt.application.name
    visible: true

    width: 1000
    height: 750

    color: RossStyles.firstColor

    Components.Page {

    }
}
