import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.4
import QtQml 2.12

ApplicationWindow{
    id:root
    x:600
    y:200
    width: 480
    height: 220
    visible: true
    //title: qsTr("Hello World")
    flags: Qt.FramelessWindowHint |
           Qt.WindowMinimizeButtonHint |
           Qt.Window
    color:"#22303c"


    property int connect_count:0
    Rectangle{
        id:bground
        x:0
        y:0
        width: root.width
        height: 73
        color: "#3c4043"
        Text {
            x: 10
            y:15
            id: bground_text
            text: qsTr("Dashboard")
            font.pixelSize: 24
            color: "#ffffff"
            font.letterSpacing: 2

        }
    }


    Rectangle{
        id:btn_connnect
        width:144
        height:50
        anchors.top:parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        color: "#1d3752"
        radius:6
        border.width: 2
        border.color:"#465161"
        Text {
            id: text_connect
            text: qsTr("Connect")
            font.letterSpacing: 2
            anchors.centerIn: parent
            font.pixelSize: 17
            color: "#ffffff"
        }
        MouseArea{
            anchors.fill:parent
            onClicked: {
                connect_count+=1

                if(connect_count ==1)
                {
                    text_connect.text="Connected"
                    say_print();

                }

                else
                {
                    text_connect.text="Disconnected"
                    screen_.text = " "
                    connect_count = 0
                }

            }
            onEntered: {
                btn_connnect.color="#22303c"
            }
            onExited: {
               btn_connnect.color="#1d3752"
            }

        }
    }

    Text {
        x:10
        y:85
        color: "whitesmoke"
        font.pixelSize: 14
        text: qsTr("COM = COM8")
        //font.family: fontStyle.medium
    }


    Text {
        x:10
        y:105
        font.pixelSize: 14
        color: "whitesmoke"
        text: qsTr("Baudrate = 9600")
         //font.family: fontStyle.medium
    }


    TextArea{
        id: screen_
        anchors.horizontalCenter: parent.horizontalCenter
        y:100
        width: 190
        height: 100
        font.pixelSize: 16
        text: " "


    }

    function say_print()
    {
        setfunction.serial_read()
    }

    signal reLine (string str)
    Component.onCompleted: setfunction.serialChange.connect(reLine)
    Component.onDestruction: setfunction.serialChange.disconnect(reLine)


    Connections{
        target: root
        function onReLine(str)
        {
            screen_.text = str
        }


    }


}
