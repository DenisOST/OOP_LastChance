#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "windows.h"

using namespace std;

class ICountingAction { //�������
public:
	virtual void counting() = 0; // ��������� �� ����� ����������
};

class IWritingAction { //������
public:
	virtual void writing() = 0; // ��������� �� ����� ����������
};

class IReadingAction { //������
public:
	virtual void reading() = 0; // ��������� �� ����� ����������
};

class IMultiplyAction { //��������
public:
	virtual void multiply() = 0; // ��������� �� ����� ����������
};

