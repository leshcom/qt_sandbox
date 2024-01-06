#include "mainwindow.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QWidget"
#include "QListWidget"
#include "QPushButton"
#include "QLabel"
#include "position.h"
#include "database.h"
#include "myfunc.cpp"
#include <iostream>
#include <string>
#include <cctype>
#include "radiobuttondialog.h"

using namespace Records;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    // Виділення пам'яті для віджетів та кнопок
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *layout1 = new QVBoxLayout;
    QWidget *textwidget = new QWidget;
    QWidget *buttons = new QWidget;
    QPushButton *addbutton = new QPushButton("Додати посаду");
    QPushButton *changebutton = new QPushButton("Змінити посаду");
    QPushButton *testbutton = new QPushButton("Пройти опитування");

    // Під'єднання слотів до подій натискання кнопок
    connect(addbutton, &QPushButton::released, this, &MainWindow::addposition);
    connect(changebutton, &QPushButton::released, this, &MainWindow::changeposition);
    connect(testbutton, &QPushButton::released, this, &MainWindow::startquerry);
    resultl->setAlignment(Qt::AlignCenter);

    // Налаштування вмісту вікна
    textwidget->setLayout(layout);
    buttons->setLayout(layout1);
    setCentralWidget(textwidget);

    // Додавання списку та кнопок на відповідні панелі
    layout->addWidget(mylist);
    layout->addWidget(buttons);
    layout1->addWidget(addbutton);
    layout1->addWidget(changebutton);
    layout1->addWidget(testbutton);
    layout1->addWidget(resultl);

}

MainWindow::~MainWindow()
{
}
