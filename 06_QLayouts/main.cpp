#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>

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

        group_box2 = new QGroupBox();
        main_layout->addWidget(group_box2);
    }

private:
    QVBoxLayout *main_layout;
    QGridLayout *grid_layout;

    // group box
    QGroupBox *group_box;
    QGroupBox *group_box2;

    // labels
    QLabel *gridLabels[3];

    // line edit
    QLineEdit *gridLineEdit[3];

    // rich text box
    QTextEdit *gridTextEdit;
};

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    MyWindow window;
    window.show();

    return app.exec();
}
