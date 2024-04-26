#pragma once

#include <coreplugin/sidebar.h>


class SideItem : public Core::SideBarItem
{
    Q_OBJECT

public:
    SideItem(QWidget *parent);

    // SideBarItem interface
public:
    QList<QToolButton *> createToolBarWidgets();
};
