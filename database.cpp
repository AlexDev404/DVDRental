#include "database.h"

// Default constructor-Moved from header to here because compilation bugs out when in there
database::database() {  // Default constructor--does nothing
}
// Remove our pain -- on second thought lets remove this because this is already painful
/*database::~database() {
    please.close(); // We're asking nicely.
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);  //remove database
}*/

database::database(string database_name) {
    // Let's start by loading this extinct driver
    please = QSqlDatabase::addDatabase("QMYSQL");
    this->dbName = QString::fromStdString(database_name);
    // Set the connection credentials
    please.setHostName(dbHost);
    please.setUserName(dbUsername);
    please.setPassword(dbPassword);
    please.setDatabaseName(dbName);

    //exception handling
    try
    {
        if (please.open())
        {
            qDebug("Successfully connected to database!");
            QMessageBox::information(nullptr, "Database Information", "You are hopefully connected.");

        }
        else
            // Lets the program know that it didnt connect to the server
        {
            
            try {
                // Create a new database
                please = QSqlDatabase::addDatabase("QMYSQL");
                please.setUserName(dbUsername);
                please.setPassword(dbPassword);
                please.setHostName(dbHost);

                if (!please.open()) {
                    QString error = please.lastError().text();
                    throw error.toStdString().c_str();
                }

                QSqlQuery query(please);
                // Prepare the query
                query.prepare("CREATE DATABASE :dbName"); // Bugs out weirdly
                query.bindValue(":dbName", dbName);

                if (!query.exec()) {
                    QString error = query.lastError().text();
                    QMessageBox::critical(nullptr, "Database Error", error);
                    throw error.toStdString().c_str();
                }
                else {
                    QMessageBox::information(nullptr, "Database Message", "Database has been created.");
                }
            }
            catch (const char* message) {
                qDebug("Creation of new database failed! " + *message);
                QString error = please.lastError().text();
                qDebug(error.toStdString().c_str());
                QMessageBox::critical(nullptr, "Database Error", error);
                throw error.toStdString().c_str();
            }
    }

    }
    catch (const char* message)  //catches the exception as a char pointer
    {
            qDebug("Connection to database failed! " + *message);
            QMessageBox::critical(nullptr, "Database Error", message);
    }

}

database database::newDatabase(string database_name) {
    database newDb(database_name);
    return newDb;
}

QSqlDatabase database::getInstance() const {
    // Return the QSqlDatabase object
    return please; // Just hope this returns please
}

// User
// Get one user by ID
std::optional<User> database::queryUser(int id) {
    QSqlDatabase database = this->getInstance();
    QSqlQuery query(database);

    // Prepare the query
    query.prepare("SELECT * FROM users WHERE id = :id");
    query.bindValue(":id", id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error querying user from database: " << query.lastError();
        // Handle error here, for example by throwing an exception or returning a default User
    }

    // Check if a row was returned
    if (query.next()) {
        // Create a User from the row
        User user(*this);
        user._id = query.value("id").toInt();
        user._firstName = query.value("firstName").toString().toStdString();
        user._lastName = query.value("lastName").toString().toStdString();
        user._sk = query.value("sk").toString().toStdString();
        user._addr = query.value("addr").toString().toStdString();
        user._role = query.value("role").toBool();
        return user;
    }
    else {
        return std::nullopt;
    }
}

// Get all users
std::vector<User> database::getAllUsers() {
    QSqlDatabase database = this->getInstance();
    QSqlQuery query(database);

    // Prepare the query
    query.prepare("SELECT * FROM users");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error querying users from database: " << query.lastError();
        // Handle error here, for example by throwing an exception or returning an empty vector
        return std::vector<User>();
    }

    // Create a vector to hold the users
    std::vector<User> users;

    // Loop through the rows
    while (query.next()) {
        // Create a User from the row
        User user(*this);
        user._id = query.value("id").toInt();
        user._firstName = query.value("firstName").toString().toStdString();
        user._lastName = query.value("lastName").toString().toStdString();
        user._sk = query.value("sk").toString().toStdString();
        user._addr = query.value("addr").toString().toStdString();
        user._role = query.value("role").toBool();

        // Add the user to the vector
        users.push_back(user);
    }

    // Return the vector of users
    return users;
}

// Product
// Get one product by ID
std::optional<Product> database::queryProduct(int id) {
    QSqlDatabase database = this->getInstance();
    QSqlQuery query(database);

    // Prepare the query
    query.prepare("SELECT * FROM products WHERE id = :id");
    query.bindValue(":id", id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error querying product from database: " << query.lastError();
        // Return an empty optional in case of error
        return std::nullopt;
    }

    // Check if a row was returned
    if (query.next()) {
        // Create a Product from the row
        Product product(*this);
        product._id = query.value("id").toInt();
        product._c_id = query.value("c_id").toInt();
        product._name = query.value("name").toString().toStdString();
        product._descr = query.value("descr").toString().toStdString();
        product._rnt_status = query.value("rnt_status").toBool();
        product._type = query.value("type").toBool();
        product._rating = query.value("rating").toFloat();
        return product;
    }
    else {
        // No row was returned, return an empty optional
        return std::nullopt;
    }
}

// Get all products
std::vector<Product> database::getAllProducts() {
    QSqlDatabase database = this->getInstance();
    QSqlQuery query(database);

    // Prepare the query
    query.prepare("SELECT * FROM products");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error querying products from database: " << query.lastError();
        // Return an empty vector in case of error
        return std::vector<Product>();
    }

    // Create a vector to hold the products
    std::vector<Product> products;

    // Loop through the rows
    while (query.next()) {
        // Create a Product from the row
        Product product(*this);
        product._id = query.value("id").toInt();
        product._c_id = query.value("c_id").toInt();
        product._name = query.value("name").toString().toStdString();
        product._descr = query.value("descr").toString().toStdString();
        product._rnt_status = query.value("rnt_status").toBool();
        product._type = query.value("type").toBool();
        product._rating = query.value("rating").toFloat();

        // Add the product to the vector
        products.push_back(product);
    }

    // Return the vector of products
    return products;
}

// Category
std::optional<Category> database::queryCategory(int id) {
    QSqlDatabase database = this->getInstance();
    QSqlQuery query(database);

    // Prepare the query
    query.prepare("SELECT * FROM categories WHERE id = :id");
    query.bindValue(":id", id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error querying category from database: " << query.lastError();
        // Return an empty optional in case of error
        return std::nullopt;
    }

    // Check if a row was returned
    if (query.next()) {
        // Create a Category from the row
        Category category(*this);
        category._id = query.value("id").toInt();
        category._name = query.value("name").toString().toStdString();
        category._descr = query.value("descr").toString().toStdString();
        return category;
    }
    else {
        // No row was returned, return an empty optional
        return std::nullopt;
    }
}

std::vector<Category> database::getAllCategories() {
    QSqlDatabase database = this->getInstance();
    QSqlQuery query(database);

    // Prepare the query
    query.prepare("SELECT * FROM categories");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error querying categories from database: " << query.lastError();
        // Return an empty vector in case of error
        return std::vector<Category>();
    }

    // Create a vector to hold the categories
    std::vector<Category> categories;

    // Loop through the rows
    while (query.next()) {
        // Create a Category from the row
        Category category(*this);
        category._id = query.value("id").toInt();
        category._name = query.value("name").toString().toStdString();
        category._descr = query.value("descr").toString().toStdString();

        // Add the category to the vector
        categories.push_back(category);
    }

    // Return the vector of categories
    return categories;
}

// Rental
std::optional<Rental> database::queryRental(int id) {
    QSqlDatabase database = this->getInstance();
    QSqlQuery query(database);

    // Prepare the query
    query.prepare("SELECT * FROM rentals WHERE id = :id");
    query.bindValue(":id", id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error querying rental from database: " << query.lastError();
        // Return an empty optional in case of error
        return std::nullopt;
    }

    // Check if a row was returned
    if (query.next()) {
        // Create a Rental from the row
        Rental rental(*this);
        Product* product = new Product(this->queryProduct(query.value("product_id").toInt()).value_or(Product(*this)));
        User* user = new User(this->queryUser(query.value("user_id").toInt()).value_or(User(*this)));

        rental._id = query.value("id").toInt();
        rental._product = product;
        rental._returned_at = query.value("returned_at").toLongLong();
        rental._rented_at = query.value("rented_at").toLongLong();
        rental._is_due_at = query.value("is_due_at").toLongLong();
        rental._charge = query.value("charge").toFloat();
        rental._user = user;
        return rental;
    }
    else {
        // No row was returned, return an empty optional
        return std::nullopt;
    }
}

std::vector<Rental> database::getAllRentals() {
    QSqlDatabase database = this->getInstance();
    QSqlQuery query(database);

    // Prepare the query
    query.prepare("SELECT * FROM rentals");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error querying rentals from database: " << query.lastError();
        // Return an empty vector in case of error
        return std::vector<Rental>();
    }

    // Create a vector to hold the rentals
    std::vector<Rental> rentals;

    // Loop through the rows
    while (query.next()) {
        // Create a Rental from the row
        Rental rental(*this);
        Product* product = new Product(this->queryProduct(query.value("product_id").toInt()).value_or(Product(*this)));
        User* user = new User(this->queryUser(query.value("user_id").toInt()).value_or(User(*this)));

        rental._id = query.value("id").toInt();
        rental._product = product;
        rental._returned_at = query.value("returned_at").toLongLong();
        rental._rented_at = query.value("rented_at").toLongLong();
        rental._is_due_at = query.value("is_due_at").toLongLong();
        rental._charge = query.value("charge").toFloat();
        rental._user = user;

        // Add the rental to the vector
        rentals.push_back(rental);
    }

    // Return the vector of rentals
    return rentals;
}
