#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>

class MyWindow : public QWidget
{
public:
    MyWindow(QWidget *parent = nullptr) {
        setWindowTitle("06_QLayout - Grid Layout");
        setGeometry(100, 100, 500, 500);
        // setStyleSheet("background-color:rgb(71, 81, 100);");

        main_layout = new QVBoxLayout(this);
        // main_layout = new QVBoxLayout();
        setLayout(main_layout);

        group_box = new QGroupBox(); // this is a group box will contain the grid layout
        group_box->setTitle("Grid Layout");

        grid_layout = new QGridLayout();
        group_box->setLayout(grid_layout);

        main_layout->addWidget(group_box);

        for (int i = 0; i < 3; i++) {
            // gridLabels[i] = new QLabel("Label " + QString::number(i + 1));
            gridLabels[i] = new QLabel(tr("Label %1").arg(i + 1));
            gridLineEdit[i] = new QLineEdit();

            grid_layout->addWidget(gridLabels[i], i, 0);
            grid_layout->addWidget(gridLineEdit[i], i, 1);
        }

        gridTextEdit = new QTextEdit();
        // grid_layout->addWidget(gridTextEdit, 3, 0, 1, 2);
        grid_layout->addWidget(gridTextEdit, 0, 2, 3, 1);

        form_box = new QGroupBox();
        form_box->setTitle("Form");

        form_layout = new QFormLayout();
        form_box->setLayout(form_layout);
        for(int i = 0; i < 3; i++) {
            formLabels[i] = new QLabel(tr("Label %1").arg(i + 1));
        }

        formLineEdit = new QLineEdit();
        formComboBox = new QComboBox();
        formComboBox->addItem("Option 1");
        formComboBox->addItem("Option 2");
        formComboBox->addItem("Option 3");
        formSpinBox = new QSpinBox();
        // change the language of the spin box
        formSpinBox->setRange(0, 100);
        formSpinBox->setSuffix(" %");
        formSpinBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates)); // English (US)

        form_layout->addRow(formLabels[0], formLineEdit);
        form_layout->addRow(formLabels[1], formComboBox);
        form_layout->addRow(formLabels[2], formSpinBox);

        main_layout->addWidget(form_box);

        // for overloaded function connection
        connect(formComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MyWindow::onIndexChanged);
        connect(formSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MyWindow::onSpinBoxChanged);
        connect(formSpinBox, QOverload<const QString&>::of(&QSpinBox::textChanged), this, &MyWindow::onSpinBoxTextChanged);
    }

private:
    QVBoxLayout *main_layout;
    QGridLayout *grid_layout;
    QFormLayout *form_layout;

    // group box
    QGroupBox *group_box;
    QGroupBox *form_box;

    // labels
    QLabel *gridLabels[3];
    QLabel *formLabels[3];

    // line edit
    QLineEdit *gridLineEdit[3];
    QLineEdit *formLineEdit;

    // combo box
    QComboBox *formComboBox;

    // spin box
    QSpinBox *formSpinBox;

    // rich text box
    QTextEdit *gridTextEdit;

    void onIndexChanged(int index) {
        printf("Index Changed: %d\n", index);
        auto txt = formComboBox->currentText();
        printf("Text1: %s\n", txt.toStdString().c_str());
        auto txt2 = formComboBox->itemText(index);
        printf("Text2: %s\n", txt2.toStdString().c_str());
    }

    void onSpinBoxChanged(int value) {
        printf("Spin Box Changed: %d\n", value);
    }

    void onSpinBoxTextChanged(const QString& text) {
        printf("Spin Box Text Changed: %s\n", text.toStdString().c_str());
    }
};

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    MyWindow window;
    window.show();

    return app.exec();
}
