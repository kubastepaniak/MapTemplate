#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
	string name;
	string position;
	unsigned int age;

	Employee() { };

	Employee(string n, string p, unsigned int a)
		:name(n), position(p), age(a) { };

	friend std::ostream& operator<< (std::ostream& out, const Employee& e) {
		out << "Name: " << e.name << " \t" << "Position: " << e.position << " \t" << "Age: " << e.age;
		return out;
	}
};