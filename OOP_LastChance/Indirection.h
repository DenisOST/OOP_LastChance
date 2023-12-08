#include <iostream>

// Интерфейс для школьных кабинетов
class SchoolRoom {
public:
    virtual void accept(class Visitor& visitor) = 0;
};

// Конкретный класс для математического кабинета
class MathRoom : public SchoolRoom {
public:
    void accept(class Visitor& visitor) override;
};

// Конкретный класс для языкового кабинета
class LanguageRoom : public SchoolRoom {
public:
    void accept(class Visitor& visitor) override;
};

// Конкретный класс для физического кабинета
class PhysicsRoom : public SchoolRoom {
public:
    void accept(class Visitor& visitor) override;
};

// Класс для ученика, реализующий интерфейс посетителя
class Visitor {
public:
    void visit(MathRoom& room) {
        std::cout << "Ученик посещает кабинет математики" << std::endl;
    }

    void visit(LanguageRoom& room) {
        std::cout << "Ученик посещает кабинет русского языка" << std::endl;
    }

    void visit(PhysicsRoom& room) {
        std::cout << "Ученик посещает кабинет физики" << std::endl;
    }
};

// Реализация методов accept для каждого конкретного кабинета
void MathRoom::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void LanguageRoom::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void PhysicsRoom::accept(Visitor& visitor) {
    visitor.visit(*this);
}