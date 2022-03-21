pragma Singleton


import QtQuick 2.15

QtObject {
    readonly property color firstColor: "#003333"
    readonly property color secondColor: "#006666"
    readonly property color thirdColor: "#009999"

    readonly property color activeColor: "#00e6e6"

    readonly property color textColor: "#ccffff"

    readonly property color styleColor: "black"

    readonly property color blank: "transparent"

    readonly property int lineWidth: 1
    readonly property int smallMargin: 5
    readonly property int normalMargin: 10
    readonly property int bigMargin: 20
}
