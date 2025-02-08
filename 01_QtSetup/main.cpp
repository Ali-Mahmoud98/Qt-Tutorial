#include <QApplication>
#include <QWidget>

int main(int argc, char* argv[])
{
	QApplication app(argc,argv);

	// QWidget* widget = new QWidget();
	QWidget widget;

	// TRY1
	// widget->setWindowTitle("Hello Qt visual C++ - TRY1");
	// widget->setGeometry(0,0,2000,1080);
	// widget->show();

	// TRY2
	widget.setWindowTitle("Hello Qt visual C++ - TRY2");
	widget.setGeometry(0,0,2000,1080);
	widget.show();

	return app.exec();
}
