#ifndef MPSCREEN_H
#define MPSCREEN_H

#include <QObject>
#include <QRect>

class MpScreen : public QRect
{
public:
    MpScreen(int, int, int, int);
    MpScreen(QRect *);
};

#endif // MPSCREEN_H
