#ifndef DOCKPLUGININTERFACE_H
#define DOCKPLUGININTERFACE_H

#include <QObject>
#include <QStringList>

class DockPluginInterface
{
public:
    virtual ~DockPluginInterface() {}
    virtual void init() = 0;
    virtual QStringList uuids() = 0;
    virtual QWidget* getItem(QString uuid) = 0;
};

QT_BEGIN_NAMESPACE

#define DockPluginInterface_iid "org.deepin.Dock.PluginInterface"

Q_DECLARE_INTERFACE(DockPluginInterface, DockPluginInterface_iid)

QT_END_NAMESPACE

#endif // DOCKPLUGININTERFACE_H
