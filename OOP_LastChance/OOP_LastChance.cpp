#include "Child.h"

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
    ILesson* proxy = new ProxyMathLesson(6, 0);

    Evil* evil = new Evil();
    Kind* kind = new Kind();
    High* high = new High();
    Low* low = new Low();

    Preschooler PS1, PS2;
    Preschooler* PS3 = new Preschooler(c, w, r, m, "Илюха Масло");
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
    OS1.SetTask(proxy);
    OS1.CompleteLesson();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TestDelegationAndProxy();
}
