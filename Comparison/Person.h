#ifndef _PERSON_H
#define _PERSON_H
#pragma warning(disable: 4996)

#include<iostream>
#include <string>

class Person
{
private:
	int ID;
	std::string name;

public:
	Person(int ID,std::string name);

	int GetID() const;
	const std::string GetName() const;

	friend std::ostream& operator<<(std::ostream& os,const Person& p);

};
#endif // !_PERSON_H
