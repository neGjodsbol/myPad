#ifndef MUSESCORECORE_H
#define MUSESCORECORE_H
#include "mptablet.h"

namespace Ui {
class MuseScoreCore;
}
class MuseScoreCore
{
protected:
#ifndef TABGUI
    Score* cs  { 0 };              // current score
    QList<Score*> scoreList;
#endif
public:
static MuseScoreCore* mscoreCore;
//      MuseScoreCore()                    { mscoreCore = this; }
    MuseScoreCore();

#ifndef TABGUI//


      Score* currentScore() const        { return cs;     }
      void setCurrentScore(Score* score) { cs = score;    }

      virtual bool saveAs(Score*, bool /*saveCopy*/, const QString& /*path*/, const QString& /*ext*/) { return false; }
      virtual void closeScore(Score*) {}
      virtual void cmd(QAction* /*a*/) {}
      virtual void setCurrentView(int /*tabIdx*/, int /*idx*/) {}

      virtual int appendScore(Score* s)               { scoreList.append(s); return 0;  }
      virtual void endCmd() {}
      virtual Score* openScore(const QString& /*fn*/) { return 0;}
      QList<Score*>& scores()                         { return scoreList; }
#endif


};

#endif // MUSESCORECORE_H
