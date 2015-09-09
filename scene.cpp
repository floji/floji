/*
** This file was created for floji (https://github.com/floji/floji).
** Copyright (C) 2015 ravas (ravas@outlook.com)
** This file is available under the GNU GENERAL PUBLIC LICENSE Version 3 (GPLv3).
** The GPLv3 license can be found in the license folder as gpl-3.0.txt
** The GPLv3 license can be found at https://www.gnu.org/licenses/gpl-3.0.txt
*/

#include "scene.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QKeyEvent>

#include <QDebug>
// #include <QGraphicsDropShadowEffect>

Scene::Scene(QObject* parent): QGraphicsScene(parent)
{
    connect(this, SIGNAL(focusItemChanged(QGraphicsItem*,QGraphicsItem*,Qt::FocusReason)),
            this, SLOT(set_selected(QGraphicsItem*,QGraphicsItem*,Qt::FocusReason)));
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->button() != Qt::LeftButton)
        return;

    switch (current_action)
    {
    case Tool::select:
        QGraphicsScene::mousePressEvent(event);
        break;

    case Tool::rectangle:
        int x = event->scenePos().x();
        int y = event->scenePos().y();
        emit request_rect(x, y);
        break;
    }

    emit click_pos(event->scenePos());
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete)
    {
        foreach(auto item, selectedItems())
        {
            delete item;
        }
    }
    else if (event->key() == Qt::Key_F2)
    {
        align_center_x();
        qDebug() << "F2";
    }
}

void Scene::align_center_x()
{

    if (selected_items.length() > 0)
    {
        qreal x = selected_items[0]->sceneBoundingRect().center().x();
//        qDebug() << x;

        for(int i=1; i<selected_items.length(); ++i)
        {
            QRectF bbox = selected_items[i]->sceneBoundingRect();
            selected_items[i]->moveBy(x-bbox.x()-(0.5*bbox.width()), 0);
            //list[i]->setPos(x-0.5*bbox.width(), bbox.y());
            //bbox.moveCenter(QPointF(x, bbox.center().y()));
        }
    }
}

void Scene::create_rect(QRectF qrectf)
{
    QGraphicsRectItem* rect = addRect(qrectf);
    rect->setFlag(QGraphicsItem::ItemIsMovable, true);
    rect->setFlag(QGraphicsItem::ItemIsSelectable, true);
    rect->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    rect->setFlag(QGraphicsItem::ItemIsFocusable, true);
    // rect->setGraphicsEffect(new QGraphicsDropShadowEffect);
}

// slots

void Scene::set_current_action(QAction* q_action)
{
    // SIGNAL = http://doc.qt.io/qt-5/qactiongroup.html#triggered

    current_action = q_action->data().toInt();
}

void Scene::set_selected(QGraphicsItem* new_item, QGraphicsItem* /* old_item */, Qt::FocusReason /* reason */)
{
    // SIGNAL = http://doc.qt.io/qt-5/qgraphicsscene.html#focusItemChanged

    if (new_item == nullptr)
    {
        selected_items.clear();
    }
    else
    {
        selected_items << new_item;
    }
}
