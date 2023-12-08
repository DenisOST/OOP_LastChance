#include "Child.h"

void TestCompositePattern() {
    // Создаем простые уроки
    ILesson* mathLesson = new MathLesson();
    ILesson* bioLesson = new BioLesson();

    cout << "Объединение двух простых уроков в композит:" << endl;

    // Создаем композит для группировки уроков
    CompositeLesson* compositeMathAndBioLesson = new CompositeLesson();
    compositeMathAndBioLesson->add(new SimpleLesson(mathLesson));
    compositeMathAndBioLesson->add(new SimpleLesson(bioLesson));
    compositeMathAndBioLesson->display();

    cout << "===============" << endl;

    // Создаем еще один простой урок
    ILesson* engLesson = new EngLesson();

    cout << "Объединение простого урока и композита в главный композит:" << endl;

    // Создаем главный композит, который содержит все уроки
    CompositeLesson* mainLesson = new CompositeLesson();
    mainLesson->add(compositeMathAndBioLesson);
    mainLesson->add(new SimpleLesson(engLesson));

    // Выводим всю иерархию уроков
    mainLesson->display();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TestCompositePattern();
}
