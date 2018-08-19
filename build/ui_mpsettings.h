/********************************************************************************
** Form generated from reading UI file 'mpsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MPSETTINGS_H
#define UI_MPSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MpSettings
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QRadioButton *smallPButton;
    QRadioButton *mediumPButton;
    QLabel *label_2;
    QRadioButton *mediumLButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *MpSettings)
    {
        if (MpSettings->objectName().isEmpty())
            MpSettings->setObjectName(QStringLiteral("MpSettings"));
        MpSettings->resize(219, 168);
        verticalLayoutWidget_2 = new QWidget(MpSettings);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 201, 151));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        smallPButton = new QRadioButton(verticalLayoutWidget_2);
        smallPButton->setObjectName(QStringLiteral("smallPButton"));
        smallPButton->setChecked(true);

        verticalLayout->addWidget(smallPButton);

        mediumPButton = new QRadioButton(verticalLayoutWidget_2);
        mediumPButton->setObjectName(QStringLiteral("mediumPButton"));

        verticalLayout->addWidget(mediumPButton);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        mediumLButton = new QRadioButton(verticalLayoutWidget_2);
        mediumLButton->setObjectName(QStringLiteral("mediumLButton"));

        verticalLayout->addWidget(mediumLButton);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(verticalLayoutWidget_2);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(verticalLayoutWidget_2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(MpSettings);
        QObject::connect(okButton, SIGNAL(clicked()), MpSettings, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), MpSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(MpSettings);
    } // setupUi

    void retranslateUi(QDialog *MpSettings)
    {
        MpSettings->setWindowTitle(QApplication::translate("MpSettings", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("MpSettings", "Portrait mode", Q_NULLPTR));
        smallPButton->setText(QApplication::translate("MpSettings", "Small", Q_NULLPTR));
        mediumPButton->setText(QApplication::translate("MpSettings", "Medium", Q_NULLPTR));
        label_2->setText(QApplication::translate("MpSettings", "Landscape mode", Q_NULLPTR));
        mediumLButton->setText(QApplication::translate("MpSettings", "Medium", Q_NULLPTR));
        okButton->setText(QApplication::translate("MpSettings", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("MpSettings", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MpSettings: public Ui_MpSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MPSETTINGS_H
