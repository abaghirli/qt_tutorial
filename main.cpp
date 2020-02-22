#include <QApplication>
#include "game.h"
#include "player.h"
#include "settings.h"

Game * game;
SettingsManager * sManager;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sManager = new SettingsManager("Anar", "Shooter");
    game = new Game();
    game->show();
    return a.exec();
}
