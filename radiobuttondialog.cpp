#include "radiobuttondialog.h"
#include "QLabel"
#include "QInputDialog"

RadioButtonDialog::RadioButtonDialog(int selectedOption, int& result, QWidget *parent)
    : QDialog(parent)
{
    // Опції для варіантів
    char* var1arr[5] = {"Позитивно", "Позитивно", "Позитивно", "Згоден цілком", "Другу"};
    char* var2arr[5] = {"Негативно", "Негативно", "Негативно", "Згоден чатсково", "Керівництву"};
    char* var3arr[5] = {"Не знаю", "Не знаю", "Не знаю", "Не згоден", "Собі"};
    char* questions[5] = {"Як ви ставитеся до куріння?",
                          "Яке ваше ставлення до спорту?",
                          "Як ви охарактеризуєте дії вашого керівника,\nякщо він не дотримується правил?",
                          "Чи згодні ви на заміну керівництва?",
                          "Кому би ви доручили керування компанією?"};

    // Встановлення заголовку вікна та розміру
    std::string temp = "Питання № ";
    temp += std::to_string(selectedOption + 1);
    setWindowTitle(QString::fromStdString(temp));
    this->resize(200, 200);

    // Опції вибору для відображення
    QRadioButton *option1 = new QRadioButton(var1arr[selectedOption], this);
    option1->setChecked(true);
    QRadioButton *option2 = new QRadioButton(var2arr[selectedOption], this);
    QRadioButton *option3 = new QRadioButton(var3arr[selectedOption], this);
    QPushButton *okButton = new QPushButton("OK", this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *titleLabel = new QLabel("Оберіть варіант:", this);
    QLabel *textLabel = new QLabel(QString::fromStdString(questions[selectedOption]), this);

    // Підключення сигналу кнопки OK
    connect(okButton, &QPushButton::clicked, this, &RadioButtonDialog::accept);

    // Додавання елементів у вікно
    layout->addWidget(titleLabel);
    layout->addWidget(textLabel);
    layout->addWidget(option1);
    layout->addWidget(option2);
    layout->addWidget(option3);
    layout->addWidget(okButton);

    // Обробка результату
    if (this->exec() == QDialog::Accepted)
    {
        if (option1->isChecked())
            result++;
        if (option2->isChecked())
            result--;
    }
}

RadioButtonDialog::~RadioButtonDialog()
{
}
