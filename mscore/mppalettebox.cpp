#include "mppalettebox.h"
#include "ui_mppalettebox.h"
#include "palette.h"
#include <QPushButton>
#include <QMessageBox>

MpPaletteBox::MpPaletteBox(QWidget* parent)
   : QDockWidget(tr("Palettes"), parent)
{
    setObjectName("palette-box");
    setAllowedAreas(Qt::LeftDockWidgetArea);
    QWidget* w = new QWidget(this);
    w->setContextMenuPolicy(Qt::NoContextMenu);
    QVBoxLayout* vbox = new QVBoxLayout(w);
    vbox->setMargin(0);
    setWidget(w);
}

MpPaletteBox::~MpPaletteBox()
{
//    delete ui;
}

void MpPaletteBox::mpAddPalette(Ms::Palette* p, QString label)
{
/*    PaletteItem *pi = new PaletteItem();
    pi->label = label;
    pi->palette = p;
    paletteList.append(pi);
*/
}

void MpPaletteBox::mpSetPalette(QAction* a, bool visible)
    {

    QString s = a->data().toString();
/*
    for (int i=0;i<paletteList.size();i++){
        if(s==paletteList[i]->label){
            Ms::Palette* p = paletteList[i]->palette;

            psa->setWidget(p); When we have a palette
            psa->setWidget(b);
            this->setVisible(true);
            psa->setVisible(true);
            break;
        }
*/
            QPushButton* b = new QPushButton (s);
            vbox->addWidget(b);
    }

