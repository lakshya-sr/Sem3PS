#include <iostream>
#include <list>

using namespace std;

int main(){
	list<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_front(30);
	
	for (auto n: numbers)
		cout << n << " ";
	cout << endl;
	
	numbers.pop_back();
	numbers.pop_front();
	
	for(auto n: numbers)
		cout << n << " ";
}
