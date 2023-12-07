#pragma once
#include <iostream>
#include <cctype>

using namespace std;

class CopyBook { // ��������� ����������
public:
	virtual void WriteText(const string& str) = 0;
	virtual ~CopyBook() {};
};
class Abstraction { // ����������
protected:
	CopyBook* impl;
public:
	virtual void WriteYourText(const string& str) = 0;
	Abstraction(CopyBook* inImpl) { impl = inImpl; }
	~Abstraction() {}
};
class Text : public Abstraction {//����� � ������� ������
public:
	virtual void WriteYourText(const string& str) {
		impl->WriteText(str);
	}
	Text(CopyBook* inImpl) : Abstraction(inImpl) {}
	~Text() {}
};
class Table : public Abstraction {//����� � ������� �������
public:
	virtual void WriteYourText(const string& str) {
		cout << " ";
		for (int i = 0; i < str.size(); i++) {
			cout << "_";
		}
		cout << endl;
		impl->WriteText("|" + str + "|");
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
class ForTitleList : public CopyBook { // ���������� ���������� ��� ���������� �����
public:
	virtual void WriteText(const string& str) {
		for (int i = 0; i < str.size(); i++) {
			char ch = toupper(str[i]);
			cout << ch;
		}
	}
	~ForTitleList() {}
};
class ForSecondList : public CopyBook { // ���������� ���������� ��� ������ ������
public:
	virtual void WriteText(const string& str) {
		cout << str;
	}
	~ForSecondList() {}
};
	
