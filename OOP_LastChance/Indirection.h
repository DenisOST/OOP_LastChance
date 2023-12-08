#include <iostream>

using namespace std;

// Класс "Студент"
class Student {
public:
    void addStudentInfo() {
        cout << "\tДобавление информации об ученике" << endl;
    }

    void getStudentInfo() {
        cout << "\tПолучение информации об ученике" << endl;
    }

    void removeStudentInfo() {
        cout << "\tУдаление информации об ученике" << endl;
    }

    void updateStudentInfo() {
        cout << "\tОбновление информации об ученике" << endl;
    }
};

// Класс "Промежуточное управление учеником"
class StudentIndirection {
public:
    void manageStudent(Student* student) {
        student_ = student;
        cout << "Управление жизненным циклом ученика" << endl;
    }

    ~StudentIndirection() {
        delete student_;
        cout << "Ученик удален" << endl;
    }

private:
    Student* student_;
};

