/********************************************************************************
** Form generated from reading UI file 'ChatItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATITEMWIDGET_H
#define UI_CHATITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatItemWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblMessage;
    QLabel *lblTime;

    void setupUi(QWidget *ChatItemWidget)
    {
        if (ChatItemWidget->objectName().isEmpty())
            ChatItemWidget->setObjectName(QString::fromUtf8("ChatItemWidget"));
        ChatItemWidget->resize(234, 94);
        verticalLayout = new QVBoxLayout(ChatItemWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblMessage = new QLabel(ChatItemWidget);
        lblMessage->setObjectName(QString::fromUtf8("lblMessage"));

        verticalLayout->addWidget(lblMessage);

        lblTime = new QLabel(ChatItemWidget);
        lblTime->setObjectName(QString::fromUtf8("lblTime"));

        verticalLayout->addWidget(lblTime, 0, Qt::AlignmentFlag::AlignRight);


        retranslateUi(ChatItemWidget);

        QMetaObject::connectSlotsByName(ChatItemWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatItemWidget)
    {
        ChatItemWidget->setWindowTitle(QCoreApplication::translate("ChatItemWidget", "Form", nullptr));
        lblMessage->setText(QCoreApplication::translate("ChatItemWidget", "Message", nullptr));
        lblTime->setText(QCoreApplication::translate("ChatItemWidget", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatItemWidget: public Ui_ChatItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATITEMWIDGET_H
