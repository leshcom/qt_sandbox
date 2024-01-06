#ifndef POSITION_H
#define POSITION_H

#include <iostream>

namespace Records {

/**
 * @brief Клас, що представляє посаду в організації.
 */
class Position
{
public:
    /**
     * @brief Конструктор за замовчуванням для класу Position.
     */
    Position();

    /**
     * @brief Зменшує бюджет на вказану суму.
     * @param inDemeritAmount Сума для зменшення бюджету.
     */
    void decrBudget(int inDemeritAmount);

    /**
     * @brief Збільшує бюджет на вказану суму.
     * @param inRaiseAmount Сума для збільшення бюджету.
     */
    void incrBudget(int inRaiseAmount);

    /**
     * @brief Додає нову вимогу до посади.
     * @param in Нова вимога.
     */
    void addNewReq(std::string in);

    /**
     * @brief Додає новий обов'язок до посади.
     * @param in Новий обов'язок.
     */
    void addNewOblig(std::string in);

    /**
     * @brief Повертає інформацію про посаду у вигляді рядка.
     * @return Інформація про посаду.
     */
    std::string display();

    /**
     * @brief Отримує код посади.
     * @return Код посади.
     */
    int getPosCode();

    /**
     * @brief Встановлює код посади.
     * @param code Код посади.
     */
    void setPosCode(int code);

    /**
     * @brief Отримує назву посади.
     * @return Назва посади.
     */
    std::string getPosName();

    /**
     * @brief Встановлює назву посади.
     * @param name Назва посади.
     */
    void setPosName(std::string name);

    /**
     * @brief Отримує розмір оплати посади.
     * @return Розмір оплати посади.
     */
    int getPayment();

    /**
     * @brief Встановлює розмір оплати посади.
     * @param salary Розмір оплати (зарплата).
     */
    void setPayment(int salary);

    /**
     * @brief Отримує перелік обов'язків посади.
     * @return Обов'язки посади.
     */
    std::string getObligations();

    /**
     * @brief Встановлює перелік обов'язків посади.
     * @param duties Обов'язки посади.
     */
    void setObligations(std::string duties);

    /**
     * @brief Отримує перелік вимог до посади.
     * @return Вимоги до посади.
     */
    std::string getRequirements();

    /**
     * @brief Встановлює перелік вимог до посади.
     * @param reqs Вимоги до посади.
     */
    void setRequirements(std::string reqs);

private:
    int posCode; /**< Код посади */
    std::string posName; /**< Назва посади */
    int payment; /**< Оплата посади (зарплата) */
    std::string obligations; /**< Обов'язки посади */
    std::string requirements; /**< Вимоги до посади */
};

} // namespace Records

#endif // POSITION_H
