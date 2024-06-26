#include "ClientManager.h"

ClientManager::ClientManager(QHostAddress ip, ushort port, QObject *parent)
    : QObject{parent},
    _ip(ip),
    _port(port)
{
    _socket = new QTcpSocket(this);
    connect(_socket, &QTcpSocket::connected, this, &ClientManager::connected);
    connect(_socket, &QTcpSocket::disconnected, this, &ClientManager::disconnected);
    connect(_socket, &QTcpSocket::readyRead, this, &ClientManager::readyRead);
}

void ClientManager::connectToServer()
{
    _socket->connectToHost(_ip, _port);
}

void ClientManager::sendMessage(QString message)
{
    _socket->write(_protocol.textMessage(message));
}

void ClientManager::sendName(QString name)
{
    _socket->write(_protocol.setNameMessage(name));
}

void ClientManager::sendStatus(ChatProtocol::Status status)
{
    _socket->write(_protocol.setStatusMessage(status));
}

void ClientManager::sendIsTyping(){
    _socket->write(_protocol.isTypingMessage());
}

void ClientManager::readyRead()
{
    auto data = _socket->readAll();
    _protocol.loadData(data);
    switch(_protocol.type()){
    case ChatProtocol::Text:
        emit textMessageReceived(_protocol.message());
        break;
    case ChatProtocol::SetName:
        emit nameChanged(_protocol.name());
        break;
    case ChatProtocol::SetStatus:
        emit statusChanged(_protocol.status());
        break;
    case ChatProtocol::IsTyping:
        emit isTyping();
        break;
    default:
        break;
    }
}

