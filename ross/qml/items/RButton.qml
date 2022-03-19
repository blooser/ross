import QtQuick 2.15
import QtQuick.Controls 2.15

import ross.styles 0.1

Button {
    id: root

    text: "Add path to watch"

    contentItem: Text {
        text: root.text
        font: root.font

        color: RossStyles.textColor
    }

    background: Rectangle {
        border.color: root.down ? RossStyles.secondColor : RossStyles.activeColor
        color: RossStyles.thirdColor
        radius: 5
    }
}
