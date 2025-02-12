#include "mainWindow.hpp"

void MainWindow::initMenuBar() {
    fileMenu = menuBar()->addMenu("File");
    {
        newAction = new QAction(QIcon(":/icons/add-file.png"), "New");
        newAction->setShortcut(QKeySequence::New);
        newAction->setStatusTip("Create a New File");
        connect(newAction, &QAction::triggered, this, &MainWindow::newFile);
        fileMenu->addAction(newAction);
        
        openAction = new QAction(QIcon(":/icons/open.png"), "Open");
        openAction->setShortcut(QKeySequence::Open);
        openAction->setStatusTip("Open an Existing File");
        connect(openAction, &QAction::triggered, this, &MainWindow::open);
        fileMenu->addAction(openAction);

        saveAction = new QAction(QIcon(":/icons/save.png"), "Save");
        saveAction->setShortcut(QKeySequence::Save);
        saveAction->setStatusTip("Save the Current File");
        connect(saveAction, &QAction::triggered, this, &MainWindow::save);
        fileMenu->addAction(saveAction);

        saveAsAction = new QAction(QIcon(":/icons/save-as.png"), "Save As");
        saveAsAction->setShortcut(QKeySequence::SaveAs);
        saveAsAction->setStatusTip("Save the Current File with a New Name");
        connect(saveAsAction, &QAction::triggered, this, &MainWindow::saveAs);

        fileMenu->addAction(saveAsAction);

        // add page setup, print, exit
        fileMenu->addSeparator();

        pageSetupAction = new QAction("Page Setup");
        pageSetupAction->setStatusTip("Configure Page Setup");
    #ifdef ADD_PAGE_SETUP
        connect(pageSetupAction, &QAction::triggered, this, &MainWindow::openCustomPageSetupDialog);
    #endif
        fileMenu->addAction(pageSetupAction);

        printAction = new QAction(QIcon(":/icons/print.png"), "Print");
        printAction->setShortcut(QKeySequence::Print);
        printAction->setStatusTip("Print the Current Document");
        fileMenu->addAction(printAction);

        fileMenu->addSeparator(); // Another separator before exit

        exitAction = new QAction(QIcon(":/icons/exit.png"), "Exit");
        exitAction->setShortcut(QKeySequence::Quit);
        exitAction->setStatusTip("Exit the Application");
        connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
        fileMenu->addAction(exitAction);
    }
    editMenu = menuBar()->addMenu("Edit");
    formatMenu = menuBar()->addMenu("Format");
    viewMenu = menuBar()->addMenu("View");
    helpMenu = menuBar()->addMenu("Help");
    {
        aboutAction = new QAction("help");
        aboutAction->setStatusTip("about us");
        helpMenu->addAction(aboutAction);
    }
}
