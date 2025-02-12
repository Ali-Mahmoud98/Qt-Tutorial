#include "mainWindow.hpp"

void MainWindow::initToolBar() {
    toolBar = new QToolBar();

    toolBar->setIconSize(QSize(26, 26));

    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addAction(saveAsAction);
    toolBar->addAction(QIcon(":/icons/copy.png"), "Copy");
    toolBar->addAction(QIcon(":/icons/cut.png"), "Cut");
    toolBar->addAction(QIcon(":/icons/paste.png"), "Paste");
    toolBar->addAction(printAction);
    toolBar->addAction(QIcon(":/icons/undo.png"), "Undo");
    toolBar->addAction(QIcon(":/icons/redo.png"), "Redo");

    addToolBar(toolBar);
}
