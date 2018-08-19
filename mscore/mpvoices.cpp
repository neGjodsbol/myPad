#include "mpvoices.h"
#include "ui_mpvoices.h"

MpVoices::MpVoices(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MpVoices)
{
    ui->setupUi(this);
    resetButtons();
    setButtons(1);
    this->setWindowFlag(Qt::FramelessWindowHint);
}

MpVoices::~MpVoices()
{
    delete ui;
}

void MpVoices::setButtons(int currentVoice)
{
    switch (currentVoice) {
    case 1:
        ui->voice1Button->setDisabled(true);
        ui->voice1Button->setFlat(true);
        break;
    case 2:
        ui->voice2Button->setDisabled(true);
        ui->voice2Button->setFlat(true);
        break;
    case 3:
        ui->voice3Button->setDisabled(true);
        ui->voice3Button->setFlat(true);
        break;
    case 4:
        ui->voice4Button->setDisabled(true);
        ui->voice4Button->setFlat(true);
        break;
    default:
        break;
    }
}

void MpVoices::resetButtons()
{
    ui->voice1Button->setDisabled(false);
    ui->voice1Button->setFlat(false);
    ui->voice2Button->setDisabled(false);
    ui->voice2Button->setFlat(false);
    ui->voice3Button->setDisabled(false);
    ui->voice3Button->setFlat(false);
    ui->voice4Button->setDisabled(false);
    ui->voice4Button->setFlat(false);
}

void MpVoices::on_voice1Button_clicked()
{
    resetButtons();
    setButtons(1);
    m_voiceSet = 1;
    emit voiceChanged(m_voiceSet);
}

void MpVoices::on_voice2Button_clicked()
{
    resetButtons();
    setButtons(2);
    m_voiceSet = 2;
    emit voiceChanged(m_voiceSet);
}

void MpVoices::on_voice3Button_clicked()
{
    resetButtons();
    setButtons(3);
    m_voiceSet = 3;
    emit voiceChanged(m_voiceSet);
}

void MpVoices::on_voice4Button_clicked()
{
    resetButtons();
    setButtons(4);
    m_voiceSet = 4;
    emit voiceChanged(m_voiceSet);
}
