#pragma once

#include "plugintest_global.h"

#include <extensionsystem/iplugin.h>

namespace PluginTest::Internal {

class PluginTestPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "PluginTest.json")

public:
    PluginTestPlugin();
    ~PluginTestPlugin() override;

    void initialize() override;
    void extensionsInitialized() override;
    ShutdownFlag aboutToShutdown() override;

private:
    void triggerAction();
};

} // namespace PluginTest::Internal
