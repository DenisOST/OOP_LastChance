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

// ILessonComponent.h
class ILessonComponent {
public:
    virtual void display() = 0;
    virtual void add(ILessonComponent* component) = 0;
    virtual void remove(ILessonComponent* component) = 0;
    virtual ILessonComponent* getChild(int index) = 0;
};

// SimpleLesson.h
class SimpleLesson : public ILessonComponent {
private:
    ILesson* lesson;

public:
    SimpleLesson(ILesson* lesson) : lesson(lesson) {}

    void display() override {
        lesson->doLesson();
    }

    void add(ILessonComponent* component) override {
        // �� ��������� ��� SimpleLesson
    }

    void remove(ILessonComponent* component) override {
        // �� ��������� ��� SimpleLesson
    }

    ILessonComponent* getChild(int index) override {
        // �� ��������� ��� SimpleLesson
        return nullptr;
    }
};

// CompositeLesson.h
class CompositeLesson : public ILessonComponent {
private:
    std::vector<ILessonComponent*> components;

public:
    void display() override {
        for (auto component : components) {
            component->display();
        }
    }

    void add(ILessonComponent* component) override {
        components.push_back(component);
    }

    void remove(ILessonComponent* component) override {
        // ������� � ������� ��������� �� �������
        auto it = std::find(components.begin(), components.end(), component);
        if (it != components.end()) {
            components.erase(it);
        }
    }

    ILessonComponent* getChild(int index) override {
        if (index >= 0 && index < components.size()) {
            return components[index];
        }
        return nullptr;
    }
};