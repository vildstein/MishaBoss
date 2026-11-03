import QtQuick.Controls
import QtQuick
import MishaBoss

ApplicationWindow  {

	id : mainWindow

	visible: true

	width: 840
	height: 480

	minimumWidth: 200
	minimumHeight: 400

	title: qsTr("Misha is a Boss")

	signal setTableSignal(tabName : string)

	menuBar: MenuBar {

		Menu {
			title: qsTr("&File")
			Action { text: qsTr("&New...")}
			Action {
				text: qsTr("Load")
				id : loadAct
				onTriggered: dbReader.tryToConnect("staff.db")
			}
			//Action { text: qsTr("&Open...") }
			//Action { text: qsTr("&Save") }
			//Action { text: qsTr("Save &As...") }
			Action { text: qsTr("Add Ridgt")
					onTriggered: {
						rightNames.append({someNames :"Iron Maiden"});
					}
			}
			MenuSeparator { }

			Action {
				id : exitAvtion
				text: qsTr("&Quit")
				onTriggered: mainWindow.close()
			}
		}
	}

	SqlConnect {
		id : dbReader
	}

	SplitView {
		id: centerWidget
		anchors.fill: parent

		Frame {
			id : lefWidget

			SplitView.minimumWidth: 125
			SplitView.preferredWidth: 350
			SplitView.maximumWidth: 700

			background: Rectangle {
				id : backGround
				anchors.fill: parent
				color: "#0F1821"
			}

			ScrollView {
				id: mainView
				anchors.fill: parent
				ScrollBar.vertical.policy: ScrollBar.AlwaysOn

				ListModel {
					id: tableNames

				}

				Connections {
					target: dbReader
					function onTableReaded (tableName) {
						tableNames.append({tableName})
					}
				}

				ListView {
					id : listView
					anchors.fill: parent
					spacing: 5
					model: tableNames

					delegate: DbNameItem {
						id : frameDelegate
					}
					clip: true
				}
			}
		}

		Frame {
			id : rightWidget

			ListModel {
				id: rightNames

				ListElement {
					someNames: "Alice"
				}

				ListElement {
					someNames: "Cooper"
				}
			}

			Component {

				id : rightNameDelegate

				Rectangle {
					id : insideRect
					required property string someNames

					border.color: "#29465D"
					border.width: 2
					radius: 5
					color: "#111C24"//"#0F1821"
					width: rightWidget.width - 30
					height: 40

					Text {

						anchors.verticalCenter: parent.verticalCenter
						anchors.left: parent.left
						anchors.leftMargin: 15
						font.family: "Inter"
						font.pointSize: 24
						color: "#DAECFA"
						text: someNames
					}

					MouseArea {
						anchors.fill: parent
						hoverEnabled: true
						onEntered: {
							insideRect.color = "#1993E7"
						}
						onExited: {
							insideRect.color = "#111C24"
						}
					}
				}
			}

			ListView {
				id : rightListView
				anchors.fill: parent
				spacing: 10
				model: rightNames
				delegate: rightNameDelegate
				clip: true
			}
		}
	}
}
