#include "Person.h"

Person::Person() {}

Person::Person(int x, int y) 
	:m_x(x), m_y(y) {}

Person::~Person() {}


//getter definitions
unsigned char Person::getGender() const {
	return m_gender;
}

std::string Person::getName() const{
	return m_name;
}

int Person::getXCoordinate() const {
	return m_x;
}

int Person::getYCoordinate() const {
	return m_y;
}

//setter definitions
void Person::setGender(unsigned char gender) {
	m_gender = gender;
}

void Person::setName(std::string name) {
	m_name = name;
}

void Person::setXCoordinate(int x) {
	m_x = x;
}

void Person::setYCoordinate(int y) {
	m_y = y;
}