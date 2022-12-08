#include "tray_icon.h"

TrayIcon::TrayIcon(Manager *parent)
    : QSystemTrayIcon()
{
    manager = parent;
    menu = new QMenu();

    QIcon icon = QIcon(":/icons/icon.png");
    setIcon(icon);

    menu->setContextMenuPolicy(Qt::CustomContextMenu);
    menu->addAction("Exit", this, SLOT(exitAction()));

    setContextMenu(menu);

    show();
}

TrayIcon::~TrayIcon(){
    delete menu;
}

void TrayIcon::exitAction() {
    QApplication::quit();
}
