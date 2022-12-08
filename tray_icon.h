#ifndef TRYICON_H
#define TRYICON_H

#include <QSystemTrayIcon>
#include <QMenu>
#include <QApplication>


class Manager;

class TrayIcon : public QSystemTrayIcon
{
Q_OBJECT

public:
    TrayIcon(Manager* parent);
    ~TrayIcon();

private slots:
    void exitAction();

private:
    Manager *manager;
    QMenu *menu;
};

#endif // TRYICON_H
