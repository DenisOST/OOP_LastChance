#pragma once
#include "Skills.h"

//�������
class CanCounting : public ICountingAction {	// ����� ��������� ��� �����, ������� ����� �������
public:
	void counting() { cout << "� ���� �������!" << endl; }
};
class CanNotCounting : public ICountingAction {	// ����� ��������� ��� �����, ������� �� ����� �������
public:
	void counting() { cout << "� �� ���� �������..." << endl; }
};

// �����
class CanWriting : public IWritingAction {		// ����� ��������� ��� �����, ������� ����� ������
public:
	void writing() { cout << "� ���� ������!" << endl; }
};
class CanNotWriting : public IWritingAction {	// ����� ��������� ��� �����, ������� �� ����� ������
public:
	void writing() { cout << "� �� ���� ������..." << endl; }
};

// ������
class CanReading : public IReadingAction {		// ����� ��������� ��� �����, ������� ����� ������
public:
	void reading() { cout << "� ���� ������!" << endl; }
};
class CanNotReading : public IReadingAction {	// ����� ��������� ��� �����, ������� �� ����� ������
public:
	void reading() { cout << "� �� ���� ������..." << endl; }
};

//��������
class CanMultiply : public IMultiplyAction {	// ����� ��������� ��� �����, ������� ����� ��������
public:
	void multiply() { cout << "� ���� ��������!" << endl; }
};
class CanNotMultiply : public IMultiplyAction {	// ����� ��������� ��� �����, ������� �� ����� ��������
public:
	void multiply() { cout << "� �� ���� ��������..." << endl; }
};