#include "pch.h"
#include <database/driver.hpp>
using namespace System::Diagnostics;

auto initDB()
{
    // Create the database
    database db;
    const auto database = db.newDatabase("database");
    Trace::WriteLine("Database created.");
    return database;
}

void main_()
{
    auto database = initDB();
    Trace::WriteLine("Inserting new user...");
    User user("John", "Doe", "???", "2 Starapple Street", false);
    auto insertedID = database.insert(user);
    Trace::WriteLine("insertedId = " + insertedID.ToString());
    user._id = insertedID;

    Trace::WriteLine("Inserting new user...");
    User secondUser("Alice", "Inwonder", "???", "5 Orange Street", false);
    insertedID = database.insert(secondUser);
    Trace::WriteLine("insertedId = " + insertedID.ToString());
    secondUser._id = insertedID;

    Trace::WriteLine("Inserting new product...");
    Product product("Alice", "Inwonder", false, 2.44);
    insertedID = database.insert(product);
    Trace::WriteLine("insertedId = " + insertedID.ToString());
    product._id = insertedID;
    // return 0;
}