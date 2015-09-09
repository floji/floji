/*
** This file was created for floji (https://github.com/floji/floji).
** Copyright (C) 2015 ravas (ravas@outlook.com)
** This file is available under the GNU GENERAL PUBLIC LICENSE Version 3 (GPLv3).
** The GPLv3 license can be found in the license folder as gpl-3.0.txt
** The GPLv3 license can be found at https://www.gnu.org/licenses/gpl-3.0.txt
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "view.h"
#include "identifiers.h"

#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
    //scene->setForegroundBrush(QColor(0, 0, 0));
    connect(scene, SIGNAL(click_pos(QPointF)), this, SLOT(set_status(QPointF)));
    connect(scene, SIGNAL(request_rect(int, int)), this, SLOT(send_rect_info(int, int)));
    ui->view->setScene(scene);
    scene->setSceneRect(0, 0, 2000, 2000);

    QActionGroup* ag_tools = new QActionGroup(this);
    connect(ag_tools, SIGNAL(triggered(QAction*)), scene, SLOT(set_current_action(QAction*)));
    connect(ag_tools, SIGNAL(triggered(QAction*)), ui->view, SLOT(set_current_action(QAction*)));

    ag_tools->addAction(ui->rectangle);
    ag_tools->addAction(ui->select);

    ui->rectangle->setData(Tool::rectangle);
    ui->select->setData(Tool::select);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// slots

void MainWindow::set_status(QPointF point)
{
    QString x = QString("Point: %1, %2").arg(point.x()).arg(point.y());
    statusBar()->showMessage(x);
}

void MainWindow::send_rect_info(int x, int y)
{
    int width = ui->sb_rect_width->value();
    int height = ui->sb_rect_height->value();
    scene->create_rect(QRectF(x, y, width, height));
}
