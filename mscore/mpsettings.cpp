#include "mpsettings.h"
#include "ui_mpsettings.h"

MpSettings::MpSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MpSettings)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);

    on_smallPButton_clicked(true);
}

MpSettings::~MpSettings()
    {
    delete ui;
    }
void MpSettings::accept()
      {
      emit setBaseSize(new QRect (baseX, baseY, baseWidth, baseHeight ));
      done(1);
      }

void MpSettings::on_smallPButton_clicked(bool checked)
{
    if (checked)
        {
        baseX = 50;
        baseY = 100;
        baseWidth = 290;
        baseHeight = 460;
        }
}

void MpSettings::on_mediumPButton_clicked(bool checked)
{
    if (checked)
       {
        baseX = 50;
        baseY = 50;
        baseWidth = 560;
        baseHeight = 900;
        }
}

void MpSettings::on_mediumLButton_clicked(bool checked)
{
    if (checked)
       {
        baseX = 50;
        baseY = 50;
        baseWidth = 900;
        baseHeight = 560;
        }
}
