#ifndef MPSETTINGS_H
#define MPSETTINGS_H

#include <QDialog>

namespace Ui {
class MpSettings;
}

class MpSettings : public QDialog
{
    Q_OBJECT

public:
    explicit MpSettings(QWidget *parent = nullptr);
    ~MpSettings();

private slots:
    void on_smallPButton_clicked(bool checked);
    void on_mediumPButton_clicked(bool checked);
    void on_mediumLButton_clicked(bool checked);

signals:
    void setBaseSize (QRect *);

private:
    Ui::MpSettings *ui;
    void accept();
    int baseX;
    int baseY;
    int baseWidth;
    int baseHeight;
};

#endif // MPSETTINGS_H
