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

int main()
{
    auto database = initDB();
    cout << "Inserting new user..." << endl;
    User user("John", "Doe", 664416000, 3);
    auto insertedID = database.insert(user);
    cout << "insertedId = " << insertedID << endl;
    user._id = insertedID;

    cout << "Inserting new user..." << endl;
    User secondUser("Alice", "Inwonder", 831168000, 2);
    insertedID = database.insert(secondUser);
    cout << "insertedId = " << insertedID << endl;
    secondUser._id = insertedID;
    return 0;
}