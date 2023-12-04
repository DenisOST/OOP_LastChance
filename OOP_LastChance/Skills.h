#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "windows.h"

using namespace std;

class ICountingAction { //считать
public:
	virtual void counting() = 0; // интерфейс не имеет реализации
};

class IWritingAction { //писать
public:
	virtual void writing() = 0; // интерфейс не имеет реализации
};

class IReadingAction { //читать
public:
	virtual void reading() = 0; // интерфейс не имеет реализации
};

class IMultiplyAction { //умножать
public:
	virtual void multiply() = 0; // интерфейс не имеет реализации
};

