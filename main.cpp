/*
** This file was created for floji (https://github.com/floji/floji).
** Copyright (C) 2015 ravas (ravas@outlook.com)
** This file is available under the GNU GENERAL PUBLIC LICENSE Version 3 (GPLv3).
** The GPLv3 license can be found in the license folder as gpl-3.0.txt
** The GPLv3 license can be found at https://www.gnu.org/licenses/gpl-3.0.txt
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow win;
    win.setWindowTitle("floji");
    win.showMaximized();
    return app.exec();
}
