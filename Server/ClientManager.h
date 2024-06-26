#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "ChatProtocol.h"
#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class ClientManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientManager(QHostAddress ip = QHostAddress::LocalHost, ushort port = 4500, QObject *parent = nullptr);
    explicit ClientManager(QTcpSocket* client, QObject *parent = nullptr);
    void connectToServer();
    void sendMessage(QString message);
    void sendName(QString name);
    void sendStatus(ChatProtocol::Status status);
    QString name() const;

public:
    void sendIsTyping();
    void setupClient();

signals:
    void connected();
    void disconnected();
    // void dataReceived(QByteArray data);
    void textMessageReceived(QString message);
    void isTyping();
    void nameChanged(QString name);
    void statusChanged(ChatProtocol::Status status);

private slots:
    void readyRead();

private:
    QTcpSocket *_socket;
    QHostAddress _ip;
    ushort _port;
    ChatProtocol _protocol;
};

#endif // CLIENTMANAGER_H
