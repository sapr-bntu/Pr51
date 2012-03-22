// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "ImageViewer.js" as JSFunc

Rectangle {
    width: 800
    height: 600
    color: "#ffffff"


    Image {
        id: image1
        x: 0
        y: 66
        width: 360
        height: 294
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    Rectangle {
        id: openFileButtonRectangle
        x: 0
        y: 0
        width: 88
        height: 34
        color: "#2093a4"
        opacity: 0.200

        Text {
            id: openFileButtonText
            x: 5
            y: 6
            text: qsTr("Open File")
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

        }
        MouseArea {
            id: openFileButton
            x: 0
            y: 0
            width: 88
            height: 34
            visible: true
            hoverEnabled: true
            smooth: true
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            onEntered: {parent.opacity=1}
            onExited: {parent.opacity=0.5}
            onClicked: JSFunc.openFile()

        }

    }

    Rectangle {
        id: prevButtonRectangle
        x: 102
        y: 0
        width: 88
        height: 34
        color: "#2093a4"
        opacity: 0.200

        Text {
            id: prevButtonText
            x: 10
            y: 6
            text: qsTr("Previous")
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

        }
        MouseArea {
            id: prevButton
            x: 0
            y: 0
            width: 88
            height: 34
            visible: true
            hoverEnabled: true
            smooth: true
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            onEntered: {parent.opacity=1}
            onExited: {parent.opacity=0.5}
            onClicked: JSFunc.prevFile()
            enabled: false
        }
    }

    Rectangle {
        id: nextButtonRectangle
        x: 204
        y: 0
        width: 88
        height: 34
        color: "#2093a4"
        opacity: 0.200

        Text {
            id: nextButtonText
            x: 25
            y: 6
            text: qsTr("Next")
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

        }
        MouseArea {
            id: nextButton
            x: 0
            y: 0
            width: 88
            height: 34
            visible: true
            hoverEnabled: true
            smooth: true
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            onEntered: {parent.opacity=1}
            onExited: {parent.opacity=0.5}
            onClicked: JSFunc.nextFile()
            enabled: false
        }
    }

    Rectangle {
        id: saveButtonRectangle
        x: 306
        y: 0
        width: 88
        height: 34
        color: "#2093a4"
        clip: true
        opacity: 0.200

        Text {
            id: saveButtonText
            x: 29
            y: 6
            text: qsTr("Save")
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

        }
        MouseArea {
            id: saveButton
            x: 0
            y: 0
            width: 88
            height: 34
            visible: true
            hoverEnabled: true
            smooth: true
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            onEntered: {parent.opacity=1}
            onExited: {parent.opacity=0.5}
            onClicked: JSFunc.saveMark()
        }
    }

    Rectangle {
        id: markTextRectangle
        x: 406
        y: 0
        width: 40
        height: 34
        color: "#2022a4"
        clip: true
        opacity: 0.200

        TextEdit {
            id: markText
            x: 276
            y: 227
            width: 80
            height: 20
            font.pixelSize: 24
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: commentTextRectangle
        x: 456
        y: 0
        width: 88
        height: 34
        color: "#2022a4"
        clip: true
        opacity: 0.200

        TextEdit {
            id: commentText
            x: 276
            y: 227
            width: 80
            height: 20
            font.pixelSize: 24
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: exitButtonRectangle
        x: 656
        y: 0
        width: 88
        height: 34
        color: "#2093a4"
        clip: true
        opacity: 0.200

        Text {
            id: exitButtonText
            x: 29
            y: 6
            text: qsTr("Exit")
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

        }
        MouseArea {
            id: exitButton
            x: 0
            y: 0
            width: 88
            height: 34
            visible: true
            hoverEnabled: true
            smooth: true
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            onEntered: {parent.opacity=1}
            onExited: {parent.opacity=0.5}
            onClicked: {Qt.quit()}
        }
    }
}
