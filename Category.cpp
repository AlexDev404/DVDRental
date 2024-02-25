#include "Category.h"

// Constructors-Moved from header to here because compilation bugs out when in there
Category::Category() { // Default constructor--does nothing
}

Category::Category(string name, string desc) {
	// TODO: Read tables, find highest ID, and assign id+1
	this->_name = name;
	this->_desc = desc;
}


// Getters
// Getter for _id
int Category::id() const {
	return this->_id;
}

// Getter for _name
string Category::name() const {
	return this->_name;
}

// Getter for _desc
string Category::desc() const {
	return this->_desc;
}

// Setters
// Setter for _id
void Category::setId(int _id) {
	this->_id = _id;
}

// Setter for _name
void Category::setName(string name) {
	this->_name = name;
}

// Setter for _desc
void Category::setDesc(string desc) {
	this->_desc = desc;
}