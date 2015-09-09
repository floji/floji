#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QAction>

#include "identifiers.h"

class View : public QGraphicsView
{
    Q_OBJECT

public:
    View(QWidget* parent);
    ~View()=default;

    int current_action;

public slots:
    void set_current_action(QAction* q_action);

};

#endif // VIEW_H
