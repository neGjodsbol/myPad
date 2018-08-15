#ifndef MPMUSEPAD_H
#define MPMUSEPAD_H

#include <QMainWindow>
#include <QtWidgets>
#include <string>
#include "mpsizing.h"
#include "mpkeyboard.h"
#include "mpvoices.h"
#include "mptoolbutton.h"
#include "mppalettebox.h"
#include "toolbuttonmenu.h"
#include "shortcut.h"
#include "globals.h"
#include "../libmscore/musescoreCore.h"
#include "../all.h"

namespace Ui {
class MusePad;
class Shortcut;
}

enum LayoutMode {
      PAGE = 0,
      LINE   = 1 << 0,
      SYSTEM  = 1 << 1
      };


class MusePad : public QMainWindow, public MuseScoreCore
{
    Q_OBJECT

public:
    explicit MusePad(QWidget *parent = 0);
    ~MusePad();
    void genIcons();
    QAction* getAction(const char* id);

private slots:
    void mpCmd (const char *);
    void mpCmd (QString, QString);
    void mpCmd (QAction *);
//    void mpShowPalette (QAction *);

    void cmd (QAction *);

    void mpSetVoiceIcon(int);

    void helpBrowser1() const;
    void tutorial () const;
    void about();
    void aboutQt();
    void aboutMusicXML();
    void reportBug();
    void switchLayoutMode (int);

signals:
//    QAction mpAction (QAction *);
//    QAction mpSetPalette (QAction *, bool);

private:
    Ui::MusePad *ui;
    Ui::MpSizing *env;
    Ms::Shortcut *shortcut;
    MpKeyboard *mpKeyboard;
    MpVoices *voices;
    MpVoices *mpVoiceBox;
    MpPaletteBox *paletteBox;

    QDockWidget *mpKeyboardPanel;
    QDockWidget *palettePanel;
    QToolBar *mpMainTools;
    QToolBar *mpPlayTools;
    QToolBar *paletteOneTools;
    QToolBar *paletteTwoTools;

    QToolButton *mpFileButton;
    QToolButton *mpMagButton;
    QToolButton *mpSettingsButton;
    QToolButton *mpEditButton;
    QToolButton *mpScoreButton;

    Ms::ToolButtonMenu *mpNoteInputButton;
    QMenu *mpFileMenu;
    QMenu *mpMagMenu;
    QMenu *mpSettingsMenu;
    QMenu *mpEditMenu;
    QMenu *mpScoreMenu;

    QMenu *mpTupletsMenu;
    QMenu *mpAddTextMenu;
    QMenu *mpHelpMenu;

    void mpInit();
    void mpPrepareToolbars ();
    void mpShowPalette(QAction* a);
    QAction* mpGetAction (const char* id);
    int  getVoice ();
    void showMessage(const QString& s, int timeout);

    QComboBox *viewModeCombo;

    QAction *repeatAction;
    QAction *panAction;
    QAction *metronomeAction;
    QAction *mpVoiceAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
    QAction *aboutMusicXMLAction;
    QAction *tutorialAction;
    QAction *reportBugAction;

    QString currentPalette;
    QAction *mpPaletteAction;
    int  m_voiceSet;
};

#endif // MPMUSEPAD_H
