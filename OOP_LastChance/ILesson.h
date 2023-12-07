#pragma once
#include "CharacterFeatures.h"

class ILesson
{
public:
    virtual void doLesson() = 0;
};

class MathLesson : public ILesson {
public:
    virtual void doLesson() { cout << "«адание по математике было выполнено!" << endl; }
    MathLesson(){}
};

class BioLesson : public ILesson {
public:
    virtual void doLesson() { cout << "«адание по биологии было выполнено!" << endl; }
    BioLesson() {}
};

class EngLesson : public ILesson {
public:
    virtual void doLesson() { cout << "«адание по английскому было выполнено!" << endl; }
    EngLesson() {}
};

//=====================================//