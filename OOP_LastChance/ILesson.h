#pragma once
#include "CharacterFeatures.h"

class ILesson
{
public:
    virtual void doLesson() = 0;
};

class MathLesson : public ILesson {
public:
    virtual void doLesson() { cout << "������� �� ���������� ���� ���������!" << endl; }
    MathLesson(){}
};

class BioLesson : public ILesson {
public:
    virtual void doLesson() { cout << "������� �� �������� ���� ���������!" << endl; }
    BioLesson() {}
};

class EngLesson : public ILesson {
public:
    virtual void doLesson() { cout << "������� �� ����������� ���� ���������!" << endl; }
    EngLesson() {}
};

//=====================================//