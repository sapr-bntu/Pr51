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

    Image {
            id: prevImage
            source: "I:/QT_proj/prev.png"
            x: 10
            y: parent.height/2
                    width: 88
                    height: 88
//                anchors.leftMargin: 0
//                anchors.rightMargin: 0
//                anchors.bottomMargin: 0
//                anchors.topMargin: 0
//                anchors.fill: parent
            opacity: 0.02
            scale: 1
            visible:true
//    Rectangle {
//        id: prevButtonRectangle
//        x: 10
//        y: parent.height/2
//        width: 88
//        height: 34
//        color: "#2093a4"
//        opacity: 0.200

//        Image {
//                id: prevImage
//                source: "I:/QT_proj/prev.png"
//                x: 0
//                y: 0
//                anchors.leftMargin: 0
//                anchors.rightMargin: 0
//                anchors.bottomMargin: 0
//                anchors.topMargin: 0
//                anchors.fill: parent
//                opacity: 0.02
//                scale: 1
//              }

//        Text {
//            id: prevButtonText
//            x: 10
//            y: 6
//            text: qsTr("Previous")
//            font.pointSize: 14
//            verticalAlignment: Text.AlignVCenter
//            horizontalAlignment: Text.AlignHCenter

//        }
        MouseArea {
            id: prevButton
            x: 0
            y: 0
            width: 88
            height: 34
            visible: true
            hoverEnabled: true
            smooth: true
//            anchors.leftMargin: 0
//            anchors.rightMargin: 0
//            anchors.bottomMargin: 0
//            anchors.topMargin: 0
//            anchors.fill: parent
            onEntered: {parent.opacity=1}
            onExited: {parent.opacity=0.02}
            onClicked: JSFunc.prevFile()
            enabled: false
        }
    }

//    Rectangle {
//        id: nextButtonRectangle
//        x: parent.width-100
//        y: parent.height/2
//        width: 88
//        height: 34
//        //color: "#ffffffff"
//        opacity: 1

//        Text {
//            id: nextButtonText
//            x: 25
//            y: 6
//            text: qsTr("Next")
//            font.pointSize: 14
//            verticalAlignment: Text.AlignVCenter
//            horizontalAlignment: Text.AlignHCenter

//        }
        Image {
                id: nextImage
                source: "I:/QT_proj/next.png"
                x: parent.width-100
                        y: parent.height/2
                        width: 88
                        height: 88
//                anchors.leftMargin: 0
//                anchors.rightMargin: 0
//                anchors.bottomMargin: 0
//                anchors.topMargin: 0
//                anchors.fill: parent
                opacity: 0.02
                scale: 1
                visible:true



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
            onExited: {parent.opacity=0.02}
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

            onTextChanged:  {JSFunc.saveMark()}
        }
    }

    Rectangle {
        id: commentTextRectangle
        x: 456
        y: 0
        width: 95
        height: 34
        color: "#2022a4"
        clip: true
        opacity: 0.200

        TextEdit {
            id: commentText
            x: 276
            y: 227
            width: 90
            height: 20
            font.pixelSize: 24
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            onTextChanged:  {JSFunc.saveMark()}
        }
    }

    Rectangle {
        id: exitButtonRectangle
        x: parent.width-100
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
