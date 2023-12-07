#pragma once
#include "CharacterFeatures.h"

class ILesson
{
public:
    virtual void excercise() = 0;
};

class MathLesson : public ILesson {
    //  ��������� ����� ��� ��������� ������
public:
    int a, b;
    virtual void excercise()
    {
        cout << "Sum: " << a + b << endl;
        cout << "Sub: " << a - b << endl;
        cout << "Mult: " << a * b << endl;
        if (b == 0) {
            cout << "Div by zero!\n";
        }
        else {
            cout << "Div: " << a / b << endl;
        }
    }

    MathLesson(int inA, int inB) { a = inA;         b = inB; }
};

class ProxyMathLesson : public ILesson {
private:
    MathLesson* prox;
    void log() { cout << "a=" << prox->a << ", b=" << prox->b << endl; }

public:
    virtual void excercise()
    {
        log();
        prox->excercise();
    }

    ProxyMathLesson(int inA, int inB) {
        prox = new MathLesson(inA, inB);
        // ����� Proxy ������� �������� ������ �1
    }
    ~ProxyMathLesson() { delete prox; }
};

//=======================

//  � ��� ���� ����� ����� � ������ �����������
class PhisicLesson {
public:
    string question1;
    string question2;

    PhisicLesson(string q1, string q2) { question1 = q1; question2 = q2; }

    void performExcercise() { cout << question1 << " � " << question2 << ", ������� ��������!" << endl; }
};

// �����-������� ��� ��������� PhisicLesson ��� ��������� ILesson
class AdapterMathToPhisicLesson : public ILesson {
private:
    PhisicLesson* phisicLesson;

public:
    AdapterMathToPhisicLesson(PhisicLesson* lesson) : phisicLesson(lesson) {}

    virtual void excercise() override
    {
        phisicLesson->performExcercise();
    }
};