#pragma once
#include "Skills.h"

//Считаем
class CanCounting : public ICountingAction {	// класс поведения для детей, которые умеют считать
public:
	void counting() { cout << "Я умею считать!" << endl; }
};
class CanNotCounting : public ICountingAction {	// класс поведения для детей, которые не умеют считать
public:
	void counting() { cout << "Я не умею считать..." << endl; }
};

// Пишем
class CanWriting : public IWritingAction {		// класс поведения для детей, которые умеют писать
public:
	void writing() { cout << "Я умею писать!" << endl; }
};
class CanNotWriting : public IWritingAction {	// класс поведения для детей, которые не умеют писать
public:
	void writing() { cout << "Я не умею писать..." << endl; }
};

// Читаем
class CanReading : public IReadingAction {		// класс поведения для детей, которые умеют читать
public:
	void reading() { cout << "Я умею читать!" << endl; }
};
class CanNotReading : public IReadingAction {	// класс поведения для детей, которые не умеют читать
public:
	void reading() { cout << "Я не умею читать..." << endl; }
};

//Умножаем
class CanMultiply : public IMultiplyAction {	// класс поведения для детей, которые умеют умножать
public:
	void multiply() { cout << "Я умею умножать!" << endl; }
};
class CanNotMultiply : public IMultiplyAction {	// класс поведения для детей, которые не умеют умножать
public:
	void multiply() { cout << "Я не умею умножать..." << endl; }
};