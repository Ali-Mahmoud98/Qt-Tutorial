#include "mainWindow.hpp"

void MainWindow::initStatusBar() {
    statusBar()->addPermanentWidget(new QLabel(""));
    statusBar()->addPermanentWidget(new QLabel(tr("Font Size: %1").arg(font_size)));
}
