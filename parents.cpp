#include <iostream>

using namespace std;

class Base {
	public:
	void printA() {
		printf("base\n");
	}
	
	void printB() {
		printf("base\n");
	}
};

class Driver : public Base {
	public:
	void printA() {
		printf("base\n");
	}
	
	void printB(Driver driver) {
		printf("base\n");
	}
};

int main() {
	Base *base = new Driver();
	Driver *driver = new Driver();

	base ->printA();
	driver -> printA();
	base ->printB(base);
	base ->printB(driver);
}
