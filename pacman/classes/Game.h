#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "Maze.h"
#include "Constants.h"
#include "Pacman.h"
#include <vector>
#include "Ghost.h"

class Game : public QWidget {
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game() = default;
    Pacman *pacman;
    std::vector<Ghost*> ghosts;
    void setup();
    void collission();
    void respawnGhosts();
    void powerUp();
    void resetGhosts();
    void endGame();
    void restartGame();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void gameLoop();
private:
    Maze *maze;
    QTimer *timer;
    QTimer *powerUpTimer;
};