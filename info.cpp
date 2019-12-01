#include "info.h"
#include <QFont>


Info::Info(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    created = 0;
    killed  = 0;
    passed  = 0;
    ingame  = 0;
    setPlainText( QString("Created: ")  + QString::number(created)
                 +QString("\n Killed:") +QString::number(killed)
                 +QString("\n Passed:") +QString::number(passed)
                 +QString("\n In Game") +QString::number(ingame));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 16));
}

void Info::incCreated()
{
    created++;
    setPlainText( QString("Created: ")  + QString::number(created)
                 +QString("\n Killed:") +QString::number(killed)
                 +QString("\n Passed:") +QString::number(passed)
                 +QString("\n In Game") +QString::number(ingame));
}

void Info::incKilled()
{
    killed++;
    setPlainText( QString("Created: ")  + QString::number(created)
                 +QString("\n Killed:") +QString::number(killed)
                 +QString("\n Passed:") +QString::number(passed)
                 +QString("\n In Game") +QString::number(ingame));
}

void Info::incPassed()
{
    passed++;
    setPlainText( QString("Created: ")  + QString::number(created)
                 +QString("\n Killed:") +QString::number(killed)
                 +QString("\n Passed:") +QString::number(passed)
                 +QString("\n In Game") +QString::number(ingame));
}

void Info::incInGame()
{
    ingame++;
    setPlainText( QString("Created: ")  + QString::number(created)
                 +QString("\n Killed:") +QString::number(killed)
                 +QString("\n Passed:") +QString::number(passed)
                 +QString("\n In Game") +QString::number(ingame));
}

void Info::decInGame()
{
    ingame--;
    setPlainText( QString("Created: ")  + QString::number(created)
                 +QString("\n Killed:") +QString::number(killed)
                 +QString("\n Passed:") +QString::number(passed)
                 +QString("\n In Game") +QString::number(ingame));
}


