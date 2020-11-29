#include <iostream>

using namespace std;

enum Size {
	TALL, GRANDE, VENTI,
};

class Beverage {
	Size size;
public:
	string description;
	Beverage() {
		description = "Unknown Beverage";
	}
	virtual void setSize(Size size) {
		this->size = size;
	}
	virtual Size getSize() {
		return size;
	}
	virtual string getDescription() {
		return description;
	}
	virtual double cost() = 0;
};

class CondimentDecorator : public Beverage {
public:
	Beverage* beverage;
	virtual string getDescription() = 0;
};

class DarkRoast : public Beverage {
public:
	DarkRoast(Size size) {
		setSize(size);
		description = "Dark Roast Coffee";
	}
	double cost() {
		double sizeCost = 0;
		if (getSize() == GRANDE) sizeCost = .2;
		else if (getSize() == VENTI) sizeCost = .3;
		return .99 + sizeCost;
	}
};

class Decaf : public Beverage {
public:
	Decaf(Size size) {
		setSize(size);
		description = "Decaf Coffee";
	}
	double cost() {
		double sizeCost = 0;
		if (getSize() == GRANDE) sizeCost = .2;
		else if (getSize() == VENTI) sizeCost = .3;
		return 1.05 + sizeCost;
	}
};

class Espresso : public Beverage {
public:
	Espresso(Size size) {
		setSize(size);
		description = "Espresso";
	}
	double cost() {
		double sizeCost = 0;
		if (getSize() == GRANDE) sizeCost = .2;
		else if (getSize() == VENTI) sizeCost = .3;
		return 1.99 + sizeCost;
	}
};

class HouseBlend : public Beverage {
public:
	HouseBlend(Size size) {
		setSize(size);
		description = "House Blend Coffee";
	}
	double cost() {
		double sizeCost = 0;
		if (getSize() == GRANDE) sizeCost = .2;
		else if (getSize() == VENTI) sizeCost = .3;
		return .89 + sizeCost;
	}
};

class Milk : public CondimentDecorator {
public:
	Milk(Beverage* beverage) {
		this->beverage = beverage;
	}
	string getDescription() {
		return beverage->getDescription() + ", Milk";
	}
	double cost() {
		return .10 + beverage->cost();
	}
};

class Mocha : public CondimentDecorator {
public:
	Mocha(Beverage* beverage) {
		this->beverage = beverage;
	}
	string getDescription() {
		return beverage->getDescription() + ", Mocha";
	}
	double cost() {
		return .20 + beverage->cost();
	}
};

class Soy : public CondimentDecorator {
public:
	Soy(Beverage* beverage) {
		this->beverage = beverage;
	}
	string getDescription() {
		return beverage->getDescription() + ", Soy";
	}
	double cost() {
		return .15 + beverage->cost();
	}
};

class Whip : public CondimentDecorator {
public:
	Whip(Beverage* beverage) {
		this->beverage = beverage;
	}
	string getDescription() {
		return beverage->getDescription() + ", Whip";
	}
	double cost() {
		return .10 + beverage->cost();
	}
};

int main(void) {
	Beverage* beverage = new Espresso(TALL);
	cout << beverage->getDescription() + " $" << beverage->cost() << '\n'; 
	Beverage* beverage2 = new DarkRoast(VENTI);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	cout << beverage2->getDescription() + " $" << beverage2->cost() << '\n';
	Beverage* beverage3 = new HouseBlend(GRANDE);
	beverage3 = new Soy(beverage3);
	beverage3 = new Mocha(beverage3);
	beverage3 = new Whip(beverage3);
	cout << beverage3->getDescription() + " $" << beverage3->cost() << '\n';
}