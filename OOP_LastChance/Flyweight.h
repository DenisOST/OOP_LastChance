#include <iostream>
#include <map>
#include <random>
#include <time.h>
using namespace std;

//Предметы для рисования
class ObjectsForDriwing {
protected:
	int Colour; //Код сигнала
public:
	ObjectsForDriwing(int Colour) { this->Colour = Colour; }
	virtual void display() = 0;
};
class Pencil : public ObjectsForDriwing {
public:
	Pencil(int Colour) : ObjectsForDriwing(Colour) {}
	virtual void display() { cout << "Карандаш" << endl; }
};
class Crayon : public ObjectsForDriwing {
public:
	Crayon(int Colour) : ObjectsForDriwing(Colour) {}
	virtual void display() { cout << "Фломастер" << endl; }
};
class Paint : public ObjectsForDriwing {
public:
	Paint(int Colour) : ObjectsForDriwing(Colour) {}
	virtual void display() { cout << "Краска" << endl; }
};
//Компьютер - фабрика сигналов
class PensilCase {
private:
	typedef map<int, ObjectsForDriwing*> ArrayToolsForDraw;
	ArrayToolsForDraw mArrayToolsForDraw;
public:
	ObjectsForDriwing* getTools(int inCode) {
		cout << inCode % 10 << " цвет ";
		ArrayToolsForDraw::iterator it = mArrayToolsForDraw.find(inCode);
		if (mArrayToolsForDraw.end() == it) {//Если не найден, то создаем новый
			cout << "новый - ";
			ObjectsForDriwing* f;
			if (inCode / 10 == 1)
				f = new Pencil(inCode);
			else {
				if (inCode / 10 == 2)
					f = new Crayon(inCode);
				else
					f = new Paint(inCode);
			}
			mArrayToolsForDraw[inCode] = f;
			return f;
		}
		else {//Если найден, то возвращаем
			cout << "уже есть - ";
			return it->second;
		}
	}
	~PensilCase() { //При удалении удаляем все созданные сигналы
		ArrayToolsForDraw::iterator it = mArrayToolsForDraw.begin();
		for (int i = 0; it != mArrayToolsForDraw.end(); it++, i++) {
			delete mArrayToolsForDraw[i];
		}
	}
};
//Получить случайное число
int randomRange(int min, int max)
{
	return int(double(rand()) / RAND_MAX * (max - min)) + min;
}

