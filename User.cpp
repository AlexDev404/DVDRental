#include "User.h"

// Constructors-Moved from header to here because compilation bugs out when in there
User::User() { // Default constructor--does nothing
}

User::User(string firstName, string lastName, string sk, string addr, bool role) {
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_sk = sk;
	this->_addr = addr;
	this->_role = role;
}


// Getters
// Getter for _id
int User::id() const {
	return this->_id;
}

// Getter for _firstName
string User::firstName() const {
	return this->_firstName;
}

// Getter for _lastName
string User::lastName() const {
	return this->_lastName;
}

// Getter for _sk
string User::sk() const {
	return this->_sk;
}

// Getter for _addr
string User::addr() const {
	return this->_addr;
}

// Getter for _desc
bool User::role() const {
	return this->_role;
}

// Setters
// Setter for _id
void User::setId(int _id) {
	this->_id = _id;
}

// Setter for _firstName
void User::setFirstName(string firstName) {
	this->_firstName = firstName;
}

// Setter for _lastName
void User::setLastName(string lastName) {
	this->_lastName = lastName;
}

// Setter for _sk
void User::setSk(string sk) {
	this->_sk = sk;
}

// Setter for _addr
void User::setAddr(string addr) {
	this->_addr = addr;
}

// Setter for _role
void User::setRole(bool role) {
	this->_role = role;
}

// Utilities
// Delete a user by ID
void delete_(int id) {
	// TODO: SQL code to delete a user by ID
}