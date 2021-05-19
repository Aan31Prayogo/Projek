import QtQuick.Layouts 1.2
import QtQml 2.12
import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

ApplicationWindow{
    property var com:""
    property var baudrate:""
    property int connect_count:0

    signal reLine (string str)
    
    Component.onCompleted: {
        setfunction.serialChange.connect(reLine)
    }
    Component.onDestruction:{
        setfunction.serialChange.disconnect(reLine)
    } 


    Connections{
        target: root
        function onReLine(str)
        {
            screen.append(str)
        }
    }


    id:root
    x:600
    y:200
    width: 640
    height: 480
    visible: true
    //title: qsTr("Hello World")
    flags: Qt.FramelessWindowHint |
           Qt.WindowMinimizeButtonHint |
           Qt.Window
    color:"#22303c"

    Rectangle{
        id:bground
        x:0
        y:0
        width: root.width
        height: 73
        color: "#3c4043"
        Text {
            x: 8
            y:23
            id: bground_text
            text: qsTr("Dashboard")
            font.pixelSize: 24
            font.wordSpacing: 0
            color: "#ffffff"
            font.letterSpacing: 2
       }

        ComboBox {
            id: comboBox_port
            x: 162
            y: 17
            font.family: "Helvetica"
            flat: false
            displayText:currentText
            editable: false
          model: ["COM6", "COM7", "COM8"]
          onActivated:{
                //console.log("I clicked item with index " + index + " which has label " + model[index])
            com=model[index]
            console.log("COM = ",com)
          }
        }

        ComboBox {
            id: comboBox_baud
            x: 329
            y: 17
            enabled: true
            font.weight: Font.Medium
            font.family: "Helvetica"
            displayText:currentText
            model: ["9600", "115200"]
            onActivated:{
                 // console.log("I clicked item with index " + index + " which has label " + model[index])
                baudrate=model[index]
                console.log("baudrate = ",baudrate)
            }

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
                    setfunction.start_serial(com,baudrate)

                }

                else
                {
                    text_connect.text="Disconnected"
                    screen.text = " "
                    setfunction.stop_serial()
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


    ScrollView {
            id: screen_view
            anchors.centerIn: parent
            width: 400
            height: 150
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            background: Rectangle {
                anchors.fill: parent
                border.color: "gray"
            }
            TextEdit {
                id: screen
                wrapMode: TextArea.Wrap
                selectByMouse: true
                font.pixelSize: 14
                //text:  "  "
            }
        }



  


}
