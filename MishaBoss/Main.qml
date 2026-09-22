import QtQuick.Controls
import QtQuick
import MishaBoss

ApplicationWindow  {

	id : mainWindow

	visible: true

	width: 640
	height: 480

	title: qsTr("Hello World")


	menuBar: MenuBar {

		Menu {
			title: qsTr("&File")
			Action { text: qsTr("&New...")}
			//Action { text: qsTr("&Open...") }
			//Action { text: qsTr("&Save") }
			//Action { text: qsTr("Save &As...") }
			MenuSeparator { }

			Action {
				id : exitAvtion
				text: qsTr("&Quit")
				onTriggered: mainWindow.close()
			}
		}
	}

	ScrollView {

		id : main_view
		anchors.fill: parent

		TableView {

			id : dataBaseView
			anchors.fill: parent
			clip : true
			interactive: true

		}
	}
}
