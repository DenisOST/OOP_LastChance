#pragma once
#include "Behaviour.h"
class ICharacterFeatures
{
public:
	virtual void features() = 0; // ��������� �� ����� ����������
};

//������ �������� ��� �������� ���� �����
class Evil : public ICharacterFeatures {
public:
	void features() { cout << "� ����!" << endl; }
};
class Kind : public ICharacterFeatures {
public:
	void features() { cout << "� ������!" << endl; }
};
class High : public ICharacterFeatures {
public:
	void features() { cout << "� �������!" << endl; }
};
class Low : public ICharacterFeatures {
public:
	void features() { cout << "� ������!" << endl; }
};