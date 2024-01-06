#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include "position.h"

namespace Records {
const int maxPos = 100; /**< Максимальна кількість позицій у базі */
const int firstposnum = 1000; /**< Перший номер позиції у базі */

/**
     * @brief Клас, що представляє базу даних позицій.
     */
class Database {
public:
    /**
         * @brief Конструктор класу Database.
         */
    Database();

    /**
         * @brief Деструктор класу Database.
         */
    ~Database();

    /**
         * @brief Додає нову позицію до бази даних.
         * @param code Код позиції.
         * @param name Назва позиції.
         * @param payment Оплата за позицію.
         * @return Посилання на об'єкт доданої позиції.
         */
    Position& addPosition(int code, std::string name, int payment);

    /**
         * @brief Отримує позицію за кодом з бази даних.
         * @param code Код позиції.
         * @return Посилання на позицію з вказаним кодом.
         */
    Position& getPosition(int code);

    /**
         * @brief Виводить інформацію про всі позиції у базі даних.
         */
    void displayAll();

    /**
         * @brief Виводить інформацію про робітників у базі даних.
         */
    void displayWorkers();

    /**
         * @brief Виводить інформацію про адміністраторів у базі даних.
         */
    void displayAdmins();

protected:
    Position poslist[maxPos]; /**< Масив позицій */
    int nextslot; /**< Наступний слот у масиві */
    int nextposnum; /**< Наступний номер позиції */
};
}

#endif // DATABASE_H
