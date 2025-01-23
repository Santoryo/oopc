#pragma once
#include <QPainter>
#include <QTimer>

class Powerup: public QObject {
    Q_OBJECT
public:
    QTimer *timer;
    Powerup();
    ~Powerup() = default;
    void draw(QPainter &painter, int x, int y);
private slots:
    void toggleVisibility();
private:
    bool isVisible;
};