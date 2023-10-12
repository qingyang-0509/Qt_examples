//
// Created by 30205 on 2023/10/11.
//

#ifndef CLIENT_H
#define CLIENT_H

#include <QDataStream>
#include <QDialog>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
QT_END_NAMESPACE

//! [0]
class Client : public QDialog {
Q_OBJECT

public:
	explicit Client(QWidget* parent = nullptr);

private slots:
	void requestNewFortune();
	void readFortune();
	void displayError(QAbstractSocket::SocketError socketError);
	void enableGetFortuneButton();

private:
	QComboBox* hostCombo = nullptr;
	QLineEdit* portLineEdit = nullptr;
	QLabel* statusLabel = nullptr;
	QPushButton* getFortuneButton = nullptr;

	QTcpSocket* tcpSocket = nullptr;
	QDataStream in;
	QString currentFortune;
};
//! [0]

#endif
