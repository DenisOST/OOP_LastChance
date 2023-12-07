#include "Child.h"
#include "Facade.h"

void TestBridgePattern() {

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Classroom classroom;

    classroom.BeginLesson();

    cout << "--------------" << endl;

    classroom.MiddleLesson();

    cout << "--------------" << endl;

    classroom.EndLesson();
}