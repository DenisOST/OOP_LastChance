#pragma once
#include "CharacterFeatures.h"

class ILesson
{
public:
    virtual void doMath() = 0;
};

class MathLesson : public ILesson {
    //  ��������� ����� ��� ��������� ������
public:
    int a, b;
    virtual void doMath() { cout << "�� ��������� �������������� �������� � ��������� �������... " << endl; }

    MathLesson(int inA, int inB) { a = inA;         b = inB; }
};

class ProxyMathLesson : public ILesson {
private:
    MathLesson* prox;
    void log() { cout << "a=" << prox->a << ", b=" << prox->b << endl; }

public:
    virtual void doMath() { log();         prox->doMath(); }

    ProxyMathLesson(int inA, int inB) {
        prox = new MathLesson(inA, inB);
        // ����� Proxy ������� �������� ������ 
    }
    ~ProxyMathLesson() { delete prox; }
};

