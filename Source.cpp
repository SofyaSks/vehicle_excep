#include <iostream>
#include <string>
#include <time.h>
using namespace std;


class Vehicle {

public:
	Vehicle() {}

	void setCapacity(int cap) {
		capacity = cap;
	}

	int getCapacity() {
		return capacity;
	}

	void setMove(string Mtype) {
		moveType = Mtype;
	}

	string getMove() {
		return moveType;
	}

private:
	int capacity;
	string moveType;
};

class Mechanical : public Vehicle {

public:
	Mechanical() {}

	void FillIn() {
		int num;
		cout << "Enter vehicle capacity: ";
		try {
			cin >> num;
			if (num < 500)
				throw "invalid capacity";
		}
		catch(const char* s) {
			cout << "Error - " << s << endl;
		}
		setCapacity(num);
		try {
			cout << "Enter wheels number: ";
			cin >> wheels;
			if (wheels < 2)
				throw 2;
			if (wheels > 10)
				throw "too much";
		}
		catch (int n) {
			cout << "incorrect wheels amount - " << n << endl;
		}
		catch (const char* s) {
			cout << "incorrect wheels amount - " << s << endl;
		}
		catch (...) {
			cout << "something is wrong...";
		}
		cout << "Enter the color: ";
		cin >> color;
		cout << "Can be used during winter? (1 - yes; 0 - no): ";
		cin >> winter;
		cout << "Enter the maximum possible speed: ";
		cin >> maxSpeed;
	}

protected:
	int wheels;
	string color;
	bool winter;
	int maxSpeed;
};

class Car : public Mechanical {

public:
	Car() {}

	void setBaggage() {
		try {
			int bag;
			cout << "Enter the baggage capacity: ";
			cin >> bag;
			if (bag > 1000)
				throw bag;
			else
			baggage = bag;
		}
		catch (int n) {
			cout << "capacity error " << n << endl;
		}

	}

	int getBaggage() {
		return baggage;
	}


	void PrintCar(Car tmp) {
		tmp.setMove("ground");
		cout << "\n\nYour vehicle is Car\nType of move: " <<
			tmp.getMove() << "\nCapacity: " << tmp.getCapacity() <<
			"\nNumber of wheels: " << wheels << "\nThe color: " << color;
		if (winter == 1) {
			cout << "\nIt can be used during winter";
		}
		else
			cout << "\nIt can not be used during winter";
		cout << "\nCar maximum speed: " << maxSpeed << endl;
		cout << "Baggage capacity: " << getBaggage() << endl;
	}

private:
	int baggage;
};

class Motorcycle : public Mechanical {

public:
	Motorcycle() {}

	void setCart() {
		int cart_;
		cout << "Does the Motorcycle have cart? (1 - yes; 0 - no): ";
		cin >> cart_;
		cart = cart_;
	}

	bool getCart() {
		return cart;
	}

	void PrintMotorcycle(Motorcycle tmp) {
		tmp.setMove("ground");
		cout << "\n\nYour vehicle is Motorcycle\nType of move: " <<
			tmp.getMove() << "\nCapacity: " << tmp.getCapacity() <<
			"\nNumber of wheels: " << wheels << "\nThe color: " << color;
		if (winter == 1) {
			cout << "\nIt can be used during winter";
		}
		else
			cout << "\nIt can not be used during winter";
		cout << "\nMotorcycle maximum speed: " << maxSpeed;

		if (cart == 1) {
			cout << "\nMotorcycle has cart";
		}
		else
			cout << "\nNo cart in Motorcycle";

	}

private:
	bool cart;
};

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	Car c1;
	Motorcycle m1;

	int choice;
	cout << "Press 1 for filling in Car characterics / press 0 for Motorcycle -> ";
	cin >> choice;

	
		while (choice != 1 || choice != 0) {
			cout << "Press 1 for filling in Car characterics / press 0 for Motorcycle -> ";
			cin >> choice;
			if (choice == 1 || choice == 0) {
				break;
			}
		}
	

	if (choice == 1) {

		c1.FillIn();
		c1.setBaggage();
		c1.PrintCar(c1);
	}
	else {
		m1.FillIn();
		m1.setCart();
		m1.PrintMotorcycle(m1);
	}

	return 0;
}