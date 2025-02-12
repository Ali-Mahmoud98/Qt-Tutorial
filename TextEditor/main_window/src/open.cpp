#include "mainWindow.hpp"
#include <QFileDialog>
#include <QMessageBox>

void MainWindow::open() {
    if (wantToSave())
    {
        currentFileName = QFileDialog::getOpenFileName(this, "Open File");
        if (!currentFileName.isEmpty()) {
            QFile file(currentFileName);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
                return;
            }

            QTextStream in(&file);
            QGuiApplication::setOverrideCursor(Qt::WaitCursor);
            textArea->setPlainText(in.readAll());
            QGuiApplication::restoreOverrideCursor();

            setCurrentFile(currentFileName);
        }
    }
    
}
