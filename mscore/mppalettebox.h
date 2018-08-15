#ifndef MPPALETTEBOX_H
#define MPPALETTEBOX_H

#include <QWidget>
#include "palette.h"
#include <QDockWidget>
#include <QVBoxLayout>

namespace Ui {
class MpPaletteBox;
class Palette;
}

class MpPaletteBox : public QDockWidget {
    Q_OBJECT
     QVBoxLayout* vbox;

public:
    MpPaletteBox(QWidget *parent = nullptr );
    ~MpPaletteBox();

    void mpSetPalette(QAction*, bool);
    void mpAddPalette(Ms::Palette* p, QString label);

private:

    struct PaletteItem {
          ~PaletteItem();
        QString label;           // used as index
        Ms::Palette* palette;
        };
    QList<PaletteItem*> paletteList;
};

#endif // MPPALETTEBOX_H
