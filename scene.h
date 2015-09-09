#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QAction>
// #include <QSet>

#include "identifiers.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(QObject* parent);
    ~Scene()=default;

    int current_action;
    QMap<QString, int> i_properties;
    QMap<QString, int> i_rect;
    QRectF i_rectf;
    void create_rect(QRectF qrectf);
    void align_center_x();
    QList<QGraphicsItem*> selected_items;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

public slots:
    void set_current_action(QAction* q_action);
    void set_selected(QGraphicsItem * new_item, QGraphicsItem * old_item, Qt::FocusReason reason);

signals:
    void click_pos(QPointF point);

    void request_rect(int x, int y);

};


#endif // SCENE_H
