#include "plugintest.h"
#include "pane.h"
#include "plugintestconstants.h"

#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/coreconstants.h>
#include <coreplugin/icontext.h>
#include <coreplugin/icore.h>
#include <coreplugin/sidebar.h>
#include <coreplugin/sidebarwidget.h>

#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/projectmanager.h>

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>

namespace PluginTest::Internal {

PluginTestPlugin::PluginTestPlugin()
{
    // Create your members
}

PluginTestPlugin::~PluginTestPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

void PluginTestPlugin::initialize()
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    // If you need access to command line arguments or to report errors, use the
    //    bool IPlugin::initialize(const QStringList &arguments, QString *errorString)
    // overload.

    auto action = new QAction(tr("PluginTest Action"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action,
                                                             Constants::ACTION_ID,
                                                             Core::Context(
                                                                 Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
    connect(action, &QAction::triggered, this, &PluginTestPlugin::triggerAction);

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("PluginTest"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    auto pane = new Pane;
    pane->setParent(this);

    auto *sessionManager = ProjectExplorer::ProjectManager::instance();
    connect(sessionManager,
            &ProjectExplorer::ProjectManager::startupProjectChanged,
            pane,
            &Pane::setProject);

    pane->setProject(sessionManager->startupProject());
}

void PluginTestPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag PluginTestPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void PluginTestPlugin::triggerAction()
{
    QMessageBox::information(Core::ICore::mainWindow(),
                             tr("Action Triggered"),
                             tr("This is an action from PluginTest."));
}

} // namespace PluginTest::Internal
