#include "Child.h"
#include "IRoom.h"

void TestDelegationAndProxy()
{
    CanCounting* c = new CanCounting();
    CanWriting* w = new CanWriting();
    CanReading* r =  new CanReading();
    CanMultiply* m =  new CanMultiply();

    CanNotCounting* cn = new CanNotCounting();
    CanNotWriting* wn = new CanNotWriting();
    CanNotReading* rn = new CanNotReading();
    CanNotMultiply* mn = new CanNotMultiply();

    ILesson* first = new MathLesson(6, 0);
    NewMathLesson* newLesson = new NewMathLesson();
    ILesson* adaptedLesson = new AdapterNewMathLesson(newLesson);

    Evil* evil = new Evil();
    Kind* kind = new Kind();
    High* high = new High();
    Low* low = new Low();

    Preschooler PS1, PS2;
    Preschooler* PS3 = new Preschooler(c, w, r, m, "Илюха Жопич");
    PS1.DisplaySkills();
    PS2.DisplaySkills();
    PS3->DisplaySkills();

    Schooler S1;
    S1.DisplaySkills();

    Oldschooler OS1;
    OS1.DisplaySkills();

    PS3->addFeature(evil);
    PS3->addFeature(low);
    cout << "Илюха Жопич:" << endl;
    PS3->DisplayFeatures();
    PS3->SetTask(first);
    PS3->CompleteLesson();

    OS1.addFeature(kind);
    OS1.addFeature(high);
    cout << "Михаил Черепной:" << endl;
    OS1.DisplayFeatures();
    OS1.SetTask(adaptedLesson);
    OS1.CompleteLesson();
}

void TestDecorator()
{
    ClassRoom* classroom = new ClassRoom();
    cout << "Создана классная комната!" << endl;
    cout << "Количество объектов в классной комнате: " << classroom->CountObject << endl;
    RestRoom* restroom = new RestRoom();
    cout << "Создан туалет!"  << endl;
    cout << "Количество объектов в туалете: " << restroom->CountObject << endl;

    Toilet* toilet[5];
    for (int i = 0; i < 5; i++)
    {
        toilet[i] = new Toilet(restroom);
        cout << toilet[i]->getDescription() << endl;
    }
    SchoolDesk* desk = new SchoolDesk(classroom);
    cout << desk->getDescription() << endl;
    cout << "Количество объектов в туалете: " << restroom->CountObject << endl;
    cout << "Количество объектов в классной комнате: " << classroom->CountObject << endl;
    Toilet* toilet1 = new Toilet(classroom);
    cout << toilet1->getDescription() << endl;
    cout << "Количество объектов в классной комнате: " << classroom->CountObject << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TestDecorator();
}
