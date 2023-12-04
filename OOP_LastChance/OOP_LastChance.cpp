#include "Child.h"

void TestCompositePattern() {
    Child child;

    // Добавляем черты к ребенку
    child.addFeature(new Evil());
    child.addFeature(new Kind());
    child.addFeature(new High());

    // Итерация по чертам
    Child::FeatureIterator iterator = child.getFeatureIterator();
    while (iterator.hasNext()) {
        ICharacterFeatures* feature = iterator.next();
        feature->features();
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TestCompositePattern();
}
