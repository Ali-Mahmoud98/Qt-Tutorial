#ifndef MY_WINDOW_HPP_
#define MY_WINDOW_HPP_

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

#include <QMessageBox>

#include <QHBoxLayout>
#include <QVBoxLayout>

class myWindow : public QWidget
{
private:
    QVBoxLayout *main_layout;
    QHBoxLayout *row1_layout;
    QHBoxLayout *row2_layout;
    QHBoxLayout *row3_layout;

    QLabel *uName_lable;
    QLabel *pass_lable;

    QLineEdit *uName_lineEdit;
    QLineEdit *pass_lineEdit;

    QPushButton *login_btn;
    QPushButton *cancel_btn;
    
    // QVBoxLayout main_layout;
    // QHBoxLayout row1_layout;
    // QHBoxLayout row2_layout;
    // QHBoxLayout row3_layout;

    // QLabel uName_lable{"Username : "};
    // QLabel pass_lable{"Password : "};

    // QLineEdit uName_lineEdit;
    // QLineEdit pass_lineEdit;

    // QPushButton login_btn{"Login"};
    // QPushButton cancel_btn{"Cancel"};

    // Use unique_ptr to automatically manage memory
    // std::unique_ptr<QVBoxLayout> main_layout;
    // std::unique_ptr<QHBoxLayout> row1_layout;
    // std::unique_ptr<QHBoxLayout> row2_layout;
    // std::unique_ptr<QHBoxLayout> row3_layout;

    // std::unique_ptr<QLabel> uName_lable;
    // std::unique_ptr<QLabel> pass_lable;

    // std::unique_ptr<QLineEdit> uName_lineEdit;
    // std::unique_ptr<QLineEdit> pass_lineEdit;

    // std::unique_ptr<QPushButton> login_btn;
    // std::unique_ptr<QPushButton> cancel_btn;
public:
    myWindow(QWidget *parent = nullptr); // every window has a parent (nullptr or another window or widget)
    ~myWindow();
    void login_pressed();
    void cancel_pressed();
};


#endif
