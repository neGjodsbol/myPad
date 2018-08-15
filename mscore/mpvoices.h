#ifndef MPVOICES_H
#define MPVOICES_H

#include <QWidget>

namespace Ui {
class MpVoices;
}

class MpVoices : public QWidget
{
    Q_OBJECT

public:
    explicit MpVoices(QWidget *parent = nullptr);
    ~MpVoices();

private slots:
    void on_voice1Button_clicked();

    void on_voice2Button_clicked();

    void on_voice3Button_clicked();

    void on_voice4Button_clicked();

signals:
    void voiceChanged (int);

private:
    Ui::MpVoices *ui;
    void setButtons(int);
    void resetButtons();
    int m_voiceSet;
};

#endif // MPVOICES_H
