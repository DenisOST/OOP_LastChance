#include "Child.h"
#include "IRoom.h"

void TestAdapter()
{
    ILesson* first = new MathLesson(12, 6);
    // Использование адаптера: 
    // Создаем объект класса PhisicLesson с двумя вопросами 
    PhisicLesson* pl = new PhisicLesson("Сила тока" , "Напряжение");

    // Создаем объект класса-адаптера, передавая ему указатель на объект класса PhisicLesson
    AdapterMathToPhisicLesson* adapter = new AdapterMathToPhisicLesson(pl);

    // Теперь мы можем использовать объект класса-адаптера как объект класса ILesson adapter->excercise(); 
    // выведет “Сила тока и Напряжение найти произведение!”

    Preschooler* PS3 = new Preschooler();

    Oldschooler OS1;

    cout << "Сергей Масло:" << endl;
    PS3->SetTask(first);
    PS3->CompleteLesson();

    cout <<  endl;

    cout << "Михаил Черепной:" << endl;
    OS1.SetTask(adapter);
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

    TestAdapter();
}
