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
                       btnSave.visible = false,
                       Controller.stopAction()
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

            onClicked: Controller.saveAction()
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
                       btnLoad.visible = false,
                       Controller.startAction()

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
            id: capLoad
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

            onClicked: Controller.loadAction()
        }
    }

    Rectangle {
        id: desk
        x: 60
        y: 60
        width: 480
        height: 480
        color: "#ffffff"
        border.width: 0

        Rectangle {
            id: row1
            x: 0
            y: 0
            width: 480
            height: 60
            color: "#ffffff"
            border.color: "#ffffff"
            border.width: 0
            visible: true

            Rectangle {
                id: cell11
                x: 0
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                border.width: 1
                objectName: "cell11"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell11
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
            }

            Rectangle {
                id: cell12
                x: 60
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                border.width: 1
                objectName: "cell12"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell12
                    x: 7
                    y: 5
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
            }

            Rectangle {
                id: cell13
                x: 120
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                border.width: 1
                objectName: "cell13"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell13
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
            }

            Rectangle {
                id: cell14
                x: 180
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                objectName: "cell14"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell14
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell15
                x: 240
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                objectName: "cell15"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell15
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell16
                x: 300
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                objectName: "cell16"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell16
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell17
                x: 360
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                objectName: "cell17"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell17
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell18
                x: 420
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                objectName: "cell18"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell18
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }
        }

        Rectangle {
            id: row2
            x: 0
            y: 60
            width: 480
            height: 60
            color: "#ffffff"
            border.width: 0
            border.color: "#ffffff"
            visible: true
            Rectangle {
                id: cell21
                x: 0
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                objectName: "cell21"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell21
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell22
                x: 60
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                objectName: "cell22"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell22
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell23
                x: 120
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                objectName: "cell23"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell23
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell24
                x: 180
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                objectName: "cell24"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell24
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell25
                x: 240
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                objectName: "cell25"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell25
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell26
                x: 300
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                objectName: "cell26"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell26
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell27
                x: 360
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                objectName: "cell27"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell27
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell28
                x: 420
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                objectName: "cell28"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell28
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
            }
        }

        Rectangle {
            id: row3
            x: 0
            y: 120
            width: 480
            height: 60
            color: "#ffffff"
            Rectangle {
                id: cell31
                x: 0
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell31
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell31"
            }

            Rectangle {
                id: cell32
                x: 60
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell32
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell32"
            }

            Rectangle {
                id: cell33
                x: 120
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell33
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell33"
            }

            Rectangle {
                id: cell34
                x: 180
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell34
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell34"
            }

            Rectangle {
                id: cell35
                x: 240
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell35
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell35"
            }

            Rectangle {
                id: cell36
                x: 300
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell36
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell36"
            }

            Rectangle {
                id: cell37
                x: 360
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell37
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell37"
            }

            Rectangle {
                id: cell38
                x: 420
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell38
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell38"
            }
            border.width: 0
            border.color: "#ffffff"
            visible: true
        }

        Rectangle {
            id: row4
            x: 0
            y: 180
            width: 480
            height: 60
            color: "#ffffff"
            Rectangle {
                id: cell41
                x: 0
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell41
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell41"
            }

            Rectangle {
                id: cell42
                x: 60
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell42
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell42"
            }

            Rectangle {
                id: cell43
                x: 120
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell43
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell43"
            }

            Rectangle {
                id: cell44
                x: 180
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell44
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell44"
            }

            Rectangle {
                id: cell45
                x: 240
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell45
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell45"
            }

            Rectangle {
                id: cell46
                x: 300
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell46
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell46"
            }

            Rectangle {
                id: cell47
                x: 360
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell47
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell47"
            }

            Rectangle {
                id: cell48
                x: 420
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell48
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell48"
            }
            border.width: 0
            border.color: "#ffffff"
            visible: true
        }

        Rectangle {
            id: row5
            x: 0
            y: 240
            width: 480
            height: 60
            color: "#ffffff"
            Rectangle {
                id: cell51
                x: 0
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell51
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell51"
            }

            Rectangle {
                id: cell52
                x: 60
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell52
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell52"
            }

            Rectangle {
                id: cell53
                x: 120
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell53
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell53"
            }

            Rectangle {
                id: cell54
                x: 180
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell54
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell54"
            }

            Rectangle {
                id: cell55
                x: 240
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell55
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell55"
            }

            Rectangle {
                id: cell56
                x: 300
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell56
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell56"
            }

            Rectangle {
                id: cell57
                x: 360
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell57
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell57"
            }

            Rectangle {
                id: cell58
                x: 420
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell58
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell58"
            }
            border.width: 0
            border.color: "#ffffff"
            visible: true
        }

        Rectangle {
            id: row6
            x: 0
            y: 300
            width: 480
            height: 60
            color: "#ffffff"
            Rectangle {
                id: cell61
                x: 0
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell61
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell61"
            }

            Rectangle {
                id: cell62
                x: 60
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell62
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell62"
            }

            Rectangle {
                id: cell63
                x: 120
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell63
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell63"
            }

            Rectangle {
                id: cell64
                x: 180
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell64
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell64"
            }

            Rectangle {
                id: cell65
                x: 240
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell65
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell65"
            }

            Rectangle {
                id: cell66
                x: 300
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell66
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell66"
            }

            Rectangle {
                id: cell67
                x: 360
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell67
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell67"
            }

            Rectangle {
                id: cell68
                x: 420
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell68
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell68"
            }
            border.width: 0
            border.color: "#ffffff"
            visible: true
        }

        Rectangle {
            id: row7
            x: 0
            y: 360
            width: 480
            height: 60
            color: "#ffffff"
            Rectangle {
                id: cell71
                x: 0
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell71
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell71"
            }

            Rectangle {
                id: cell72
                x: 60
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell72
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell72"
            }

            Rectangle {
                id: cell73
                x: 120
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell73
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell73"
            }

            Rectangle {
                id: cell74
                x: 180
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell74
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell74"
            }

            Rectangle {
                id: cell75
                x: 240
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell75
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell75"
            }

            Rectangle {
                id: cell76
                x: 300
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell76
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell76"
            }

            Rectangle {
                id: cell77
                x: 360
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell77
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell77"
            }

            Rectangle {
                id: cell78
                x: 420
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell78
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell78"
            }
            border.width: 0
            border.color: "#ffffff"
            visible: true
        }

        Rectangle {
            id: row8
            x: 0
            y: 420
            width: 480
            height: 60
            color: "#ffffff"
            Rectangle {
                id: cell81
                x: 0
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell81
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell81"
            }

            Rectangle {
                id: cell82
                x: 60
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell82
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell82"
            }

            Rectangle {
                id: cell83
                x: 120
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell83
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell83"
            }

            Rectangle {
                id: cell84
                x: 180
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell84
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell84"
            }

            Rectangle {
                id: cell85
                x: 240
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell85
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell85"
            }

            Rectangle {
                id: cell86
                x: 300
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell86
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell86"
            }

            Rectangle {
                id: cell87
                x: 360
                y: 0
                width: 60
                height: 60
                color: "#9e630a"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell87
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell87"
            }

            Rectangle {
                id: cell88
                x: 420
                y: 0
                width: 60
                height: 60
                color: "#ffead1"
                Text {
                    objectName: "t_"+parent.objectName;
                    width: parent.width
                    height: parent.height
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    id: mouseAreaCell88
                    anchors.fill: parent

                    onClicked: Controller.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell88"
            }
            border.width: 0
            border.color: "#ffffff"
            visible: true
        }

    }

    Rectangle {
        id: btnDraw
        x: 462
        y: 8
        width: 130
        height: 40
        color: "#f5cba3"
        Text {
            id: capDraw
            width: 130
            height: 40
            text: qsTr("Draw")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea {
            id: mouseAreaDraw
            anchors.fill: parent

            onClicked: Controller.tmpDraw()
        }
        objectName: "btnLoad"
    }
}
