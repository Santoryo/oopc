#include "Game.h"
#include "Pacman.h"
#include <QKeyEvent>
#include <QLabel>
#include "Ghost.h"
#include "Blinky.h"
#include "Inky.h"
#include "Clyde.h"
#include "Pinky.h"
#include <QFontDatabase>
#include <iomanip>
#include <sstream> 

QLabel *label;
QLabel *health;
QLabel *gameOver;
int scoreVal = 0;
int healthVal = 3;

Blinky *blinky;
Inky *inky;
Clyde *clyde;
Pinky *pinky;

Game::Game(QWidget *parent) : QWidget(parent)
{
    setup();
}

void Game::setup()
{
    maze = new Maze();
    pacman = new Pacman(maze->grid);
    pacman->respawn();

    resize(maze->grid.getCols() * TILE_SIZE, maze->grid.getRows() * TILE_SIZE + 100);

    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::gameLoop);
    timer->start(16); // ~60 FPS

    powerUpTimer = new QTimer(this);
    connect(powerUpTimer, &QTimer::timeout, this, &Game::resetGhosts);

    int fontId = QFontDatabase::addApplicationFont(":/font.ttf");
    if(fontId == -1)
    {
        std::cerr << "Failed to load font" << std::endl;
        throw std::runtime_error("Failed to load font");
    } 
    QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font(family, 24);

    label = new QLabel(this);
    label->setStyleSheet("QLabel { color : white; }");
    label->move(10, maze->grid.getRows() * TILE_SIZE + 10);
    label->setFont(font);
    label->setFixedWidth(100);

    health = new QLabel(this);
    health->setStyleSheet("QLabel { color : white; }");
    health->move(maze->grid.getCols() * TILE_SIZE - 140, maze->grid.getRows() * TILE_SIZE + 10);
    label->setFixedWidth(100);
    health->setFont(font);

    gameOver = new QLabel(this);
    gameOver->setStyleSheet("QLabel { color : white; }");
    gameOver->move(maze->grid.getCols() * TILE_SIZE / 2 - gameOver->width(), maze->grid.getRows() * TILE_SIZE / 2);
    gameOver->setFont(font);
    gameOver->setText("GAME OVER \n SCORE: " + QString::number(scoreVal));
    gameOver->hide();

    auto [xx, xy] = maze->grid.getSpawnCoordinates(BLINKY);
    blinky = new Blinky(maze->grid, xx, xy, *pacman);
    inky = new Inky(maze->grid, xx, xy, *pacman);
    clyde = new Clyde(maze->grid, xx, xy, *pacman);
    pinky = new Pinky(maze->grid, xx, xy, *pacman);

    ghosts.push_back(blinky);
    ghosts.push_back(inky);
    ghosts.push_back(clyde);
    ghosts.push_back(pinky);

    health->setText("LIVES: " + QString::number(healthVal));
}

void Game::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    maze->drawGrid(painter);

    pacman->draw(painter);
    blinky->draw(painter);
    inky->draw(painter);
    clyde->draw(painter);
    pinky->draw(painter);
}

void Game::gameLoop()
{
    collission();

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(3) << scoreVal;
    label->setText(oss.str().c_str());
    pacman->move();

    if(maze->grid.getCell(pacman->getRow(), pacman->getCol()) == COIN)
    {
        maze->grid.setCell(pacman->getRow(), pacman->getCol(), PATH);
        scoreVal++;
    }
    if(maze->grid.getCell(pacman->getRow(), pacman->getCol()) == POWERUP)
    {
        maze->grid.setCell(pacman->getRow(), pacman->getCol(), PATH);
        powerUp();
    }

    update();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Left:
            pacman->setDirection(LEFT);
            break;
        case Qt::Key_Right:
            pacman->setDirection(RIGHT);
            break;
        case Qt::Key_Up:
            pacman->setDirection(UP);
            break;
        case Qt::Key_Down:
            pacman->setDirection(DOWN);
            break;
        case Qt::Key_Escape:
            exit(0);
        case Qt::Key_R:
            restartGame();
            break;
        default:
            break;
    }
}

void Game::collission()
{
    for(Ghost *ghost : ghosts)
    {
        ghost->move();
        if(pacman->getRow() == ghost->getRow() && pacman->getCol() == ghost->getCol())
        {
            if(ghost->getScared())
            {
                    auto [x, y] = maze->grid.getSpawnCoordinates(BLINKY);
                    ghost->setPos(x, y);
                    ghost->setNormal();
                    scoreVal += 100;
            }
            else
            {
                healthVal--;
                health->setText("LIVES: " + QString::number(healthVal));;
                if(healthVal == 0)
                {
                    endGame();
                    return;
                }
                pacman->respawn();
                respawnGhosts();
            }
        }
    }
}

void Game::respawnGhosts()
{
    auto [x, y] = maze->grid.getSpawnCoordinates(BLINKY);
    for(Ghost *ghost : ghosts)
    {
        ghost->setPos(x, y);
    }
}

void Game::powerUp()
{
    for(Ghost *ghost : ghosts)
    {
        ghost->setScared();
    }

    scoreVal += 10;

    if (powerUpTimer->isActive())
    {
        powerUpTimer->stop();
    }

    powerUpTimer->start(10000);
}

void Game::resetGhosts()
{
    for (Ghost *ghost : ghosts)
    {
        ghost->setNormal();
    }
}

void Game::endGame()
{
    gameOver->show();
    timer->stop();
}

void Game::restartGame()
{
    scoreVal = 0;
    healthVal = 3;
    health->setText("LIVES: " + QString::number(healthVal));
    respawnGhosts();
    resetGhosts();
    pacman->respawn();
    timer->start(16);
    gameOver->hide();
    maze = new Maze();
    resize(maze->grid.getCols() * TILE_SIZE, maze->grid.getRows() * TILE_SIZE + 100);
    update();
}