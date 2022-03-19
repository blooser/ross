import QtQuick 2.15
import Qt.labs.platform 1.1

import "../items" as Items

Items.RButton {
    id: root

    onClicked: dialog.open()

    signal pathSelected(url path);

    FolderDialog {
        id: dialog

        title: "Choose path to watch"

        onAccepted: root.pathSelected(dialog.folder)
    }
}
