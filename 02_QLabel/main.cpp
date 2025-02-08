#include <QApplication>
#include <QWidget>
#include <QLabel>

// #include <QScreen>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // QRect screenGeometry = QGuiApplication::primaryScreen()->availableGeometry();
    int window_width = 500;
    int window_height = 500;
    // int window_x = 0;
    // int window_y = 0;

    // int x = (screenGeometry.width() - window_width) / 2;
    // int y = (screenGeometry.height() - window_height) / 2;

    QWidget *window = new QWidget();
    window->setWindowTitle("QLabel Example");
    window->setGeometry(500, 500, window_width, window_height);
    // window->setGeometry(x, y, window_width, window_height);
    // window->resize(window_width, window_height);
    // window->move(200, 200);

    // QWidget window;
    // window.setWindowTitle("QLabel Example");
    // window.setGeometry(0, 0, window_width, window_height);
    // window.setGeometry(x, y, window_width, window_height);

    // QLabel name_label("Name:", &window);
    QLabel name_label("Name:", window);
    name_label.move(20, 20);

    // QFont font("Arial", 12, QFont::Bold);
    // name_label.setFont(font);

    name_label.setStyleSheet("color: red; font: bold 14px Arial;");

    name_label.setText(u8"اسم المستخدم");


    window->show();
    // window.show();
    return app.exec();
}
