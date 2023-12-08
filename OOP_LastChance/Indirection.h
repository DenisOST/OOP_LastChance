#include <iostream>

// ��������� ��� �������� ���������
class SchoolRoom {
public:
    virtual void accept(class Visitor& visitor) = 0;
};

// ���������� ����� ��� ��������������� ��������
class MathRoom : public SchoolRoom {
public:
    void accept(class Visitor& visitor) override;
};

// ���������� ����� ��� ��������� ��������
class LanguageRoom : public SchoolRoom {
public:
    void accept(class Visitor& visitor) override;
};

// ���������� ����� ��� ����������� ��������
class PhysicsRoom : public SchoolRoom {
public:
    void accept(class Visitor& visitor) override;
};

// ����� ��� �������, ����������� ��������� ����������
class Visitor {
public:
    void visit(MathRoom& room) {
        std::cout << "������ �������� ������� ����������" << std::endl;
    }

    void visit(LanguageRoom& room) {
        std::cout << "������ �������� ������� �������� �����" << std::endl;
    }

    void visit(PhysicsRoom& room) {
        std::cout << "������ �������� ������� ������" << std::endl;
    }
};

// ���������� ������� accept ��� ������� ����������� ��������
void MathRoom::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void LanguageRoom::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void PhysicsRoom::accept(Visitor& visitor) {
    visitor.visit(*this);
}