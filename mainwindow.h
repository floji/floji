#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scene.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Scene* scene;

private slots:

    void set_status(QPointF);
    void send_rect_info(int x, int y);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
