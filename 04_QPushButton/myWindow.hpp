#ifndef MY_WINDOW_HPP_
#define MY_WINDOW_HPP_

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

#include <QMessageBox>

class myWindow : public QWidget
{
private:
    QLabel *name_label;
    QLineEdit *name_edit;
    QPushButton *button;
public:
    myWindow(QWidget *parent = nullptr) : QWidget(parent) // every window has a parent (nullptr or another window or widget)
    {
        setFixedSize(500, 500);
        setWindowTitle("My Window - 03_QLineEdit");
        setStyleSheet("background-color: #2E3440;");

        name_label = new QLabel("Name:", this);
        name_label->move(20, 20);

        name_edit = new QLineEdit(this);
        name_edit->setStyleSheet("color: black; font: bold 14px Arial; background-color: #D8DEE9;");
        name_edit->move(70, 18);

        button = new QPushButton("Enter", this);
        button->move(220, 100);

        // connect params:
        // first param: object emits the signal
        // second param: function that the emitter will emit
        // third param: object that will receive the signal or that contains the slot.
        //              the object that has the function that will receive the signal.
        // fourth param: function that will be called when the signal is emitted
        // connect(name_edit, &QLineEdit::textChanged, this, &myWindow::text_changed);
        connect(name_edit, &QLineEdit::returnPressed, this, &myWindow::enter_pressed);
        connect(button, &QPushButton::clicked, this, &myWindow::button_clicked);
    }
    ~myWindow() {
        delete name_label;
        delete name_edit;
    }

    // void enter_pressed() {
    //     printf("Name: %s\n", name_edit->text().toStdString().c_str());
    // }
    void enter_pressed() {
        QMessageBox msgBox;
        msgBox.setText("Name: " + name_edit->text());
        msgBox.exec();
    }

    void text_changed() {
        printf("Text Changed");
    }

    void button_clicked() {
        printf("Button Clicked\n");
    }
};


#endif
