#include "pch.h"
#include <iostream>
#include <database/driver.hpp>
using namespace std;

auto initDB()
{
    // Create the database
    database db;
    const auto database = db.newDatabase("database");
    cout << "Database created." << endl;
    return database;
}

void main_()
{
    auto database = initDB();
    cout << "Inserting new user..." << endl;
    User user("John", "Doe", "???", "2 Starapple Street", false);
    auto insertedID = database.insert(user);
    cout << "insertedId = " << insertedID << endl;
    user._id = insertedID;

    cout << "Inserting new user..." << endl;
    User secondUser("Alice", "Inwonder", "???", "5 Orange Street", false);
    insertedID = database.insert(secondUser);
    cout << "insertedId = " << insertedID << endl;
    secondUser._id = insertedID;

    cout << "Inserting new product..." << endl;
    Product product("Alice", "Inwonder", false, 2.44);
    insertedID = database.insert(product);
    cout << "insertedId = " << insertedID << endl;
    product._id = insertedID;
    // return 0;
}