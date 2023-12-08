#include "Child.h"
#include "Indirection.h"



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Пример использования паттерна Indirection в системе управления студентами
    StudentIndirection studentIndirection;

    // Создаем объект Student
    Student* student = new Student();

    // Устанавливаем управление жизненным циклом студента
    studentIndirection.manageStudent(student);

    // Выполняем операции с учеником через промежуточный класс
    student->addStudentInfo();
    student->getStudentInfo();
    student->removeStudentInfo();
    student->updateStudentInfo();

    return 0;
}
