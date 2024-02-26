#include "User.h"
#include "database.h"

// Constructors-Moved from header to here because compilation bugs out when in there
User::User(database &db): db(db) {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("SELECT MAX(id) FROM users");
	if (query.exec() && query.next()) {
		int maxId = query.value(0).toInt();
		this->_id = maxId + 1;
	}
	else {
		qDebug() << "Construct_User: Error getting max ID: " << query.lastError();
	}
}

User::User(database &db, string userName, string firstName, string lastName, string sk, string addr, bool role): db(db) {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("SELECT MAX(id) FROM users");
	if (query.exec() && query.next()) {
		int maxId = query.value(0).toInt();
		this->_id = maxId + 1;
	}
	else {
		qDebug() << "Construct_User: Error getting max ID: " << query.lastError();
	}
	this->_userName = userName;
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_sk = sk;
	this->_addr = addr;
	this->_role = role;
//	this->db = db;
}


// Getters
// Getter for _id
int User::id() const {
	return this->_id;
}

// Getter for _userName
string User::userName() const {
	return this->_userName;
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

// Getter for _role
bool User::role() const {
	return this->_role;
}

// Setters
// Setter for _id
void User::setId(int _id) {
	this->_id = _id;
}

// Setter for _userName
void User::setUserName(string userName) {
	this->_userName = userName;
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
void User::delete_(int id) {
	// SQL code to delete a user by ID
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("DELETE FROM users WHERE id = :id");
	query.bindValue(":id", id);

	if (!query.exec()) {
		qDebug() << "Error deleting user: " << query.lastError();
	}
}

// Write (something?)
void User::write() {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	// Check if the row exists
	query.prepare("SELECT COUNT(*) FROM users WHERE id = :id");
	query.bindValue(":id", this->_id);
	if (query.exec() && query.next() && query.value(0).toInt() > 0) {
		// The row exists, update it
		query.prepare("UPDATE users SET userName = :userName, firstName = :firstName, lastName = :lastName, sk = :sk, addr = :addr, role = :role WHERE id = :id");
	}
	else {
		// The row doesn't exist, insert a new one
		query.prepare("INSERT INTO users (id, userName, firstName, lastName, sk, addr, role) VALUES (:id, :firstName, :lastName, :sk, :addr, :role)");
	}

	// Bind the values and execute the next upcoming/prepared query
	query.bindValue(":id", this->_id);
	query.bindValue(":userName", QString::fromStdString(this->_userName));
	query.bindValue(":firstName", QString::fromStdString(this->_firstName));
	query.bindValue(":lastName", QString::fromStdString(this->_lastName));
	query.bindValue(":sk", QString::fromStdString(this->_sk));
	query.bindValue(":addr", QString::fromStdString(this->_addr));
	query.bindValue(":role", this->_role);
	if (!query.exec()) {
		qDebug() << "Error writing user to database: " << query.lastError();
	}
}
