#include "mpmusepad.h"
#include "ui_mpmusepad.h"
#include "shortcut.h"
#include "icons.h"
#include <QApplication>
#include <QWidget>

MusePad::MusePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MusePad)
{
    ui->setupUi(this);

    QActionGroup* ag = Ms::Shortcut::getActionGroupForWidget(Ms::MsWidget::MAIN_WINDOW);
    ag->setParent(this);
    addActions(ag->actions());
    connect(ag, SIGNAL(triggered(QAction*)), SLOT(cmd(QAction*)));

    mpInit ();

}

MusePad::~MusePad()
{
    delete ui;
}

void MusePad::mpInit ()
{
    env = new Ui::MpSizing (this);
    this->setIconSize(QSize(19,19));

    setCentralWidget(ui->scoreEdit);
    shortcut = new Ms::Shortcut ();
    shortcut->init();

    Ms::genIcons();

    mpPrepareToolbars();

    mpPaletteAction = new QAction(); //Hold info on last used palette.

    mpKeyboardPanel = new QDockWidget (this);
    mpKeyboardPanel->setAllowedAreas(Qt::BottomDockWidgetArea);
    mpKeyboard = new MpKeyboard (mpKeyboardPanel);
    mpKeyboardPanel->setWidget(mpKeyboard);
    addDockWidget(Qt::BottomDockWidgetArea, mpKeyboardPanel);

    mpVoiceBox = new MpVoices (this);
    mpVoiceBox->setVisible(false);

    connect (mpVoiceBox, SIGNAL(voiceChanged(int)),mpKeyboard,SLOT(setVoice(int)));
    connect (mpKeyboard, SIGNAL (keyAction(const char *)), SLOT (mpCmd(const char *)));

// Set Tablet defaults

      mpKeyboardPanel->setVisible(true);
      mpPlayTools->setVisible(false);
      paletteOneTools->setVisible(false);
      paletteTwoTools->setVisible(false);

      palettePanel = new QDockWidget ("Palttes",this);
      palettePanel->setAllowedAreas(Qt::LeftDockWidgetArea);
      paletteBox = new MpPaletteBox (palettePanel);
      palettePanel->setWidget(paletteBox);
      addDockWidget(Qt::LeftDockWidgetArea, palettePanel);
      palettePanel->setVisible(false);
/*

    mpPlayTools->setVisible(false);


    currentPalette = "";
    connect (this, SIGNAL (mpSetPalette (QAction *)),paletteBox, SLOT (mpSetPalette (QAction *)));

    voicePanel = new QDockWidget ("Voices",this);
    voicePanel->setAllowedAreas(Qt::RightDockWidgetArea);
    voices = new MpVoices (voicePanel);
    voicePanel->setWidget(voices);
    addDockWidget(Qt::RightDockWidgetArea, voicePanel);
    voicePanel->setVisible(false);
    m_voiceSet = 1;
    mpSetVoiceIcon(m_voiceSet);
    connect(voices, SIGNAL (voiceChanged (int)), SLOT (mpSetVoiceIcon(int)));
    scorePanel = new QDockWidget ("Score",this);
    scorePanel->setAllowedAreas(Qt::RightDockWidgetArea);
    score = new MpScoreSettings (scorePanel);
    scorePanel->setWidget(score);
    addDockWidget(Qt::RightDockWidgetArea, scorePanel);
    scorePanel->setVisible(false);
    settingsPanel = new QDockWidget ("Settings",this);
    settingsPanel->setAllowedAreas(Qt::LeftDockWidgetArea);
    settings= new MpSettings (settingsPanel);
    settingsPanel->setWidget(settings);
    addDockWidget(Qt::LeftDockWidgetArea, settingsPanel);
    settingsPanel->setVisible(false);

    connect (settings, SIGNAL (mpGuiAction(QString, QString)), SLOT (mpCmd(QString, QString)));
    connect (settings, SIGNAL (mpAction(const char *)), SLOT (mpCmd(const char *)));
    connect (settings, SIGNAL (mpLayoutMode(int)), SLOT (switchLayoutMode(int)));

    keyboardPanel = new QDockWidget (this);
    keyboardPanel->setAllowedAreas(Qt::BottomDockWidgetArea);
    key = new MpKeyboard (keyboardPanel);
    keyboardPanel->setWidget(key);
    addDockWidget(Qt::BottomDockWidgetArea, keyboardPanel);
    keyboardPanel->setVisible(true);
    connect (key, SIGNAL (keyAction(QAction *)), SLOT(cmd(QAction *)));
    connect (key, SIGNAL (keyAction(const char *)), SLOT (mpCmd(const char *)));
    connect (key, SIGNAL (keyAction(QString, QString)), SLOT (mpCmd(QString, QString)));

*/
}

// ----------------------------------------------------
// TABLET functions
// ----------------------------------------------------
void MusePad::mpPrepareToolbars ()
{

// -----------------------------------------
// Action Groups - Note Entry and View mode
//------------------------------------------
    QActionGroup* noteEntryMethods = new QActionGroup(this);
    noteEntryMethods->addAction(getAction("note-input-steptime"));
    noteEntryMethods->addAction(getAction("note-input-repitch"));
    noteEntryMethods->addAction(getAction("note-input-rhythm"));
    for (QAction* a : noteEntryMethods->actions()) {
         a->setCheckable(true);
         a->setIconVisibleInMenu(true);
         }
    getAction("note-input-steptime")->setChecked(true);

//(Not used!)    connect(noteEntryMethods, SIGNAL(triggered(QAction*)), this, SLOT(cmd(QAction*)));

    QActionGroup* viewModes = new QActionGroup(this);
    viewModes->addAction(getAction("viewmode-page"));
    viewModes->addAction(getAction("viewmode-horizontal"));
    viewModes->addAction(getAction("viewmode-vertical"));
    getAction("viewmode-page")->setChecked(true);
    connect(viewModes, SIGNAL(triggered(QAction*)), this, SLOT(mpCmd(QAction*)));

// ---------------------------------------------------
// Action Group - Tablet GUI actions
// ---------------------------------------------------

      QActionGroup* tabletGui = Ms::Shortcut::getActionGroupForWidget(Ms::MsWidget::TABLET_GUI);
      tabletGui->setParent(this);
      addActions(tabletGui->actions());
      connect(tabletGui, SIGNAL(triggered(QAction*)), SLOT(mpCmd(QAction*)));

//  ---------------------------------------------------
//  Main toolbar - Setings, File, and Zoom actions
//  ---------------------------------------------------

    addToolBarBreak();
    mpMainTools= addToolBar("");
    mpMainTools->setMovable(false);

    mpSettingsButton = new MpToolButton(mpMainTools, getAction("settings-menu"));
    mpMainTools->addWidget(mpSettingsButton);

    mpMainTools->addAction(getAction("logo"));

    mpNoteInputButton = new Ms::ToolButtonMenu(tr("Note Entry Methods"),
       Ms::ToolButtonMenu::TYPES::ICON_CHANGED,
       getAction("note-input"),
       noteEntryMethods,
       mpMainTools);
    mpMainTools->addWidget(mpNoteInputButton);

    mpMainTools->addWidget(new MpToolButton(mpMainTools,mpGetAction("")));

    mpMagButton = new MpToolButton(mpMainTools, getAction("zoom-menu"));
    mpMainTools->addWidget(mpMagButton);

    mpMainTools->addAction (getAction("toggle-playback"));

    mpMainTools->addWidget(new MpToolButton(mpMainTools,mpGetAction("")));

    mpFileButton = new MpToolButton(mpMainTools, getAction("file-menu"));
    mpMainTools->addWidget(mpFileButton);

    mpEditButton =new MpToolButton(mpMainTools, getAction("edit-menu"));
    mpMainTools->addWidget(mpEditButton);

    mpMainTools->addAction (getAction("toggle-palette-tools"));

    mpScoreButton =new MpToolButton(mpMainTools, getAction("score-menu"));
    mpMainTools->addWidget(mpScoreButton);

//  ----------------------------------------------------
//  Playback tools
//  ----------------------------------------------------

    mpPlayTools = new QToolBar();
    mpPlayTools->setAllowedAreas(Qt::BottomToolBarArea);
    mpPlayTools->setMovable(false);
    addToolBar(Qt::BottomToolBarArea, mpPlayTools);
    mpPlayTools->setObjectName("playback-tools");

    mpPlayTools->addAction(getAction("rewind"));
    mpPlayTools->addAction(getAction("play"));
    mpPlayTools->addAction(getAction("repeat"));
    mpPlayTools->addAction(getAction("pan"));
    mpPlayTools->addAction(getAction("metronome"));
    mpPlayTools->addAction(getAction("toggle-mixer"));

    getAction("repeat")->setChecked(true);
    getAction("pan")->setChecked(true);

    connect(mpMainTools,SIGNAL(actionTriggered (QAction*)),SLOT (mpCmd(QAction*)));
    connect(mpPlayTools,SIGNAL(actionTriggered (QAction*)),SLOT (mpCmd(QAction*)));

//  -----------------------------------------------------
//  Palette toolbars
//  -----------------------------------------------------

    addToolBarBreak();

    paletteOneTools = addToolBar("");
    paletteOneTools->addAction(getAction("palette-clefs"));
    paletteOneTools->addAction(getAction("palette-keysignatures"));
    paletteOneTools->addAction(getAction("palette-timesignatures"));
    paletteOneTools->addAction(getAction("palette-accidentals"));
    paletteOneTools->addAction(getAction("palette-articulations"));
    paletteOneTools->addAction(getAction("palette-gracenotes"));
    paletteOneTools->addAction(getAction("palette-lines"));

    paletteOneTools->setVisible(false);
    paletteOneTools->setMovable(false);

    paletteTwoTools = addToolBar("");
    paletteTwoTools->addAction(getAction("palette-barlines"));
    paletteTwoTools->addAction(getAction("palette-texts"));
    paletteTwoTools->addAction(getAction("palette-tempi"));
    paletteTwoTools->addAction(getAction("palette-dynamics"));
    paletteTwoTools->addAction(getAction("palette-endings"));
    paletteTwoTools->addAction(getAction("palette-jumps"));
    paletteTwoTools->addAction(getAction("palette-beams"));

    paletteTwoTools->setVisible(false);
    paletteTwoTools->setMovable(false);

    connect (paletteOneTools, SIGNAL(triggerd(QAction*)),SLOT(mpCmd(QAction*)));
    connect (paletteTwoTools, SIGNAL(triggerd(QAction*)),SLOT(mpCmd(QAction*)));

//  ---------------------------------------------
//  Pop-up menus
//  ---------------------------------------------

    mpFileMenu = new QMenu();
    mpFileButton->setMenu(mpFileMenu);
    mpFileMenu->addAction (getAction("file-open"));
    mpFileMenu->addAction (getAction("file-save"));
    mpFileMenu->addAction (getAction("file-save-as"));
    mpFileMenu->addAction (getAction("file-close"));
    mpFileMenu->addSeparator();
    mpFileMenu->addAction (getAction("file-new"));
    connect(mpFileMenu, SIGNAL(triggered(QAction*)),SLOT (mpCmd(QAction*)));

    mpMagMenu = new QMenu();
    mpMagButton->setMenu(mpMagMenu);
    mpMagMenu->addAction(getAction("zoomin"));
    mpMagMenu->addAction(getAction("zoomout"));
    mpMagMenu->addAction(getAction("zoom100"));
    connect(mpMagMenu, SIGNAL(triggered(QAction*)),SLOT (mpCmd(QAction*)));

    mpEditMenu = new QMenu;
    mpEditButton->setMenu(mpEditMenu);
    mpEditMenu->addAction(getAction("undo"));
    mpEditMenu->addAction(getAction("redo"));
    mpEditMenu->addAction(getAction("cut"));
    mpEditMenu->addAction(getAction("copy"));
    mpEditMenu->addAction(getAction("paste"));
    connect(mpEditMenu, SIGNAL(triggered(QAction*)),SLOT (mpCmd(QAction*)));

    mpTupletsMenu = new QMenu();
    mpTupletsMenu->addAction(getAction("duplet"));
    mpTupletsMenu->addAction(getAction("triplet"));
    mpTupletsMenu->addAction(getAction("quadruplet"));
    mpTupletsMenu->addAction(getAction("quintuplet"));
    mpTupletsMenu->addAction(getAction("sextuplet"));
    mpTupletsMenu->addAction(getAction("septuplet"));
    mpTupletsMenu->addAction(getAction("octuplet"));
    mpTupletsMenu->addAction(getAction("nonuplet"));
    connect(mpTupletsMenu,SIGNAL(triggered (QAction*)),SLOT (mpCmd(QAction*)));

    mpAddTextMenu = new QMenu();
    mpAddTextMenu->addAction(getAction("title-text"));
    mpAddTextMenu->addAction(getAction("subtitle-text"));
    mpAddTextMenu->addAction(getAction("composer-text"));
    mpAddTextMenu->addAction(getAction("poet-text"));
    mpAddTextMenu->addAction(getAction("part-text"));
    connect(mpAddTextMenu,SIGNAL(triggered (QAction*)),SLOT (mpCmd(QAction*)));

    mpHelpMenu = new QMenu();
    aboutAction = new QAction(tr("About..."), nullptr);

    aboutAction->setMenuRole(QAction::AboutRole);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    mpHelpMenu->addAction(aboutAction);

    aboutQtAction = new QAction(tr("About Qt..."), nullptr);
    aboutQtAction->setMenuRole(QAction::AboutQtRole);
    connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));
    mpHelpMenu->addAction(aboutQtAction);

    aboutMusicXMLAction = new QAction(tr("About MusicXML..."), nullptr);
    aboutMusicXMLAction->setMenuRole(QAction::ApplicationSpecificRole);
    connect(aboutMusicXMLAction, SIGNAL(triggered()), this, SLOT(aboutMusicXML()));
    mpHelpMenu->addAction(aboutMusicXMLAction);

    mpHelpMenu->addSeparator();
    tutorialAction = mpHelpMenu->addAction(tr("Tutorial"), this, SLOT(tutorial()));
    reportBugAction = mpHelpMenu->addAction(tr("Report a bug"), this, SLOT(reportBug()));
//    connect(mpHelpMenu,SIGNAL(triggered (QAction*)),SLOT (mpCmd(QAction*)));

    mpSettingsMenu = new QMenu();
    mpSettingsButton->setMenu(mpSettingsMenu);
    mpSettingsMenu->addAction(getAction("file-export"));
    mpSettingsMenu->addSeparator();
    mpSettingsMenu->addAction(getAction("settings-dialog"));
    mpSettingsMenu->addSeparator();
    QAction* helpMenu = getAction("help-menu");
    helpMenu->setMenu(mpHelpMenu);
    mpSettingsMenu->addAction(helpMenu);
    mpSettingsMenu->addSeparator();
    mpSettingsMenu->addAction(getAction("exit"));
    connect(mpSettingsMenu, SIGNAL(triggered(QAction*)),SLOT (mpCmd(QAction*)));

    mpScoreMenu = new QMenu;
    mpScoreButton->setMenu(mpScoreMenu);
    mpScoreMenu->addAction(new QAction(tr("Note Input"), mpScoreMenu));
    mpScoreMenu->addActions(noteEntryMethods->actions());
    mpScoreMenu->addSeparator();
    mpScoreMenu->addAction(new QAction(tr("Scroll mode"), mpScoreMenu));
    mpScoreMenu->addActions(viewModes->actions());
    mpScoreMenu->addSeparator();
    mpScoreMenu->addAction(getAction("toggle-concertpitch"));
        getAction("toggle-concertpitch")->setCheckable(true);
        getAction("toggle-concertpitch")->setChecked(false);
    mpScoreMenu->addAction(getAction("instruments"));
    QAction* scoreInfo = getAction("info-menu");
    scoreInfo->setMenu(mpAddTextMenu);
    mpScoreMenu->addAction(scoreInfo);
    connect(mpScoreMenu,SIGNAL(triggered (QAction*)),SLOT (mpCmd(QAction*)));
}


void MusePad::mpSetVoiceIcon(int voice)
{
    static QString vtxt[4];
    QString s;

    m_voiceSet = voice;
}

int MusePad::getVoice ()
{
    return m_voiceSet;
}

QAction* MusePad::getAction(const char* id)
{
    Ms::Shortcut* s = Ms::Shortcut::getShortcut(id);
    return s ? s->action() : nullptr;
}

QAction* MusePad::mpGetAction (const char* id)
{
    QAction *a = new QAction ();
    a->setData(QByteArray(id));
    a->setIconVisibleInMenu(false);
    QString cmdn = a->data().toString();
    QString path = "icons/" + cmdn + ".png";

    if (cmdn == "file-open")
    {
        a->setText("Open");
    }
    else if (cmdn == "open-entrytools")
        a->setIcon(QIcon(path));
    else if (cmdn == "close-entrytools")
        a->setIcon(QIcon(path));
    else if (cmdn == "open-voices")
        a->setIcon(QIcon(path));
    else if (cmdn == "accidentals")
        a->setText("Accidentls");
    else if (cmdn == "clefs")
        a->setText("Clefs");
    else if (cmdn == "timensignatures")
        a->setText("Timesignatures");
    else if (cmdn == "keysignatures")
        a->setText("Keysignatures");
    else if (cmdn == "gracenotes")
        a->setText("Gracenotes");
//    else if (cmdn == "clefs")
//        a->setText("Clefs");
    else
        a->setText(id);
        a->setIcon(QIcon(path));
    return a;
}

void MusePad::mpCmd (const char *cmdn)
{
#ifndef TABGUI
    getAction(cmdn)->trigger();
#else
    cmd(getAction(cmdn));
#endif
}
void MusePad::mpCmd (QString modifier, QString key)
{
    if (modifier == "gui")
    {
        QPoint p = this->pos();
        p.setX(p.x()+50);
        p.setY(p.y()+75);
        if (key == "score-info")
        {
           mpAddTextMenu->popup(p);
        }
        else if (key == "help-menu")
        {
//            mpHelpMenu->popup(p);
        }
        else if (key == "tuplet-menu")
        {
            mpTupletsMenu->popup(QPoint (p));
        }
    }
    ui->scoreEdit->setText(modifier + " " + key);
}
void MusePad::mpCmd (QAction *a)
    {
    QString cmdn = (a->data().toString());

    if (cmdn == "tuplets-menu")
          {
          QPoint p = this->pos();
          p.setX(p.x()+50);
          p.setY(p.y()+75);
          mpTupletsMenu->popup(QPoint (p));
          }
    else if (cmdn == "toggle-voices")
        {
            if (mpVoiceBox->isVisible()) {
            mpVoiceBox->setVisible(false);
                }
            else {
            mpVoiceBox->setVisible(true);
            }
        }
    else if (cmdn == "toggle-playback")
          {
          if (getAction("toggle-playback")->isChecked())
                mpPlayTools->setVisible(true);
          else
                mpPlayTools->setVisible(false);

          if (mpPlayTools->isVisible())
                mpKeyboardPanel->setVisible(false);
          else
                mpKeyboardPanel->setVisible(true);
          }
    else if (cmdn == "toggle-palette-tools")
          {
          if (paletteOneTools->isVisible())
                {
                paletteBox->setVisible(false);
                paletteOneTools->setVisible(false);
                paletteTwoTools->setVisible(true);
                mpPaletteAction->setChecked(false);
                }
          else if (paletteTwoTools->isVisible())
                {
                paletteBox->setVisible(false);
                paletteTwoTools->setVisible(false);
                }
          else
                {
                paletteOneTools->setVisible(true);
                }
          }
    else if (cmdn.startsWith("palette-"))
          {
          mpShowPalette(a);
          }
    else if (cmdn == "viewmode-page")
          {
          emit (switchLayoutMode(LayoutMode::PAGE));
          }
    else if (cmdn == "viewmode-horizontal")
          {
          emit (switchLayoutMode(::LINE));
          }
    else if (cmdn == "viewmode-vertical")
          {
          emit (switchLayoutMode(LayoutMode::SYSTEM));
          }
    else
#ifdef TABGUI
        cmd(a);
#endif
    return;
    }
void MusePad::cmd (QAction *a)
{
    QString cmdn = (a->data().toString());
    if (cmdn == "null")
        cmdn = a->text();
    ui->scoreEdit->setText(cmdn);
}
void MusePad::mpShowPalette(QAction* a)
      {
      QString s = a->data().toString();
#ifdef TABGUI
      ui->scoreEdit->setText(s);
#else
      if (!mpPaletteAction) {
                  paletteBox->mpSetPalette(a, true);
                  paletteBox->setVisible(true);
                  mpPaletteAction = a;
                  }
            else if (mpPaletteAction == a) {
                  paletteBox->mpSetPalette(a, false);
                  paletteBox->setVisible(false);
                  mpPaletteAction = nullptr;
                  }
            else  {
                  paletteBox->mpSetPalette(mpPaletteAction, false);
                  mpPaletteAction->setChecked(false);
                  mpPaletteAction = a;
                  paletteBox->mpSetPalette(a, true);
                  paletteBox->setVisible(true);
                  }
#endif
      }

void MusePad::showMessage(const QString& s, int timeout)
      {
        ui->scoreEdit->setText(s);
      }
// --------------------------------------------------
//  Help Actions
// --------------------------------------------------

void MusePad::helpBrowser1() const{
    ui->scoreEdit->setText("Online help request");
}
void MusePad::tutorial() const{
    ui->scoreEdit->setText("Show tutorial");
}
void MusePad::about(){
    ui->scoreEdit->setText("About MusePad");
}
void MusePad::aboutQt(){
    ui->scoreEdit->setText("AboutQt");
}
void MusePad::aboutMusicXML(){
    ui->scoreEdit->setText("About Music XML");
}
void MusePad::reportBug(){
    ui->scoreEdit->setText("report bug");
}
void MusePad::switchLayoutMode(int mode){
    if (mode == 0)
    ui->scoreEdit->setText("layoyt mode 0");
    else if (mode == 1)
    ui->scoreEdit->setText("layoyt mode 1");
    else if (mode == 2)
    ui->scoreEdit->setText("layoyt mode 2");
    else
    ui->scoreEdit->setText("layoyt mode undef");
}


