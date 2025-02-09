#include "myWindow.hpp"


myWindow::myWindow(QWidget *parent): QWidget(parent) {
    // qDebug() << "Creating myWindow instance";
    if (parent == nullptr)
    {
        printf("parent is nullptr\n");
    }
    
    setWindowTitle("Login Window");
    setFixedSize(300, 150);
    // Qt::FramelessWindowHint → Removes the title bar and window borders.
    // Qt::Window → Ensures it is a standard window.
    // Qt::WindowCloseButtonHint → Keeps the close button while removing minimize & maximize buttons.
    // setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::FramelessWindowHint);
    // setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    // setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    main_layout = new QVBoxLayout();
    setLayout(main_layout);

    row1_layout = new QHBoxLayout();
    row1_layout->setSpacing(7);
    uName_lable = new QLabel("Username : ");
    uName_lineEdit = new QLineEdit();
    row1_layout->addWidget(uName_lable);
    row1_layout->addWidget(uName_lineEdit);

    main_layout->addLayout(row1_layout);

    row2_layout = new QHBoxLayout();
    row2_layout->setSpacing(10);
    pass_lable = new QLabel("Password : ");
    pass_lineEdit = new QLineEdit();
    pass_lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
    row2_layout->addWidget(pass_lable);
    row2_layout->addWidget(pass_lineEdit);

    main_layout->addLayout(row2_layout);

    row3_layout = new QHBoxLayout();
    login_btn = new QPushButton("Login");
    cancel_btn = new QPushButton("Cancel");
    row3_layout->addWidget(login_btn);
    row3_layout->addWidget(cancel_btn);

    main_layout->addLayout(row3_layout);

    connect(login_btn, &QPushButton::clicked, this, &myWindow::login_pressed);
    connect(cancel_btn, &QPushButton::clicked, this, &myWindow::cancel_pressed);

    // without pointers
    // setLayout(&main_layout);
    // row1_layout.setSpacing(7);
    // row1_layout.addWidget(&uName_lable);
    // row1_layout.addWidget(&uName_lineEdit);
    // main_layout.addLayout(&row1_layout);
    // row2_layout.setSpacing(10);
    // pass_lineEdit.setEchoMode(QLineEdit::EchoMode::Password);
    // row2_layout.addWidget(&pass_lable);
    // row2_layout.addWidget(&pass_lineEdit);
    // main_layout.addLayout(&row2_layout);
    // row3_layout.addWidget(&login_btn);
    // row3_layout.addWidget(&cancel_btn);
    // main_layout.addLayout(&row3_layout);

    // using unique pointer
    // main_layout = std::make_unique<QVBoxLayout>();
    // setLayout(main_layout.get());

    // row1_layout = std::make_unique<QHBoxLayout>();
    // row1_layout->setSpacing(7);
    // uName_lable = std::make_unique<QLabel>("Username : ");
    // uName_lineEdit = std::make_unique<QLineEdit>();
    // row1_layout->addWidget(uName_lable.get());
    // row1_layout->addWidget(uName_lineEdit.get());

    // main_layout->addLayout(row1_layout.get());

    // row2_layout = std::make_unique<QHBoxLayout>();
    // row2_layout->setSpacing(10);
    // pass_lable = std::make_unique<QLabel>("Password : ");
    // pass_lineEdit = std::make_unique<QLineEdit>();
    // pass_lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
    // row2_layout->addWidget(pass_lable.get());
    // row2_layout->addWidget(pass_lineEdit.get());

    // main_layout->addLayout(row2_layout.get());

    // row3_layout = std::make_unique<QHBoxLayout>();
    // login_btn = std::make_unique<QPushButton>("Login");
    // cancel_btn = std::make_unique<QPushButton>("Cancel");
    // row3_layout->addWidget(login_btn.get());
    // row3_layout->addWidget(cancel_btn.get());

    // main_layout->addLayout(row3_layout.get());

    // connect(login_btn.get(), &QPushButton::clicked, this, &myWindow::login_pressed);
    // connect(cancel_btn.get(), &QPushButton::clicked, this, &myWindow::cancel_pressed);
}

myWindow::~myWindow() {
    // qDebug() << "Destroying myWindow instance";
}

void myWindow::login_pressed() {
    printf("Login button pressed\n");
}

void myWindow::cancel_pressed() {
    printf("Cancel button pressed\n");
    myWindow::close();
}
