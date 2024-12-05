    #include <QApplication>
    #include <QPushButton>
    #include <QMainWindow>
    #include <QGraphicsScene>
    #include <QGraphicsView>
    #include <QGraphicsRectItem>

    int main(int argc, char *argv[])
    {
        QApplication app(argc, argv);

        QGraphicsScene *scene = new QGraphicsScene();

        QGraphicsRectItem *rect  = new QGraphicsRectItem(0, 0, 100, 100);
        scene->addItem(rect);

        
        QGraphicsView *view = new QGraphicsView(scene);
        view->setScene(scene);

        view->show();
        view->resize(400, 400);
        return app.exec();
    }