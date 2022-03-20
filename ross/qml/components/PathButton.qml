import QtQuick 2.15
import QtQuick.Dialogs 1.3

import "../items" as Items

Items.RButton {
    id: root

    onClicked: dialog.open()

    signal pathSelected(url path);

    FileDialog {
        id: dialog

        title: "Select path to watch"

        selectFolder: true

        onAccepted: root.pathSelected(dialog.fileUrl)
    }
}
