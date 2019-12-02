/******************************************************************************

This program utilizes inheritance to fill out information on Employee and Manager.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;
//Main Hierachry
class Person
{
public:
	Person(string Fname, string Lname, int Age);
	string getFName() const;
	string getLName() const;
	int getAge() const;
private:
	string fname, lname;
	int age;
};
//Second Hierachry
class Employee : public Person
{
public:
	Employee(int Salary, string Name, string last, int Age);
	int getSalary() const;
private:
	int salary;
};
//Third Hierachry
class Manager : public Employee
{
public:
	Manager(int Bonus, string name, string last, int salary, int age);
	int getBonus() const;
private:
	int bonus;
};
//class Member definition with constructor initializer lists
Person::Person(string Fname, string Lname, int Age) :fname(Fname), lname(Lname), age(Age) {}
Employee::Employee(int Salary, string Name, string last, int age) : salary(Salary), Person(Name, last, age) {}
Manager::Manager(int Bonus, string name, string last, int salary, int age) : bonus(Bonus), Employee(salary, name, last, age) {}
//PLP
int Person::getAge() const { return age; }
string Person::getFName() const { return fname; }
string Person::getLName() const { return lname; }
int Employee::getSalary() const { return salary; }
int Manager::getBonus() const { return bonus; }

int main()
{
	//instantiating Employee and Manager objects
	Employee no1(45000, "Micheal", "Bennet", 64);
	Manager no2(30000, "Jarret", "Allen", 45000, 21);
	//displays information
	cout << "First Name: " << no1.getFName() << endl;
	cout << "Last Name: " << no1.getLName() << endl;
	cout << "Age: " << no1.getAge() << endl;
	cout << "Salary: " << no1.getSalary() << endl;
	cout << "First Name: " << no2.getFName() << endl;
	cout << "Last Name: " << no2.getLName() << endl;
	cout << "Age: " << no2.getAge() << endl;
	cout << "Salary: " << no2.getSalary() << endl;
	cout << "Bonus: " << no2.getBonus() << endl;
	return 0;
}

