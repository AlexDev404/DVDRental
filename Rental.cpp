#include "Rental.h"
#include "database.h"

// Constructors-Moved from header to here because compilation bugs out when in there
Rental::Rental(database& db): db(db) {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("SELECT MAX(id) FROM rentals");
	if (query.exec() && query.next()) {
		int maxId = query.value(0).toInt();
		this->_id = maxId + 1;
	}
	else {
		qDebug() << "Construct_Rental: Error getting max ID: " << query.lastError();
	}
}

Rental::Rental(database& db, User* user, Product* product, long int rented_at, long int is_due_at, float charge) : db(db) {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("SELECT MAX(id) FROM rentals");
	if (query.exec() && query.next()) {
		int maxId = query.value(0).toInt();
		this->_id = maxId + 1;
	}
	else {
		qDebug() << "Construct_Rental: Error getting max ID: " << query.lastError();
	} {
		this->_user = user;
		this->_product = product;
		this->_rented_at = rented_at;
		this->_is_due_at = is_due_at;
		this->_charge = charge;
	}
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

// Utility
// Delete a product by ID
void Rental::delete_(int id) {
	// SQL code to delete a products by ID
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("DELETE FROM rentals WHERE id = :id");
	query.bindValue(":id", id);

	if (!query.exec()) {
		qDebug() << "Error deleting rental: " << query.lastError();
	}
}

void Rental::write() {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	// Check if the row exists
	query.prepare("SELECT COUNT(*) FROM rentals WHERE id = :id");
	query.bindValue(":id", this->_id);
	if (query.exec() && query.next() && query.value(0).toInt() > 0) {
		// The row exists, update it
		query.prepare("UPDATE rentals SET product = :product_id, returned_at = :returned_at, rented_at = :rented_at, is_due_at = :is_due_at, charge = :charge, user_id = :user_id WHERE id = :id");
	}
	else {
		// The row doesn't exist, insert a new one
		query.prepare("INSERT INTO rentals (id, product, returned_at, rented_at, is_due_at, charge, user_id) VALUES (:id, :product_id, :returned_at, :rented_at, :is_due_at, :charge, :user_id)");
	}

	// Bind the values and execute the next upcoming/prepared query
	query.bindValue(":id", this->_id);
	query.bindValue(":product_id", this->_product->id());
	query.bindValue(":returned_at", static_cast<int>(this->_returned_at));
	query.bindValue(":rented_at", static_cast<int>(this->_rented_at));
	query.bindValue(":is_due_at", static_cast<int>(this->_is_due_at));
	query.bindValue(":charge", this->_charge);
	query.bindValue(":user_id", this->_user->id());
	if (!query.exec()) {
		qDebug() << "Error writing rental to database: " << query.lastError();
	}
}
