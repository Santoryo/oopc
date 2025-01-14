#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "Maze.h"
#include "Constants.h"

class Game : public QWidget {
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game() = default;
private slots:
    void gameLoop();
private:
    Maze *maze;
    QTimer *timer;
};