#include <iostream>
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    std::cout << "Hello from GUI\n";
    QApplication app(argc, argv);

    QPushButton hello("Hello world! Press to quit.", 0);
    hello.resize(200, 60);

    QObject::connect(&hello, SIGNAL(clicked()), &app, SLOT(quit()));

    app.setActiveWindow(&hello);

    hello.show();

    return app.exec();
}
