#ifndef RADIOBUTTONDIALOG_H
#define RADIOBUTTONDIALOG_H

#include <QDialog>
#include <QRadioButton>
#include <QPushButton>
#include <QVBoxLayout>

/**
 * @brief Клас RadioButtonDialog представляє діалогове вікно з радіокнопками.
 */
class RadioButtonDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief Конструктор RadioButtonDialog з заданим вибраним варіантом.
     * @param selectedOption Індекс початково обраного варіанту.
     * @param result Ссилка для зберігання індексу обраного варіанту при закритті діалогу.
     * @param parent Батьківський віджет.
     */
    RadioButtonDialog(int selectedOption, int& result, QWidget *parent);

    /**
     * @brief Деструктор RadioButtonDialog.
     */
    ~RadioButtonDialog();

};

#endif // RADIOBUTTONDIALOG_H
