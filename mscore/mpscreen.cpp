#include "mpscreen.h"

MpScreen::MpScreen(int x, int y, int w, int h)
{
    setX(x);
    setY(y);
    setWidth(w);
    setHeight(h);
}
MpScreen::MpScreen(QRect *r)
{
    setX(r->x());
    setY(r->y());
    setWidth(r->width());
    setHeight(r->height());
}
