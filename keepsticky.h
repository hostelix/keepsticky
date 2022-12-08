#ifndef __KEEPSTICKY_H__
#define __KEEPSTICKY_H__

#include <QEvent>
#include <QMainWindow>
#include <QMouseEvent>
#include <QObject>
#include <QSizeGrip>
#include <QPlainTextEdit>
#include <QWidget>
#include <string>
#include "decoration.h"

using namespace std;

class KeepSticky : public QMainWindow {
    Q_OBJECT
public:
    KeepSticky();
    ~KeepSticky();
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
private:
    string getStylesheet(int rand);
    Decoration* decoration;
    QSizeGrip* grip;
    QPlainTextEdit* text;
    QWidget* window;

    QPoint _mpos;
    bool dragging;
};

#endif
