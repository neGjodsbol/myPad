#include "mpsizing.h"


Ui::MpSizing::MpSizing(QWidget *parent)
{
// Parametrene skal hentes fra omgivende miljø.
    m_screenHeight = 500;
    m_screenWidth = 300;
    m_screenIsPortrait = true ;
//
    if (m_screenIsPortrait){
        parent->setFixedHeight(m_screenHeight);
        parent->setFixedWidth(m_screenWidth);
    }
    else {
        parent->setFixedHeight(m_screenWidth);
        parent->setFixedWidth(m_screenHeight);
    }
}
Ui::MpSizing::~MpSizing()
{}

int Ui::MpSizing::getHeight()
{
    return (m_screenHeight);
}
int Ui::MpSizing::getWidth()
{
    return (m_screenWidth);
}
bool Ui::MpSizing::isPortrait()
{
    return (m_screenIsPortrait);
}
