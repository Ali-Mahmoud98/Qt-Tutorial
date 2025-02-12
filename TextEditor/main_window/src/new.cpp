#include "mainWindow.hpp"

void MainWindow::newFile() {
    if (wantToSave()) {
        textArea->clear();
        setCurrentFile(QString());
    #ifdef DEBUG_MODE_FUNC
        qDebug() << "New file created\n";
    #endif
    }
}
