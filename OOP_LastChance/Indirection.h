#include <iostream>

using namespace std;

// ����� "�������"
class Student {
public:
    void addStudentInfo() {
        cout << "\t���������� ���������� �� �������" << endl;
    }

    void getStudentInfo() {
        cout << "\t��������� ���������� �� �������" << endl;
    }

    void removeStudentInfo() {
        cout << "\t�������� ���������� �� �������" << endl;
    }

    void updateStudentInfo() {
        cout << "\t���������� ���������� �� �������" << endl;
    }
};

// ����� "������������� ���������� ��������"
class StudentIndirection {
public:
    void manageStudent(Student* student) {
        student_ = student;
        cout << "���������� ��������� ������ �������" << endl;
    }

    ~StudentIndirection() {
        delete student_;
        cout << "������ ������" << endl;
    }

private:
    Student* student_;
};

