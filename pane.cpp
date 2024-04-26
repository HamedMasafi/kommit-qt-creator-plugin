#include "pane.h"

#include <qlabel.h>

#include <projectexplorer/project.h>

Pane::Pane() {
    setId("kommit");
    setDisplayName("kommit");
    setPriorityInStatusBar(10);

    label = new QLabel;
}

QWidget *Pane::outputWidget(QWidget *parent)
{
    label->setParent(parent);
    label->setWindowTitle("kommit");
    label->setText("Hi");
    return label;
}

void Pane::clearContents() {}

void Pane::setFocus() {}

bool Pane::hasFocus() const
{
    return true;
}

bool Pane::canFocus() const
{
    return true;
}

bool Pane::canNavigate() const
{
    return true;
}

bool Pane::canNext() const
{
    return true;
}

bool Pane::canPrevious() const
{
    return true;
}

void Pane::goToNext() {}

void Pane::goToPrev() {}

void Pane::setProject(ProjectExplorer::Project *project)
{
    if (project)
        label->setText(project->projectDirectory().path());
}
