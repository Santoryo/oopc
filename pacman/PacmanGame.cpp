#include <QApplication>
#include "classes/Game.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Game game;
    game.show();
    game.setWindowTitle("PacMan");

    return app.exec();
}