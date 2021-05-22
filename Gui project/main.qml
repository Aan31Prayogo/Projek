import QtQuick.Layouts 1.2
import QtQml 2.12
import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

ApplicationWindow{
    property var com:""
    property var baudrate:""
    property int connect_count:0
    property var serial_data:""
    property  var txt_file:""

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
            //serial_data=str
            //console.log(serial_data)            
        }
    }


    id:root
    x:300
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
        id:header_
        x:0
        y:0
        width: root.width
        height: 73
        color: "#3c4043"
        Text {
            x: 10
            y:23
            id: bground_text
            text: qsTr("Serial Logger")
            font.pixelSize: 18
            //font.wordSpacing: 0
            color: "azure"
            font.letterSpacing: 3
       }

        Text {
            id: port_text
            text: qsTr("Port:")
            font.pixelSize: 12
            color: "whitesmoke"
            x:162
            y:2
            font.letterSpacing: 2
        }

        ComboBox {
            id: comboBox_port
            x: 162
            y: 20
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
        Text {
            id: baud_text
            text: qsTr("Baudrate:")
            font.pixelSize: 12
            color: "whitesmoke"
            x:329
            y:2
            font.letterSpacing: 2
        }
        ComboBox {
            id: comboBox_baud
            x: 329
            y: 20
            enabled: true
            font.weight: Font.Medium
            font.family: "Helvetica"
            displayText:currentText
            model: ["9600", "57600","115200"]
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
        anchors.topMargin: 15
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

                if(connect_count ==1){
                    text_connect.text="Connected"
                    //console.log("TEXT: ", textfield.text)
                    txt_file=textfield.text
                    setfunction.start_serial(com,baudrate,txt_file)
                }
                else{
                    text_connect.text="Disconnected"
                    //screen.text = " "
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

    Text {
        id: screnn_text
        x:10
        y:120
        font.pixelSize: 14
        color: "whitesmoke"
        text: qsTr("Serial Screen")
        font.letterSpacing: 2
    }
    ScrollView {
            id: screen_view
            x:10
            y:150
            width: 400
            height: 200
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            background: Rectangle {
                anchors.fill: parent
                border.color: "gray"
            }
            TextArea {
                width:parent.width
                height:parent.height
                //anchors.fill: parent
                id: screen
                font.pixelSize: 14
                property int preContentHeight: 0
                wrapMode: TextArea.Wrap; selectByMouse: true;
                onContentHeightChanged: {
                    //The height of each line is 14, and it will scroll automatically when the input is greater than 3 lines
                    if(contentHeight > 14 && contentHeight < 28) {
                        if(contentHeight != preContentHeight) {
                            preContentHeight = contentHeight;
                            screen_view.height += 14;
                        }
                    }
                }
            }
        }

    Text {
        id: txt_text
        x:450
        y:130
        font.pixelSize: 12
        color: "whitesmoke"
        text: qsTr("File Name :")
        font.letterSpacing: 2
    }
    Text {
        id: txt_ex
        x:450
        y:185
        font.pixelSize: 10
        color: "whitesmoke"
        text: qsTr("example : \"file.txt\"")
        font.letterSpacing: 1
    }
    Rectangle{
        id:box_txt
        x:450
        y:150
        width: 150
        height: 30
        color: "whitesmoke"
        TextField {
            id:textfield
            width: parent.width
            height: parent.height
            placeholderText: qsTr("Enter file name")
            text:""
        }
    }

}
