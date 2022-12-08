#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <keepsticky.h>
#include <tray_icon.h>

class Manager : public QObject
{
    Q_OBJECT
public:
    Manager();
    ~Manager();

    void init();

private:
    TrayIcon *trayIcon;

};

#endif // MANAGER_H
