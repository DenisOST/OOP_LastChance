#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "windows.h"

using namespace std;
class IRoom { // ��������� ������ ������ ����
public:
	virtual string getDescription() = 0;
	virtual float getSquare() = 0;
};

class AdditionalObject : public IRoom { // ���������
protected:
	IRoom* room; // ������������ ������
public:
	virtual string getDescription() = 0;
	virtual float getSquare() = 0;
	AdditionalObject(IRoom* inRoom) { room = inRoom; }
	~AdditionalObject() {
		if (room) delete room;
	}
};
class ClassRoom : public IRoom { // ���������� ������
public:
	int CountObject = 0;
	virtual string getDescription() {
		CountObject++;
		return string("�������� �������"); 
	}
	virtual float getSquare() {
		return 0;
	}
};

class RestRoom : public IRoom { // ��� ���� ������������ ������
public:
	int CountObject = 0;
	virtual string getDescription() {
		CountObject++;
		return string("������"); 
	}
	virtual float getSquare() { 
		return 0;
	}
};
class Toilet : public AdditionalObject { // ���������� ���������
public:
	virtual string getDescription() {
		return string("������ �������� � ") + room->getDescription();
	}
	virtual float getSquare() {	return 1 + room->getSquare();
	}
	Toilet(IRoom* inRoom) : AdditionalObject(inRoom) {}
};

class SchoolDesk : public AdditionalObject {
	// ���������� ���������
public:
	virtual string getDescription() {
		return string("�������� ����� ��������� � ") + room->getDescription();
	}
	virtual float getSquare() { return 1 + room->getSquare(); }
	SchoolDesk(IRoom* inRoom) : AdditionalObject(inRoom) {}
	void makeMix() { cout << "� ����� �������� ���� " << room->getDescription() << endl; }
};