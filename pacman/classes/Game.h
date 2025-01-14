#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "Maze.h"
#include "Constants.h"
#include "Pacman.h"

class Game : public QWidget {
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game() = default;
    Pacman pacman;
protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void gameLoop();
private:
    Maze *maze;
    QTimer *timer;
};