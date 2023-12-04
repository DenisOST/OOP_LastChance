#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "windows.h"

using namespace std;
class IRoom { // интерфейс одного пункта меню
public:
	virtual string getDescription() = 0;
	virtual float getSquare() = 0;
};

class AdditionalObject : public IRoom { // декоратор
protected:
	IRoom* room; // декорируемый объект
public:
	virtual string getDescription() = 0;
	virtual float getSquare() = 0;
	AdditionalObject(IRoom* inRoom) { room = inRoom; }
	~AdditionalObject() {
		if (room) delete room;
	}
};
class ClassRoom : public IRoom { // конкретный объект
public:
	int CountObject = 0;
	virtual string getDescription() {
		CountObject++;
		return string("Классная комната"); 
	}
	virtual float getSquare() {
		return 0;
	}
};

class RestRoom : public IRoom { // еще один декорируемый объект
public:
	int CountObject = 0;
	virtual string getDescription() {
		CountObject++;
		return string("Туалет"); 
	}
	virtual float getSquare() { 
		return 0;
	}
};
class Toilet : public AdditionalObject { // конкретный декоратор
public:
	virtual string getDescription() {
		return string("Унитаз добавлен в ") + room->getDescription();
	}
	virtual float getSquare() {	return 1 + room->getSquare();
	}
	Toilet(IRoom* inRoom) : AdditionalObject(inRoom) {}
};

class SchoolDesk : public AdditionalObject {
	// конкретный декоратор
public:
	virtual string getDescription() {
		return string("Школьная парта добавлена в ") + room->getDescription();
	}
	virtual float getSquare() { return 1 + room->getSquare(); }
	SchoolDesk(IRoom* inRoom) : AdditionalObject(inRoom) {}
	void makeMix() { cout << "К парте добавлен стул " << room->getDescription() << endl; }
};