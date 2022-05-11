#include <iostream>
#include <queue>
using namespace std;



class Shelter {
private:
	queue <int> dog;
	queue <int> cat;
	queue <int> any;
	bool check[10000] = {false};
public:

	void enqueue(string option, int i) {
		if(option == "dog") {
			dog.push(i);
			any.push(i);
			check[i] = true;
		}
		else if(option == "cat") {
			cat.push(i);
			any.push(i);
			check[i] = true;
		}
	}

	int dequeueAny() {
		int no = any.front();
		
		while(check[no] == false) {
			any.pop();
			no = any.front();
		}
		check[no] = false;
		any.pop();
		
		return no;
	}

	int dequeueDog() {

		int no = dog.front();
		while(check[no] == false) {
			dog.pop();
			no = dog.front();
		}
		check[no] = false;
		dog.pop();
		return no;

	}
	int dequeueCat() {

		int no = cat.front();
		while(check[no] == false) {
			cat.pop();
			no = cat.front();
		}
		check[no] = false;
		cat.pop();
		return no;
	}
};



int main() {
	Shelter s;
	s.enqueue("dog", 1);
	s.enqueue("dog", 2);
	s.enqueue("dog", 3);
	s.enqueue("dog", 4);
	s.enqueue("cat", 5);
	s.enqueue("cat", 6);
	s.enqueue("dog", 7);
	s.enqueue("cat", 8);
	
	cout << s.dequeueAny() <<endl;
	cout << s.dequeueDog() <<endl;
	cout << s.dequeueCat() <<endl;
	

}