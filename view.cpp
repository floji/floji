/*
** This file was created for floji (https://github.com/floji/floji).
** Copyright (C) 2015 ravas (ravas@outlook.com)
** This file is available under the GNU GENERAL PUBLIC LICENSE Version 3 (GPLv3).
** The GPLv3 license can be found in the license folder as gpl-3.0.txt
** The GPLv3 license can be found at https://www.gnu.org/licenses/gpl-3.0.txt
*/

#include "view.h"

View::View(QWidget* parent): QGraphicsView(parent)
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void View::set_current_action(QAction* q_action)
{
    current_action = q_action->data().toInt();

    if (current_action == Tool::select)
    {
        setDragMode(QGraphicsView::RubberBandDrag);
    }
    else
    {
        setDragMode(QGraphicsView::NoDrag);
    }
}
