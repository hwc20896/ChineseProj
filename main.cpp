#include "widget.h"

#include <QApplication>

int main(int argc, char** argv){
    QApplication app(argc, argv);
    Widget window;
    window.show();
    window.setWindowTitle("中華文化知識40題");
    return app.exec();
}
