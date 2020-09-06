/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Layout;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QString::fromUtf8("Config"));
        Config->resize(400, 300);
        verticalLayoutWidget = new QWidget(Config);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 291, 111));
        Layout = new QVBoxLayout(verticalLayoutWidget);
        Layout->setObjectName(QString::fromUtf8("Layout"));
        Layout->setContentsMargins(0, 0, 0, 0);
        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        Layout->addWidget(buttonBox);


        retranslateUi(Config);

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QWidget *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
