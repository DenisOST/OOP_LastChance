#include "Child.h"

void TestCompositePattern() {
    // Создаем простые уроки
    ILesson* mathLesson = new MathLesson();
    ILesson* bioLesson = new BioLesson();

    // Создаем композит для группировки уроков
    CompositeLesson* compositeMathLesson = new CompositeLesson();
    compositeMathLesson->add(new SimpleLesson(mathLesson));
    compositeMathLesson->add(new SimpleLesson(bioLesson));

    // Создаем еще один простой урок
    ILesson* engLesson = new EngLesson();

    // Создаем главный композит, который содержит все уроки
    CompositeLesson* mainLesson = new CompositeLesson();
    mainLesson->add(compositeMathLesson);
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
