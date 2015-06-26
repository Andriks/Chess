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
                       curGame.stopAction()
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

            onClicked: curGame.saveAction()
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
                       curGame.startAction()

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

            onClicked: curGame.loadAction()
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
                color: "#ffffff"
                border.width: 1
                objectName: "cell11"
                MouseArea {
                    id: mouseAreaCell11
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                objectName: "cell12"
                MouseArea {
                    id: mouseAreaCell12
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                objectName: "cell13"
                MouseArea {
                    id: mouseAreaCell13
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
                }
            }

            Rectangle {
                id: cell14
                x: 180
                y: 0
                width: 60
                height: 60
                color: "#ffffff"
                objectName: "cell14"
                MouseArea {
                    id: mouseAreaCell14
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell15
                x: 240
                y: 0
                width: 60
                height: 60
                color: "#ffffff"
                objectName: "cell15"
                MouseArea {
                    id: mouseAreaCell15
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                objectName: "cell16"
                MouseArea {
                    id: mouseAreaCell16
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                objectName: "cell17"
                MouseArea {
                    id: mouseAreaCell17
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                objectName: "cell18"
                MouseArea {
                    id: mouseAreaCell18
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                objectName: "cell21"
                MouseArea {
                    id: mouseAreaCell21
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell22
                x: 60
                y: 0
                width: 60
                height: 60
                color: "#ffffff"
                objectName: "cell22"
                MouseArea {
                    id: mouseAreaCell22
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell23
                x: 120
                y: 0
                width: 60
                height: 60
                color: "#ffffff"
                objectName: "cell23"
                MouseArea {
                    id: mouseAreaCell23
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell24
                x: 180
                y: 0
                width: 60
                height: 60
                color: "#ffffff"
                objectName: "cell24"
                MouseArea {
                    id: mouseAreaCell24
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell25
                x: 240
                y: 0
                width: 60
                height: 60
                color: "#ffffff"
                objectName: "cell25"
                MouseArea {
                    id: mouseAreaCell25
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell26
                x: 300
                y: 0
                width: 60
                height: 60
                color: "#ffffff"
                objectName: "cell26"
                MouseArea {
                    id: mouseAreaCell26
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell27
                x: 360
                y: 0
                width: 60
                height: 60
                color: "#ffffff"
                objectName: "cell27"
                MouseArea {
                    id: mouseAreaCell27
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
                }
                border.width: 1
            }

            Rectangle {
                id: cell28
                x: 420
                y: 0
                width: 60
                height: 60
                color: "#ffffff"
                objectName: "cell28"
                MouseArea {
                    id: mouseAreaCell28
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell31
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell32
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell33
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell34
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell35
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell36
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell37
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell38
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell41
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell42
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell43
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell44
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell45
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell46
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell47
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
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
                color: "#ffffff"
                MouseArea {
                    id: mouseAreaCell48
                    anchors.fill: parent

                    onClicked: curGame.cellAction(parent.objectName)
                }
                border.width: 1
                objectName: "cell48"
            }
            border.width: 0
            border.color: "#ffffff"
            visible: true
        }

    }
}
