#pragma once
#include "CharacterFeatures.h"

class ILesson
{
public:
    virtual void doMath() = 0;
};

class MathLesson : public ILesson {
    //  настоящий класс для обработки данных
public:
    int a, b;
    virtual void doMath() { cout << "Мы выполняем арифметические операции с заданными числами... " << endl; }

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
        // здесь Proxy создает реальный объект 
    }
    ~ProxyMathLesson() { delete prox; }
};

