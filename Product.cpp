#include "Product.h"
#include "database.h"

// Constructors-Moved from header to here because compilation bugs out when in there
Product::Product(database& db) : db(db) {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("SELECT MAX(id) FROM products");
	if (query.exec() && query.next()) {
		int maxId = query.value(0).toInt();
		this->_id = maxId + 1;
	}
	else {
		qDebug() << "Construct_Product: Error getting max ID: " << query.lastError();
	}
}

Product::Product(database& db, string name, string desc, bool rnt_status, float price, bool type, float rating): db(db) {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("SELECT MAX(id) FROM products");
	if (query.exec() && query.next()) {
		int maxId = query.value(0).toInt();
		this->_id = maxId + 1;
	}
	else {
		qDebug() << "Construct_Product: Error getting max ID: " << query.lastError();
	}
	this->_name = name;
	this->_desc = desc;
	this->_rnt_status = rnt_status;
	this->_type = type;
	this->_price = price;
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

// Getter for _price
float Product::price() const {
	return this->_price;
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

// Setter for _price
void Product::setPrice(float price) {
	this->_price = price;
}

// Setter for _rating
void Product::setRating(float rating) {
	this->_rating = rating;
}

// Utility
// Delete a product by ID
void Product::delete_(int id) {
	// SQL code to delete a products by ID
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("DELETE FROM products WHERE id = :id");
	query.bindValue(":id", id);

	if (!query.exec()) {
		qDebug() << "Error deleting product: " << query.lastError();
	}
}

// Write (something?)
void Product::write() {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	// Check if the row exists
	query.prepare("SELECT COUNT(*) FROM products WHERE id = :id");
	query.bindValue(":id", this->_id);
	if (query.exec() && query.next() && query.value(0).toInt() > 0) {
		// The row exists, update it
		query.prepare("UPDATE products SET c_id = :cid, name = :name, desc = :desc, rnt_status = :rnt_status, type = :type, price = :price, rating = :rating WHERE id = :id");
	}
	else {
		// The row doesn't exist, insert a new one
		query.prepare("INSERT INTO products (id, c_id, name, desc, rnt_status, type, price, rating) VALUES (:id, :cid, :name, :desc, :rnt_status, :type, :price, :rating)");
	}

	// Bind the values and execute the next upcoming/prepared query
	query.bindValue(":id", this->_id);
	query.bindValue(":cid", this->_c_id);
	query.bindValue(":name", QString::fromStdString(this->_name));
	query.bindValue(":desc", QString::fromStdString(this->_desc));
	query.bindValue(":rnt_status", this->_rnt_status);
	query.bindValue(":type", this->_type);
	query.bindValue(":price", this->_price);
	query.bindValue(":rating", this->_rating);
	if (!query.exec()) {
		qDebug() << "Error writing product to database: " << query.lastError();
	}
}
