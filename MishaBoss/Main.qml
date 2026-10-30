import QtQuick.Controls
import QtQuick
import MishaBoss

ApplicationWindow  {

	id : mainWindow

	visible: true

	width: 640
	height: 480

	title: qsTr("Misha is a Boss")

	//onShow :

	signal setTableSignal(tabName : string)


	menuBar: MenuBar {

		Menu {
			title: qsTr("&File")
			Action { text: qsTr("&New...")}
			Action {
				text: qsTr("Load")
				id : loadAct
				onTriggered: mainWindow.setTableSignal("staff.db")
			}
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

	onSetTableSignal : (string) => {
						   sqlModel.lodDB(string)
						   sqlModel.setTable(string)
					   }

	ScrollView {

		id : main_view
		anchors.fill: parent

		TableView {

			id : dataBaseView
			anchors.fill: parent
			clip : true
			interactive: true
			visible : true

			model: SqlModel {
				required property string table

				id : sqlModel
				table: ""

				function setTable(tableName) {
					table = tableName;
					console.log(tableName, "from qml")
				}
			}

			delegate: Rectangle {
				required property string modelData
				height: 25
				width: 100
				Text { text: parent.modelData }
			}
		}
	}
}
