#include "Rental.h"

// Constructors-Moved from header to here because compilation bugs out when in there
Rental::Rental() { // Default constructor--does nothing
}

Rental::Rental(User* user, Product* product, long int rented_at, long int is_due_at, long int charge) {
	this->_user = user;
	this->_product = product;
	this->_rented_at = rented_at;
	this->_is_due_at = is_due_at;
	this->_charge = charge;
}


// Getters
// Getter for _id
int Rental::id() const {
	return this->_id;
}

// Getter for _name
Product* Rental::product() const {
	return this->_product;
}

// Getter for _returned_at
long int Rental::returned_at() const {
	return this->_returned_at;
}

// Getter for _rented_at
long int Rental::rented_at() const {
	return this->_rented_at;
}

// Getter for _is_due_at
long int Rental::is_due_at() const {
	return this->_is_due_at;
}

// Getter for _charge
float Rental::charge() const {
	return this->_charge;
}

// Setters
// Setter for _id
void Rental::setId(int _id) {
	this->_id = _id;
}

// Setter for _product
void Rental::setProduct(Product* product) {
	this->_product = product;
}

// Setter for _returned_at
void Rental::setReturnDate(long int returned_at) {
	this->_returned_at = returned_at;
}

// Setter for _rented_at
void Rental::setRentedAt(long int rented_at) {
	this->_rented_at = rented_at;
}

// Setter for _is_due_at
void Rental::setDueDate(long int is_due_at) {
	this->_is_due_at = is_due_at;
}

// Setter for _charge
void Rental::setCharge(float charge) {
	this->_charge = charge;
}

// Setter for _user
void Rental::setUser(User* user) {
	this->_user = user;
}
