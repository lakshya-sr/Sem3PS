#include <iostream>

using namespace std;

int GLOBAL_ID = 0;
class Book
{
	public:
		bool available;
		string name;
		int id;
	
	Book(string book_name)
	{
		name = book_name;
		available = true;
		id = GLOBAL_ID;
		GLOBAL_ID++;
	}
	
	~Book()
	{
		cout << "Book " << name << " removed\n";
	}
	
	int issue()
	{
		if (available)
		{
			available = false;
			return id;
		}
		else
		{
			return -1;
		}
	}
};

int main()
{
	Book hamlet("Hamlet");
	cout << hamlet.available << endl;
	hamlet.issue();
	cout << hamlet.available << endl;
}
