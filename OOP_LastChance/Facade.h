#include <iostream>
#include <map>
#include <random>
#include <time.h>
using namespace std;

class Teacher {
public:
	void EnterRoom() {
		cout << "Учитель вошёл в комнату" << endl;
	}
	void CheckHW()
	{
		cout << "Учитель проверяет домашнее задание" << endl;
	}
	void TeacherReportsGrades()
	{
		cout << "Учитель сообщил оценки ученикам" << endl;
	}
};

class Student {
public:
	void SitAtDesk() {
		cout << "Ученики сели за парты" << endl;
	}
	void GiveHW()
	{
		cout << "Ученики дают на проверку домашнее задание" << endl;
	}
	void LeftRoom() {
		cout << "Ученики ушли" << endl;
	}
};

class Lesson {
public:
	void BeginLesson() {
		cout << "Прозвенел звонок, урок начался" << endl;
	}
	void EndLesson()
	{
		cout << "Прозвенел звонок, урок кончился" << endl;
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