#include "mainWindow.hpp"

void MainWindow::openCustomPageSetupDialog() {
    QDialog *pageSetupDialog = new QDialog(this);
    pageSetupDialog->setWindowTitle("Page Setup");

    // Layout for the dialog
    QVBoxLayout *layout = new QVBoxLayout(pageSetupDialog);

    // Example: margin settings
    QLabel *marginsLabel = new QLabel("Set margins (mm):", pageSetupDialog);
    QSpinBox *topMarginSpinBox = new QSpinBox(pageSetupDialog);
    QSpinBox *bottomMarginSpinBox = new QSpinBox(pageSetupDialog);
    QSpinBox *leftMarginSpinBox = new QSpinBox(pageSetupDialog);
    QSpinBox *rightMarginSpinBox = new QSpinBox(pageSetupDialog);

    // Set margin ranges (0 to 100 mm for example)
    topMarginSpinBox->setRange(0, 100);
    bottomMarginSpinBox->setRange(0, 100);
    leftMarginSpinBox->setRange(0, 100);
    rightMarginSpinBox->setRange(0, 100);

    layout->addWidget(marginsLabel);
    layout->addWidget(topMarginSpinBox);
    layout->addWidget(bottomMarginSpinBox);
    layout->addWidget(leftMarginSpinBox);
    layout->addWidget(rightMarginSpinBox);

    // Example: page orientation (portrait/landscape)
    QLabel *orientationLabel = new QLabel("Select Orientation:", pageSetupDialog);
    QComboBox *orientationComboBox = new QComboBox(pageSetupDialog);
    orientationComboBox->addItem("Portrait");
    orientationComboBox->addItem("Landscape");
    layout->addWidget(orientationLabel);
    layout->addWidget(orientationComboBox);

    // Apply/Cancel buttons
    QPushButton *applyButton = new QPushButton("Apply", pageSetupDialog);
    QPushButton *cancelButton = new QPushButton("Cancel", pageSetupDialog);

    connect(applyButton, &QPushButton::clicked, this, [=]() {
        // You can handle the values set by the user here, e.g., save them to settings
        int topMargin = topMarginSpinBox->value();
        int bottomMargin = bottomMarginSpinBox->value();
        int leftMargin = leftMarginSpinBox->value();
        int rightMargin = rightMarginSpinBox->value();
        QString orientation = orientationComboBox->currentText();

        // Handle the page setup (store values, print, etc.)
        qDebug() << "Margins: " << topMargin << bottomMargin << leftMargin << rightMargin;
        qDebug() << "Orientation: " << orientation;
        pageSetupDialog->accept();
    });

    connect(cancelButton, &QPushButton::clicked, pageSetupDialog, &QDialog::reject);

    layout->addWidget(applyButton);
    layout->addWidget(cancelButton);

    pageSetupDialog->exec();
}
