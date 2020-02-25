#include <QApplication>
#include "game.h"
#include "player.h"
#include "settings.h"

//Game * game;
//SettingsManager * sManager;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SettingsManager * sManager = new SettingsManager("Anar", "Shooter");
    Game * game = new Game(sManager);
    game->show();
    return a.exec();
}
