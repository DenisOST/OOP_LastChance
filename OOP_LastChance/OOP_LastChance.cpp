#include "Child.h"
#include "Indirection.h"



#include <iostream>
#include <string>
#include <map>

// Класс, представляющий канцелярский предмет
class StationeryItem {
public:
	StationeryItem(const std::string& name, float price) : name(name), price(price) {}

	const std::string& getName() const { return name; }
	float getPrice() const { return price; }

private:
	std::string name;
	float price;
};

// Класс, представляющий пенал с канцелярскими предметами
class PencilCase {
public:
	void addItem(const std::string& name, float price) {
		stationeryItems[name] = StationeryItem(name, price);
	}

	float calculateTotalPrice() const {
		float total = 0;
		for (const auto& pair : stationeryItems) {
			total += pair.second.getPrice();
		}
		return total;
	}

private:
	std::map<std::string, StationeryItem> stationeryItems;
};

int main() {
	// Создаем пенал и добавляем канцелярские предметы
	PencilCase pencilCase;
	pencilCase.addItem("Pen", 1.5);
	pencilCase.addItem("Pencil", 0.75);
	pencilCase.addItem("Notebook", 3.25);

	// Вычисляем общую стоимость канцелярских предметов в пенале
	float total = pencilCase.calculateTotalPrice();
	std::cout << "Total price of stationery items in the pencil case: $" << total << std::endl;

	return 0;
}

