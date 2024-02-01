#pragma once
#include <string>
#include <sqlite-orm/sqlite_orm.h>
using std::string, sqlite_orm::make_table, sqlite_orm::make_column, sqlite_orm::unique, sqlite_orm::primary_key;

class User
{
public:
    User();
    User(string firstName, string lastName, int birthDate, int typeId);
    auto schema();
    // Properties
    int _id;
    string firstName;
    string lastName;
    int birthDate;
    int typeId;
};

// Default constructor
User::User()
{
    // Nothing. Absolutely nothing.
}

// New user
User::User(string firstName, string lastName, int birthDate, int typeId)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->birthDate = birthDate;
    this->typeId = typeId;
}

// Export the schema
auto User::schema()
{
    return make_table<User>("users",
                            make_column("_id", &User::_id, unique(), primary_key().autoincrement()),
                            make_column("first_name", &User::firstName),
                            make_column("last_name", &User::lastName),
                            make_column("birth_date", &User::birthDate),
                            make_column("image_url", &User::typeId));
}