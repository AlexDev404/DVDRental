#pragma once
#include <string>
#include <sqlite-orm/sqlite_orm.h>
using std::string, sqlite_orm::make_table, sqlite_orm::make_column, sqlite_orm::unique, sqlite_orm::primary_key;

class User
{
public:
    User();
    User(string firstName, string lastName, string sk, string addr, bool role);
    auto schema();
    // Properties
    int _id; // Database ID 
    string firstName; // First name 
    string lastName; // Last name
    string sk; // Security key
    string addr; // Customer/user address 
    bool role; // User role
};

// Default constructor
User::User()
{
    // Nothing. Absolutely nothing.
}

// New user
User::User(string firstName, string lastName, string sk, string addr, bool role)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->sk = sk;
    this->addr = addr;
    this->role = role;
}

// Export the schema
auto User::schema()
{
    return make_table<User>("users",
                            make_column("_id", &User::_id, unique(), primary_key().autoincrement()),
                            make_column("first_name", &User::firstName),
                            make_column("last_name", &User::lastName),
                            make_column("sk", &User::sk),
                            make_column("addr", &User::addr),
                            make_column("role", &User::role));
}