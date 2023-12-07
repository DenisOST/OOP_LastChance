#pragma once
#include <iostream>
#include <cctype>

using namespace std;

class CopyBook { // Интерфейс реализации
public:
	virtual void WriteTextList(const string& str) = 0;
	virtual ~CopyBook() {};
};
class Abstraction { // Абстракция
protected:
	CopyBook* impl;
public:
	virtual void WriteYourText(const string& str) = 0;
	Abstraction(CopyBook* inImpl) { impl = inImpl; }
	~Abstraction() {}
};
class Text : public Abstraction {//Вывод в формате текста
public:
	virtual void WriteYourText(const string& str) {
		impl->WriteTextList(str);
	}
	Text(CopyBook* inImpl) : Abstraction(inImpl) {}
	~Text() {}
};
class Table : public Abstraction {//Вывод в формате таблицы
public:
	virtual void WriteYourText(const string& str) {
		cout << " ";
		for (int i = 0; i < str.size(); i++) {
			cout << "_";
		}
		cout << endl;
		impl->WriteTextList("|" + str + "|");
		cout << endl;
		cout << "|";
		for (int i = 0; i < str.size(); i++) {
			cout << "_";
		}
		cout << "|";
	}
	Table(CopyBook* inImpl) : Abstraction(inImpl) {}
	~Table() {}
};
class ForTitleList : public CopyBook { // конкретная реализация для титульного листа
public:
	virtual void WriteTextList(const string& str) {
		for (int i = 0; i < str.size(); i++) {
			char ch = toupper(str[i]);
			cout << ch;
		}
	}
	~ForTitleList() {}
};
class ForSecondList : public CopyBook { // конкретная реализация для листов внутри
public:
	virtual void WriteTextList(const string& str) {
		cout << str;
	}
	~ForSecondList() {}
};
	
