#include "manager.h"

Manager::Manager(){
    this->trayIcon = new TrayIcon(this);
}

Manager::~Manager()
{
    delete trayIcon;
}


void Manager::init() {
    KeepSticky w;
}
