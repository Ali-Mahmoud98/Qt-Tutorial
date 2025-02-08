#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>

#include "myWindow.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    myWindow window;
    window.show();

    return app.exec();
}
