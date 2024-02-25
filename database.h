#pragma once
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqlerror.h>
#include <QDebug>
#include <vector>
#include "./User.h"
#include "./Product.h"
#include "./Category.h"
#include "./Rental.h"

class database
{
public:
    database();
    database(string database_name);
    // (if-no-exists): Create and return back a new database instance
    database newDatabase(string database_name);

    // Utilities and the such
    // User
/*    void newUser(User user);          // Add a new user
    void deleteUser(int id);          // Delete a user by ID
    User queryUser(int id);           // Get a user by ID
    std::vector<User> getAllUsers();  // Get all users

    // Product
    void newProduct(Product product);
    void deleteProduct(int id);
    Product queryProduct(int id);
    std::vector<Product> getAllProducts();

    // Category
    void newCategory(Category category);
    void deleteCategory(int id);
    Category queryCategory(int id);
    std::vector<Product> getAllCategories();

    // Rental
    void newRental(Rental rental);
    void deleteRental(int id);
    Rental queryRental(int id);
    std::vector<Rental> getAllRentals();*/
private:
    QSqlDatabase please;
};
