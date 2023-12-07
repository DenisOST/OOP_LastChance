#pragma once
#include "CharacterFeatures.h"

class ILesson
{
public:
    virtual void excercise() = 0;
};

class MathLesson : public ILesson {
    //  настоящий класс для обработки данных
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
        // здесь Proxy создает реальный объект М1
    }
    ~ProxyMathLesson() { delete prox; }
};

//=======================

//  У нас есть новый класс с другим интерфейсом
class PhisicLesson {
public:
    string question1;
    string question2;

    PhisicLesson(string q1, string q2) { question1 = q1; question2 = q2; }

    void performExcercise() { cout << question1 << " и " << question2 << ", найдите мощность!" << endl; }
};

// Класс-адаптер для адаптации PhisicLesson под интерфейс ILesson
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