#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QSystemTrayIcon>
#include <QCoreApplication>
#include <manager.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setQuitLockEnabled(false);

//    QIcon icon = QIcon("icon.png");

//    // Adding item on the menu bar
//    QSystemTrayIcon tray;
//    tray.setIcon(icon);
//    tray.setVisible(true);

//    // Creating the options
//    QMenu *menu = new QMenu();
////    QAction *option1 = new QAction("Quit");

//    menu->addAction("Quit", menu, SLOT( QCoreApplication::quit()));

//    tray.setContextMenu(menu);

////    QObject::connect(option1, SIGNAL(&QAction::triggered), &app, SLOT(quit()));

    Manager *notesManager = new Manager();

    notesManager->init();

    return app.exec();
}
