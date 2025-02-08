#ifndef MY_WINDOW_HPP_
#define MY_WINDOW_HPP_

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

class myWindow : public QWidget
{
private:
    QLabel *name_label;
    QLineEdit *name_edit;
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
    }
    ~myWindow() {
        delete name_label;
        delete name_edit;
    }
};


#endif
