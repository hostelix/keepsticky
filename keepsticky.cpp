#include "keepsticky.h"

#include <array>
#include <QWidget>
#include <QDebug>
#include <QGridLayout>
#include <random>
#include <sstream>
#include <tuple>

//const std::array<std::tuple<const char*, const char*>, 3> colors =
//    {std::make_tuple<const char*, const char*>("#D5DB5A", "#E1EB31"),
//     std::make_tuple<const char*, const char*>("#53B3B5", "#68D7D9"),
//     std::make_tuple<const char*, const char*>("#D90D8B", "#FC30AE")};

KeepSticky::KeepSticky() {
    window = new QWidget(this);
    decoration = new Decoration(window);
    decoration->setFixedHeight(20);
    grip = new QSizeGrip(window);

    text = new QPlainTextEdit();

    QGridLayout* layout = new QGridLayout(window);
    layout->addWidget(decoration, 0, 0);
    layout->addWidget(text, 1, 0);
    layout->addWidget(grip, 1, 0, Qt::AlignBottom | Qt::AlignRight);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

//    setStyleSheet(getStylesheet(rand()).c_str());

    setCentralWidget(window);
    setWindowFlags(Qt::FramelessWindowHint);

    dragging = false;

    show();
}


KeepSticky::~KeepSticky() {
    delete decoration;
    delete text;
    delete grip;
    delete window;
}

void KeepSticky::mousePressEvent(QMouseEvent* event){
    QWidget* widget;
    if((widget = QWidget::childAt(event->pos())) && widget->inherits("Decoration")) {
        _mpos = event->pos();
        dragging = true;
    }
}

void KeepSticky::mouseReleaseEvent(QMouseEvent*) {
    dragging = false;
}

void KeepSticky::mouseMoveEvent(QMouseEvent* event){
    if(dragging && event->buttons() && Qt::LeftButton) {
        QPoint diff = event->pos() - _mpos;
        QPoint newpos = this->pos() + diff;

        this->move(newpos);
    }
}
