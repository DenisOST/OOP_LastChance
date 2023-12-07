#include <iostream>
#include <map>
#include <random>
#include <time.h>
using namespace std;

class Teacher {
public:
	void EnterRoom() {
		cout << "������� ����� � �������" << endl;
	}
	void CheckHW()
	{
		cout << "������� ��������� �������� �������" << endl;
	}
	void TeacherReportsGrades()
	{
		cout << "������� ������� ������ ��������" << endl;
	}
};

class Student {
public:
	void SitAtDesk() {
		cout << "������� ���� �� �����" << endl;
	}
	void GiveHW()
	{
		cout << "������� ���� �� �������� �������� �������" << endl;
	}
	void LeftRoom() {
		cout << "������� ����" << endl;
	}
};

class Lesson {
public:
	void BeginLesson() {
		cout << "��������� ������, ���� �������" << endl;
	}
	void EndLesson()
	{
		cout << "��������� ������, ���� ��������" << endl;
	}
};

class Classroom {
private:
	Teacher teacher;
	Student student;
	Lesson lesson;
public:
	void BeginLesson() {
		lesson.BeginLesson();
		teacher.EnterRoom();
		student.SitAtDesk();
	}
	void MiddleLesson() {
		student.GiveHW();
		teacher.CheckHW();
		teacher.TeacherReportsGrades();
	}
	void EndLesson() {
		lesson.EndLesson();
		student.LeftRoom();
	}
};