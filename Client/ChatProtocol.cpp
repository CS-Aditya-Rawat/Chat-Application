#include "ChatProtocol.h"
#include <QIODevice>
#include <QDataStream>

ChatProtocol::ChatProtocol() {}

QByteArray ChatProtocol::textMessage(QString message)
{
    return getData(Text, message);
}

QByteArray ChatProtocol::isTypingMessage()
{
    return getData(IsTyping, "");
}
QByteArray ChatProtocol::setNameMessage(QString name)
{
    return getData(SetName, name);
}
QByteArray ChatProtocol::setStatusMessage(Status status)
{
    QByteArray ba;
    QDataStream out(&ba, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out<< SetStatus << status;
    return ba;
}

QByteArray ChatProtocol::getData(MessageType type, QString data)
{
    QByteArray ba;
    QDataStream out(&ba, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out<< type << data;
    return ba;
}