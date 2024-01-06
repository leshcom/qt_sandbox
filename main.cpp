/**
 * @file main.cpp
 * @brief Головний файл програми
 */

#include "mainwindow.h"
#include "radiobuttondialog.h"
#include "position.h"
#include "database.h"
#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>

using namespace Records;

/**
 * @brief Головна функція програми.
 * @param argc Кількість аргументів командного рядка.
 * @param argv Масив з аргументами командного рядка.
 * @return Код завершення програми.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QMenu *fileMenu = w.menuBar()->addMenu("Файл");
    QAction *exitAction = fileMenu->addAction("Вихід");
    QObject::connect(exitAction, &QAction::triggered, [&](){
        QApplication::quit();
    });
    QMenu *actionmenu = w.menuBar()->addMenu("Дії");
    QAction *addpos = actionmenu->addAction("Додати посаду");
    QAction *changepos = actionmenu->addAction("Змінити обрану посаду");
    QAction *acomplishtest = actionmenu->addAction("Пройти опитування");
    QObject::connect(addpos, &QAction::triggered, [&](){
        w.addposition();
    });
    QObject::connect(changepos, &QAction::triggered, [&](){
        w.changeposition();
    });
    QObject::connect(acomplishtest, &QAction::triggered, [&](){
        w.startquerry();
    });
    // connect(w.addbutton, &QPushButton::released, w, addposition());
    // connect(w.changebutton, &QPushButton::released, w, changeposition());
    // connect(w.testbutton, &QPushButton::released, w, startquerry());

    QMenu *helpMenu = w.menuBar()->addMenu("Допомога");
    QAction *aboutAction = helpMenu->addAction("Про програму");
    QObject::connect(aboutAction, &QAction::triggered, [&](){
        QMessageBox::about(&w, "Про програму", "Це Лабораторна робота 3\nВиконана студентом групи ІО-12\nМаксименко Олексієм");
    });

    w.show();
    return a.exec();
}
