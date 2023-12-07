#include <iostream>
#include <map>
#include <random>
#include <time.h>
using namespace std;

//�������� ��� ���������
class ObjectsForDriwing {
protected:
	int Code; //��� �������
public:
	ObjectsForDriwing(int Code) { this->Code = Code; }
	virtual void display() = 0;
};
class Pencil : public ObjectsForDriwing {
public:
	Pencil(int Code) : ObjectsForDriwing(Code) {}
	virtual void display() { cout << "��������" << endl; }
};
class Crayon : public ObjectsForDriwing {
public:
	Crayon(int Code) : ObjectsForDriwing(Code) {}
	virtual void display() { cout << "���������" << endl; }
};
class Paint : public ObjectsForDriwing {
public:
	Paint(int Code) : ObjectsForDriwing(Code) {}
	virtual void display() { cout << "������" << endl; }
};
//��������� - ������� ��������
class PensilCase {
private:
	typedef map<int, ObjectsForDriwing*> ArrayToolsForDraw;
	ArrayToolsForDraw mArrayToolsForDraw;
public:
	ObjectsForDriwing* getTools(int inCode) {
		cout << inCode % 10 << " grade - ";
		ArrayToolsForDraw::iterator it = mArrayToolsForDraw.find(inCode);
		if (mArrayToolsForDraw.end() == it) {//���� �� ������, �� ������� �����
			cout << "(new) - ";
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
		else {//���� ������, �� ����������
			cout << "(return) - ";
			return it->second;
		}
	}
	~PensilCase() { //��� �������� ������� ��� ��������� �������
		ArrayToolsForDraw::iterator it = mArrayToolsForDraw.begin();
		for (int i = 0; it != mArrayToolsForDraw.end(); it++, i++) {
			delete mArrayToolsForDraw[i];
		}
	}
};
//�������� ��������� �����
int randomRange(int min, int max)
{
	return int(double(rand()) / RAND_MAX * (max - min)) + min;
}

