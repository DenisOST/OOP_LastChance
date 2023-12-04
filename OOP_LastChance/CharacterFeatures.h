#pragma once
#include "Behaviour.h"
class ICharacterFeatures
{
public:
	virtual void features() = 0; // интерфейс не имеет реализации
};

//Классы делегаты для описания черт детей
class Evil : public ICharacterFeatures {
public:
	void features() { cout << "Я злой!" << endl; }
};
class Kind : public ICharacterFeatures {
public:
	void features() { cout << "Я добрый!" << endl; }
};
class High : public ICharacterFeatures {
public:
	void features() { cout << "Я высокий!" << endl; }
};
class Low : public ICharacterFeatures {
public:
	void features() { cout << "Я низкий!" << endl; }
};