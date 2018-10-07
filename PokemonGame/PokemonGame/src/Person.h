#pragma once

#include <string>

class Person {
protected:
	unsigned char m_gender = 'n';
	std::string m_name = "null";
	int m_x , m_y;
public:
	Person();
	Person(int x, int y);
	~Person();

	//getter declarations
	unsigned char getGender() const;
	std::string getName() const;
	int getXCoordinate() const;
	int getYCoordinate() const;

	//setter declarations
	void setGender(unsigned char gender);
	void setName(std::string name);
	void setXCoordinate(int x);
	void setYCoordinate(int y);
};
