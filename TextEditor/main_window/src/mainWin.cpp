#include "mainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), font_size(12) {
    // setWindowTitle("My Text Editor"); // Set the window title, I use setCurrentFile to set the title of the window
    setGeometry(100, 100, 800, 600);
    
    textArea = new QPlainTextEdit(this);
    setCentralWidget(textArea);

    initMenuBar();
    initStatusBar();
    initToolBar();

    setCurrentFile(QString());

    // connect(textArea, &QPlainTextEdit::textChanged, this, &MainWindow::documantModified);
    connect(textArea->document(), &QTextDocument::contentsChanged, this, &MainWindow::documantModified);
}

MainWindow::~MainWindow() {

}
