#include "Child.h"
#include "Flyweight.h"

void TestBridgePattern() {

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));
    PensilCase* pencilCase = new PensilCase();
    const int CodeRange = 39; //Диапазон кода
    for (int i = 0; i < CodeRange; i++) {
        pencilCase->getTools(randomRange(10, CodeRange))->display();
    }
    return 0;
    delete pencilCase;
}
