#include "Person.h"

Person::Person(int ID, std::string name)
{
	this->ID = ID;
	this->name = name;
}

int Person::GetID() const
{//return the person's ID
	return ID;
}

const std::string Person::GetName() const
{//return the person's name
	return name;
}

std::ostream & operator<<(std::ostream & os,const Person & p)
{//printing operator
	os << p.ID << " " << p.name << "\n";
	return os;
}
