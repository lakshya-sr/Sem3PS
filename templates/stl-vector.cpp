#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	
	for (auto n: numbers)
		cout << n << " ";
	cout << endl;
	
	numbers.pop_back();
	numbers.pop_back();
	
	for(auto n: numbers)
		cout << n << " ";
}
