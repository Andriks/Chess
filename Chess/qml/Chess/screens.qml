import QtQuick 2.0

Rectangle {
    width: 600
    height: 600

    Rectangle {
        id: btnStop
        x: 60
        y: 8
        width: 130
        height: 40
        color: "#f5cba3"
        objectName: "btnStop"
        Text {
            id: capStop
            x: 0
            y: 0
            width: 130
            height: 40
            text: qsTr("Stop")
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea {
            id: mouseAreaStop
            anchors.fill: parent

            onClicked: btnStart.visible = true,
                       btnLoad.visible = true,
                       btnStop.visible = false,
                       btnSave.visible = false
                       //curDesc.stopAction()
        }
    }

    Rectangle {
        id: btnSave
        x: 212
        y: 8
        width: 130
        height: 40
        color: "#f5cba3"
        objectName: "btnStop"
        Text {
            id: capSave
            x: 0
            y: 0
            width: 130
            height: 40
            text: qsTr("Save")
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea {
            id: mouseAreaSave
            anchors.fill: parent
        }
    }

    Rectangle {
        id: btnStart
        x: 60
        y: 8
        width: 130
        height: 40
        color: "#f5cba3"
        objectName: "btnStart"
        Text {
            id: capStart
            x: 0
            y: 0
            width: 130
            height: 40
            text: qsTr("Start")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
        }

        MouseArea {
            id: mouseAreaStart
            anchors.fill: parent

            onClicked: btnStop.visible = true,
                       btnSave.visible = true,
                       btnStart.visible = false,
                       btnLoad.visible = false
            //curDesc.stopAction()

        }
    }

    Rectangle {
        id: btnLoad
        x: 212
        y: 8
        width: 130
        height: 40
        color: "#f5cba3"
        objectName: "btnLoad"
        Text {
            id: capStart1
            x: 0
            y: 0
            width: 130
            height: 40
            text: qsTr("Load")
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea {
            id: mouseAreaLoad
            anchors.fill: parent
        }
    }

    Rectangle {
        id: desc
        x: 60
        y: 60
        width: 480
        height: 480
        color: "#ffffff"
        border.width: 0

        Rectangle {
            id: cell11
            x: 0
            y: 0
            width: 60
            height: 60
            color: "#ffffff"
            border.width: 1

            MouseArea {
                id: mouseAreaCell11
                visible: true
                anchors.fill: parent

                onClicked: curDesc.cellAction(parent.objectName)
            }
        }

        Rectangle {
            id: cell12
            x: 60
            y: 0
            width: 60
            height: 60
            color: "#ffffff"
            border.width: 1

            MouseArea {
                id: mouseAreaCell12
                anchors.fill: parent

                onClicked: curDesc.cellAction(parent.objectName)
            }
        }

        Rectangle {
            id: cell13
            x: 120
            y: 0
            width: 60
            height: 60
            color: "#ffffff"
            border.width: 1

            MouseArea {
                id: mouseAreaCell13
                anchors.fill: parent

                onClicked: curDesc.cellAction(parent.objectName)
            }
        }

        Rectangle {
            id: cell14
            x: 180
            y: 0
            width: 60
            height: 60
            color: "#ffffff"
            border.width: 1

            MouseArea {
                id: mouseAreaCell14
                anchors.fill: parent

                onClicked: curDesc.cellAction(parent.objectName)
            }
        }

        Rectangle {
            id: cell15
            x: 240
            y: 0
            width: 60
            height: 60
            color: "#ffffff"
            MouseArea {
                id: mouseAreaCell15
                anchors.fill: parent
            }
            border.width: 1
        }

        Rectangle {
            id: cell16
            x: 300
            y: 0
            width: 60
            height: 60
            color: "#ffffff"
            MouseArea {
                id: mouseAreaCell16
                anchors.fill: parent
            }
            border.width: 1
        }

        Rectangle {
            id: cell17
            x: 360
            y: 0
            width: 60
            height: 60
            color: "#ffffff"
            MouseArea {
                id: mouseAreaCell17
                anchors.fill: parent
            }
            border.width: 1
        }

        Rectangle {
            id: cell18
            x: 420
            y: 0
            width: 60
            height: 60
            color: "#ffffff"
            MouseArea {
                id: mouseAreaCell18
                anchors.fill: parent
            }
            border.width: 1
        }
    }
}
