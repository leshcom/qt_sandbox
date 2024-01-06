#define defaultSalary 1000 /**< Зарплата за замовчуванням */
#define defaultCode 0 /**< Код за замовчуванням */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "position.h"
#include "database.h"
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QLabel>
#include <QListWidget>
#include <QStringList>
#include "radiobuttondialog.h"

using namespace Records;
using namespace std;

/**
 * @brief Головне вікно програми.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класу MainWindow.
     * @param parent Вказівник на батьківський віджет.
     */
    MainWindow(QWidget *parent = nullptr);

    QPushButton addbutton; /**< Кнопка "Додати" */
    QPushButton changebutton; /**< Кнопка "Змінити" */
    QPushButton testbutton; /**< Кнопка "Тест" */
    QListWidget *mylist = new QListWidget; /**< Список позицій */
    Database myDB; /**< База даних */
    int result=0; /**< Результат тесту */
    QStringList answered; /**< Список відповідей */
    QLabel * resultl = new QLabel("0"); /**< Мітка з результатом */

    /**
     * @brief Деструктор класу MainWindow.
     */
    ~MainWindow();

public slots:
    /**
     * @brief Додає нову посаду до бази даних.
     */
    void addposition()
    {
        QStringList positions = {};
        bool okCode;
        int code = QInputDialog::getInt(nullptr, "Введення коду", "Введіть код:", 0, 0, 1000, 1, &okCode);
        QString name = QInputDialog::getText(nullptr, "Введення назви", "Введіть назву:");
        bool okSalary;
        double salary = QInputDialog::getDouble(nullptr, "Введення зарплати", "Введіть зарплату:", 0.00, -1000000.00, 1000000.00, 2, &okSalary);

        if (!okSalary || !okCode)
        {
            QMessageBox::about(this, "Увага", "Посада додана до бази, але сталася непередбачена помилка. Перевірте посаду у списку та внесіть зміни.");
            myDB.addPosition(defaultCode, name.toStdString(), defaultSalary);
        }

        myDB.addPosition(code, name.toStdString(), salary);
        positions.append(QString::fromStdString(myDB.getPosition(code).display()));
        mylist->addItem(positions.first());
    }
    /**
     * @brief Змінює існуючу посаду.
     */
    void changeposition()
    {
        QListWidgetItem* selectedIndex = mylist->currentItem();
        if(selectedIndex != nullptr)
        {
            int pickedcode = findFirstNumber((selectedIndex->text()).toStdString());
            int code = QInputDialog::getInt(nullptr, "Введення коду", "Введіть код:", 0, 0, 1000, 1);
            QString name = QInputDialog::getText(nullptr, "Введення назви", "Введіть назву:");
            double salary = QInputDialog::getDouble(nullptr, "Введення зарплати", "Введіть зарплату:", 0.00, -1000000.00, 1000000.00, 2);
            QString oblig = QInputDialog::getText(nullptr, "Введення обов'язків", "Введіть обов'язки:");
            QString requir = QInputDialog::getText(nullptr, "Введення вимог", "Введіть вимоги:");

            myDB.getPosition(pickedcode).setPosCode(code);
            myDB.getPosition(pickedcode).setPayment(salary);
            myDB.getPosition(pickedcode).setPosName(name.toStdString());
            myDB.getPosition(pickedcode).setObligations(oblig.toStdString());
            myDB.getPosition(pickedcode).setRequirements(requir.toStdString());
            mylist->currentItem()->setText(QString::fromStdString(myDB.getPosition(code).display()));
        }
    }
    /**
     * @brief Розпочинає опитування користувача.
     */
    void startquerry()
    {
        QString name = QInputDialog::getText(nullptr, "Введіть ім'я", "Введіть ім'я:");
        result = 0;
        for(int i = 0; i < 5; i++)
        {
            RadioButtonDialog(i, result ,this);
        }
        answered.append(name+QString::fromStdString(std::to_string(result)));
        resultl->setText(QString::fromStdString(std::to_string(result)));
        if (result > 0)
        {
            resultl->setStyleSheet("background-color: green");

        }
        else if(result < 0)
        {
            resultl->setStyleSheet("background-color: red");

        }
        else{
            resultl->setStyleSheet("background-color: yellow");


        }
    }
    /**
     * @brief Знаходить перше число в рядку.
     * @param str Рядок, в якому потрібно знайти число.
     * @return Знайдене число.
     */
    int findFirstNumber(const std::string& str) {
        int number = 0;
        bool found = false;

        for (char ch : str) {
            if (std::isdigit(ch)) {
                number = number * 10 + (ch - '0');
                found = true;
            } else if (found) {
                break;
            }
        }

        return number;
    }
};

#endif // MAINWINDOW_H
