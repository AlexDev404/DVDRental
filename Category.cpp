#include "Category.h"
#include "database.h"

// Constructors-Moved from header to here because compilation bugs out when in there
Category::Category(database& db): db(db) {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("SELECT MAX(id) FROM categories");
	if (query.exec() && query.next()) {
		int maxId = query.value(0).toInt();
		this->_id = maxId + 1;
	}
	else {
		qDebug() << "Construct_Category: Error getting max ID: " << query.lastError();
	}
}

Category::Category(database& db, string name, string desc): db(db) {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("SELECT MAX(id) FROM categories");
	if (query.exec() && query.next()) {
		int maxId = query.value(0).toInt();
		this->_id = maxId + 1;
	} else {
		qDebug() << "Construct_Category: Error getting max ID: " << query.lastError();
	}

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

// Utility
// Delete a category by ID
void Category::delete_(int id) {
	// SQL code to delete a category by ID
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	query.prepare("DELETE FROM categories WHERE id = :id");
	query.bindValue(":id", id);

	if (!query.exec()) {
		qDebug() << "Error deleting category: " << query.lastError();
	}
}

// Write (something?)
void Category::write() {
	QSqlDatabase database = db.getInstance();
	QSqlQuery query(database);

	// Check if the row exists
	query.prepare("SELECT COUNT(*) FROM categories WHERE id = :id");
	query.bindValue(":id", this->_id);
	if (query.exec() && query.next() && query.value(0).toInt() > 0) {
		// The row exists, update it
		query.prepare("UPDATE categories SET name = :name, desc = :desc WHERE id = :id");
	}
	else {
		// The row doesn't exist, insert a new one
		query.prepare("INSERT INTO categories (id, name, desc) VALUES (:id, :name, :desc)");
	}

	// Bind the values and execute the next upcoming/prepared query
	query.bindValue(":id", this->_id);
	query.bindValue(":name", QString::fromStdString(this->_name));
	query.bindValue(":desc", QString::fromStdString(this->_desc));  // JavaScript's easier, tbh
	if (!query.exec()) {
		qDebug() << "Error writing category to database: " << query.lastError();
	}
}
