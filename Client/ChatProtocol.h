#ifndef CHATPROTOCOL_H
#define CHATPROTOCOL_H
#include <QString>
#include <QByteArray>

class ChatProtocol
{
public:
    enum MessageType {
        Text,
        File,
        IsTyping,
        SetName,
        SetStatus
    };
    enum Status {
        None,
        Available,
        Away,
        Busy
    };

    ChatProtocol();
    QByteArray textMessage(QString message);
    QByteArray isTypingMessage();
    QByteArray setNameMessage(QString name);
    QByteArray setStatusMessage(Status status);

    void loadData(QByteArray data);
private:
    QByteArray getData(MessageType type, QString data);
    MessageType _type;
};

#endif // CHATPROTOCOL_H
