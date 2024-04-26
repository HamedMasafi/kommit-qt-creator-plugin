#pragma once

#include <coreplugin/ioutputpane.h>

namespace ProjectExplorer {
class Project;
};

class QLabel;

class Pane final : public Core::IOutputPane
{
public:
    Pane();

public:
    QWidget *outputWidget(QWidget *parent);
    void clearContents();
    void setFocus();
    bool hasFocus() const;
    bool canFocus() const;
    bool canNavigate() const;
    bool canNext() const;
    bool canPrevious() const;
    void goToNext();
    void goToPrev();

    void setProject(ProjectExplorer::Project *project);

    QLabel *label;
};
