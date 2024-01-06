#include "database.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

namespace Records {
/**
     * @brief Конструктор за замовчуванням для класу Database.
     */
Database::Database() {
    nextslot = 0;
    nextposnum = firstposnum;
}

/**
     * @brief Деструктор для класу Database.
     */
Database::~Database() {}

/**
     * @brief Додає нову посаду у базу даних.
     * @param code Код посади.
     * @param name Назва посади.
     * @param payment Зарплата посади.
     * @return Змінна типу Position, що представляє нову посаду.
     * @throw std::exception Якщо досягнуто максимальну кількість посад.
     */
Position& Database::addPosition(int code, std::string name, int payment) {
    if (nextslot >= maxPos) {
        cerr << "Ми не можемо додавати більше посад!" << endl;
        throw exception();
    }
    Position& newPosition = poslist[nextslot++];
    newPosition.setPosCode(code);
    newPosition.setPosName(name);
    newPosition.setPayment(payment);
    return newPosition;
}

/**
     * @brief Отримує посаду за її кодом.
     * @param code Код посади.
     * @return Змінна типу Position, що представляє шукану посаду.
     * @throw std::exception Якщо посада з вказаним кодом не знайдена.
     */
Position& Database::getPosition(int code) {
    for (int i = 0; i < nextslot; i++) {
        if (poslist[i].getPosCode() == code) {
            return poslist[i];
        }
    }
    cerr << "Немає збігу з кодом " << code << endl;
    throw exception();
}

/**
     * @brief Виводить інформацію про всі посади у базі даних.
     */
void Database::displayAll() {
    for (int i = 0; i < nextslot; i++) {
        poslist[i].display();
    }
}

/**
     * @brief Виводить інформацію про робочі посади у базі даних.
     */
void Database::displayWorkers() {
    for (int i = 0; i < nextslot; i++) {
        if (poslist[i].getPayment() < 1000) {
            poslist[i].display();
        }
    }
}

/**
     * @brief Виводить інформацію про адміністративні посади у базі даних.
     */
void Database::displayAdmins() {
    for (int i = 0; i < nextslot; i++) {
        if (poslist[i].getPayment() >= 1000) {
            poslist[i].display();
        }
    }
}
}
