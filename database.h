#pragma once
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqlerror.h>
#include <QDebug>
#include <vector>
#include <optional>
#include <QString>
#include <qmessagebox.h>
#include "./User.h"
#include "./Product.h"
#include "./Category.h"
#include "./Rental.h"

class database
{
public:
    database(); // Does nothing
    // ~database(); // Goodbye, database. We never missed you!
    database(string database_name); // Connect to the database
    // (if-no-exists): Create and return back a new database instance
    database newDatabase(string database_name);
    QSqlDatabase getInstance() const; // Get the database instance please

    // Utilities and the such
    // User
    std::optional<User> queryUser(int id);  // Get a user by ID
    std::vector<User> getAllUsers();        // Get all users

    // Product
    std::optional<Product> queryProduct(int id);  // Get a product by ID
    std::vector<Product> getAllProducts();        // Get all products

    // Category
    std::optional<Category> queryCategory(int id);
    std::vector<Category> getAllCategories();

    // Rental
    std::optional<Rental> queryRental(int id);
    std::vector<Rental> getAllRentals();
private:
    QSqlDatabase please;
    QString dbHost = "127.0.0.1";
    QString dbUsername = "root";
    QString dbPassword = "root";
    QString dbName = "DVDRental";
};
