#include <QApplication>
#include "game.h"
#include "player.h"
#include "settings.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SettingsManager * sManager = new SettingsManager("Anar", "Shooter");
    Game * game = new Game(sManager, &a);
    game->show();
    return a.exec();
}
