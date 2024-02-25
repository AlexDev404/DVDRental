#include "Product.h"

// Constructors-Moved from header to here because compilation bugs out when in there
Product::Product() { // Default constructor--does nothing
}

Product::Product(string name, string desc, bool rnt_status, bool type, float rating) {
	this->_name = name;
	this->_desc = desc;
	this->_rnt_status = rnt_status;
	this->_type = type;
	this->_rating = rating;
}


// Getters
// Getter for _id
int Product::id() const {
	return this->_id;
}

// Getter for c_id
int Product::c_id() const {
	return this->_c_id;
}

// Getter for _name
string Product::name() const {
	return this->_name;
}

// Getter for _desc
string Product::desc() const {
	return this->_desc;
}

// Getter for _rnt_status
bool Product::rnt_status() const {
	return this->_rnt_status;
}

// Getter for _type
bool Product::type() const {
	return this->_type;
}

// Getter for _rating
float Product::rating() const {
	return this->_rating;
}

// Setters
// Setter for _id
void Product::setId(int _id) {
	this->_id = _id;
}

// Setter for _c_id
void Product::setcId(int c_id) {
	this->_c_id = c_id;
}

// Setter for _name
void Product::setName(string name) {
	this->_name = name;
}

// Setter for _desc
void Product::setDesc(string desc) {
	this->_desc = desc;
}

// Setter for _rnt_status
void Product::setStatus(bool rnt_status) {
	this->_rnt_status = rnt_status;
}

// Setter for _type
void Product::setType(bool type) {
	this->_type = type;
}

// Setter for _rating
void Product::setRating(float rating) {
	this->_rating = rating;
}
