#include "mainWindow.hpp"
#include <QFileDialog>
#include <QGuiApplication>
#include <QSaveFile>
#include <QMessageBox>

void MainWindow::saveAs() {
    QFileDialog dialog(this);

    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);

    if (dialog.exec() == QDialog::Accepted) {
        currentFileName = dialog.selectedFiles().first();
        setCurrentFile(currentFileName);
        save();
    } else {
    #ifdef DEBUG_MODE_FUNC
        qDebug() << "Save canceled\n";
    #endif
        return;
    }
}
void MainWindow::save() {
    if (currentFileName.isEmpty()) {
        saveAs();
    } else {
        QGuiApplication::setOverrideCursor(Qt::WaitCursor);
        
        QSaveFile saveFile(currentFileName);
        if (saveFile.open(QFile::WriteOnly | QFile::Text)) {
            QTextStream out(&saveFile);
            out << textArea->toPlainText();

            if (!saveFile.commit()) {
                QMessageBox::warning(this, "Warning", "Cannot save file: " + saveFile.errorString());
            }
        } else {
            QMessageBox::warning(this, "Warning", "Cannot open file: " + saveFile.errorString());
        }

        QGuiApplication::restoreOverrideCursor();
        setCurrentFile(currentFileName);
        statusBar()->showMessage("File saved", 2000);
    }
}
