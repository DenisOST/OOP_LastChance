#pragma once
#include "CharacterFeatures.h"

class ILesson
{
public:
    virtual void sum() = 0;
    virtual void sub() = 0;
    virtual void mult() = 0;
    virtual void div() = 0;
};

class MathLesson : public ILesson {
    //  настоящий класс для обработки данных
public:
    int a, b;
    virtual void sum() { cout << "Sum: " << a + b << endl; }
    virtual void sub() { cout << "Sub: " << a - b << endl; }
    virtual void mult() { cout << "Mult: " << a * b << endl; }
    virtual void div() {
        if (b == 0) {
            cout << "Div by zero!\n";
        }
        else {
            cout << "Div: " << a * b << endl;
        }
    }
    MathLesson(int inA, int inB) { a = inA;         b = inB; }
};

class ProxyMathLesson : public ILesson {
private:
    MathLesson* prox;
    void log() { cout << "a=" << prox->a << ", b=" << prox->b << endl; }

public:
    virtual void sum() { log();         prox->sum(); }
    virtual void sub() { log();         prox->sub(); }
    virtual void mult() { log();         prox->mult(); }
    virtual void div() { cout << "No div!" << endl; }

    ProxyMathLesson(int inA, int inB) {
        prox = new MathLesson(inA, inB);
        // здесь Proxy создает реальный объект М1
    }
    ~ProxyMathLesson() { delete prox; }
};

