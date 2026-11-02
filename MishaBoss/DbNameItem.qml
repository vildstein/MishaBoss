import QtQuick
import QtQuick.Controls

Rectangle {
	required property string tableName
	id : frameDelegate
	border.color: "#29465D"
	border.width: 2
	radius: 10
	color: "#111C24"//"#0F1821"
	width: parent.width - 20
	height: 40

	Text {


		anchors.verticalCenter: parent.verticalCenter
		anchors.left: parent.left
		anchors.leftMargin: 15
		font.family: "Inter"
		font.pointSize: 24
		color: "#DAECFA"
		text: frameDelegate.tableName
	}

	MouseArea {
		anchors.fill: parent
		hoverEnabled: true
		onEntered: {
			frameDelegate.color = "#1993E7"
		}
		onExited: {
			frameDelegate.color = "#111C24"
		}
	}
}




