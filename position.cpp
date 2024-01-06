/**
 * @file position.cpp
 * @brief Реалізація методів класу Position.
 */

#include <iostream>
#include <string>
#include "position.h"

using namespace std;

namespace Records {

/**
 * @brief Конструктор за замовчуванням класу Position.
 */
Position::Position() {
    posCode = 0;
    posName = "";
    payment = 0;
    obligations = "";
    requirements = "";
}

/**
 * @brief Збільшує бюджет посади на вказану суму.
 * @param inRaiseAmount Сума, на яку збільшується бюджет.
 */
void Position::incrBudget(int inRaiseAmount) {
    setPayment(getPayment() + inRaiseAmount);
}

/**
 * @brief Зменшує бюджет посади на вказану суму.
 * @param inDemeritAmount Сума, на яку зменшується бюджет.
 */
void Position::decrBudget(int inDemeritAmount) {
    setPayment(getPayment() - inDemeritAmount);
}

/**
 * @brief Додає нові вимоги до посади.
 * @param in Нові вимоги.
 */
void Position::addNewReq(std::string in) {
    requirements.append(in);
}

/**
 * @brief Додає нові обов'язки до посади.
 * @param in Нові обов'язки.
 */
void Position::addNewOblig(std::string in) {
    obligations.append(in);
}

/**
 * @brief Повертає рядок з інформацією про посаду.
 * @return Рядок з інформацією про посаду.
 */
std::string Position::display() {
    std::string info = "Посада: " + std::to_string(getPosCode()) + ", " + getPosName() + "\n";
    info += "-------------------------\n";
    info += (getPayment() < 1000 ? "Робітник\n" : "Адміністратор\n");
    info += "Обов'язки: " + getObligations() + "\n";
    info += "Вимоги: " + getRequirements() + "\n";
    info += "Зарплата (у $): " + std::to_string(getPayment()) + "\n\n";

    return info;
}

/**
 * @brief Повертає код посади.
 * @return Код посади.
 */
int Position::getPosCode() {
    return posCode;
}

/**
 * @brief Повертає назву посади.
 * @return Назва посади.
 */
std::string Position::getPosName() {
    return posName;
}

/**
 * @brief Повертає зарплату посади.
 * @return Зарплата посади.
 */
int Position::getPayment() {
    return payment;
}

/**
 * @brief Повертає обов'язки посади.
 * @return Обов'язки посади.
 */
std::string Position::getObligations() {
    return obligations;
}

/**
 * @brief Повертає вимоги посади.
 * @return Вимоги посади.
 */
std::string Position::getRequirements() {
    return requirements;
}

/**
 * @brief Встановлює код посади.
 * @param code Код посади.
 */
void Position::setPosCode(int code) {
    posCode = code;
}

/**
 * @brief Встановлює назву посади.
 * @param name Назва посади.
 */
void Position::setPosName(string name) {
    posName = name;
}

/**
 * @brief Встановлює зарплату посади.
 * @param salary Зарплата посади.
 */
void Position::setPayment(int salary) {
    payment = salary;
}

/**
 * @brief Встановлює обов'язки посади.
 * @param duties Обов'язки посади.
 */
void Position::setObligations(string duties) {
    obligations = duties;
}

/**
 * @brief Встановлює вимоги посади.
 * @param reqs Вимоги посади.
 */
void Position::setRequirements(string reqs) {
    requirements = reqs;
}

} // namespace Records
