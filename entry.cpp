#include "pch.h"
#include <iostream>
#include <database/driver.hpp>
using std::cout;
using namespace Windows::Storage;


auto initDB()
{
    // Create the database
    database001 db;
    const auto database = db.newDatabase("database.sqlite"); //database.sqlite
    // cout << "Database created." << endl;
    return database;
}

void uwp_main()
{

    auto database = initDB();
    cout << "Inserting new user..." << endl;
    User user("John", "Doe", "???", "2 Starapple Street", false);
    auto insertedID = database.insert(user);
/*
    cout << "insertedId = " << insertedID << endl;
    user._id = insertedID;

    cout << "Inserting new user..." << endl;
    User secondUser("Alice", "Inwonder", "???", "5 Orange Street", false);
    insertedID = database.insert(secondUser);
    cout << "insertedId = " << insertedID << endl;
    secondUser._id = insertedID;

    cout << "Inserting new product..." << endl;
    Product product("Alice", "Inwonder", false, 2.4);
    insertedID = database.insert(product);
    cout << "insertedId = " << insertedID << endl;
    product._id = insertedID;
    */
}