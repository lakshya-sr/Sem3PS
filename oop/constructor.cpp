#include <iostream>

using namespace std;

class Student
{
	public:
		int rollnumber;
		string name;
	
	Student()
	{
		cout << "Default constructor\n";
		cout << "Enter name\n";
		cin >> name;
		cout << "Enter rollno\n";
		cin >> rollnumber;	
	}
	
	Student(string n, int r)
	{
		cout << "Parameterized constructor\n";
		name = n;
		rollnumber = r;
	}
	
	Student(const Student &s)
	{
		cout << "Copy constructor\n";
		name = s.name;
		rollnumber = s.rollnumber;
	}
	
	~Student()
	{
		cout << rollnumber << "-" << name << " deinitialized\n";
	}
	
	void display()
	{
		cout << "Name: " << name << "\n";
		cout << "Roll No: " << rollnumber << "\n";
	}
};

int main()
{
	Student s1("Lakshya", 204);
	s1.display();
	
	Student s2 = s1;
	s2.display();
	return 0;
}
