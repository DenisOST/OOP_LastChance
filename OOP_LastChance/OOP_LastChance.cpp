#include "Child.h"
#include "Bridge.h"

void TestBridgePattern() {
    // Создаем конкретные реализации действий и черт
    ICountingAction* canCount = new CanCounting();
    ICharacterFeatures* evil = new Evil();

    // Создаем абстракции с конкретными реализациями
    ChildAction* countingAction = new CountingChildAction(canCount);
    ChildFeatures* characterFeatures = new CharacterChildFeatures(evil);

    // Выполняем действия и отображаем черты
    countingAction->performAction();
    characterFeatures->displayFeatures();

    // Освобождаем память
    delete canCount;
    delete evil;
    delete countingAction;
    delete characterFeatures;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	//Текст капсом для титульного листа
	Text* txtForTitle = new Text(new ForTitleList());
	cout << "Текст капсом для титульного листа: " << endl;
	txtForTitle->WriteYourText("Walter");
	//Текст не капсом для внутреннего листа
	Text* txtForSecond = new Text(new ForSecondList());
	cout << endl << endl << "Текст не капсом для внутреннего листа: " << endl;
	txtForSecond->WriteYourText("Walter");
	//Обведённый текст для титульного листа
	Table* tblForTitle = new Table(new ForTitleList());
	cout << endl << endl << "Обведённый текст для титульного листа: " << endl;
	tblForTitle->WriteYourText("Walter");
	//Обведённый текст для внутреннего листа
	Table* tblForSecond = new Table(new ForSecondList());
	cout << endl << endl << "Обведённый текст для внутреннего листа: " << endl;
	tblForSecond->WriteYourText("Walter");
	delete tblForTitle, tblForSecond;
	delete txtForTitle, txtForSecond;
	return 0;
}
