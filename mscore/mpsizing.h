#ifndef MPSIZING_H
#define MPSIZING_H

#include <QWidget>

namespace Ui {
class MpSizing;
}

class Ui::MpSizing
{
public:
    MpSizing (QWidget *parent);
        ~MpSizing();
    int getHeight ();
    int getWidth ();
    bool isPortrait ();
private:
    int m_screenHeight;
    int m_screenWidth;
    bool m_screenIsPortrait;
};

#endif // MPSIZING_H
