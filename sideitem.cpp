#include "sideitem.h"

#include <QToolButton>

SideItem::SideItem(QWidget *parent)
    : Core::SideBarItem{parent, "wieuroiweurower"}
{}

QList<QToolButton *> SideItem::createToolBarWidgets()
{
    QList<QToolButton *> ret;
    for (int i = 0; i < 3; ++i) {
        auto btn = new QToolButton;
        btn->setText(QStringLiteral("btn %0").arg(i + 1));
        ret << btn;
    }
    return ret;
}
