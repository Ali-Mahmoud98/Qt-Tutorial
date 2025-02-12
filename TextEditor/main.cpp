#include "mainWindow.hpp"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}

#ifdef USE_QOBJECT_MACRO
#include "main.moc"
#endif
