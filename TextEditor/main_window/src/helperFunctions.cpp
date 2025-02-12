#include "mainWindow.hpp"
#include <QMessageBox>

void MainWindow::setCurrentFile(QString fileName) {
    currentFileName = fileName;
    textArea->document()->setModified(false);

    setWindowModified(false);

    QString showName = currentFileName;
    if (currentFileName.isEmpty()) {
        showName = "untitled.txt";
    }

    setWindowFilePath(showName);
}

void MainWindow::documantModified() {
    setWindowModified(textArea->document()->isModified());
}

bool MainWindow::wantToSave() {
    if (!textArea->document()->isModified())
        return true;
    
    auto ret = QMessageBox::warning(this, "Save",
                "The document has been modified.\nDo you want to save your changes?",
                QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    
    switch (ret)
    {
    case QMessageBox::Save:
        save();
        break;
    case QMessageBox::Discard:
        break;
    case QMessageBox::Cancel:
        return false;    
    default:
        break;
    }

    return true;
}
