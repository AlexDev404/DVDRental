#pragma once
#include <string>
#include <sqlite-orm/sqlite_orm.h>
using std::string, sqlite_orm::make_table, sqlite_orm::make_column, sqlite_orm::unique, sqlite_orm::primary_key;

class Rental
{
public:
    Rental();
    Rental(int product, int returned_at, int rented_at, int is_due_at, float charge, int user);
    auto schema();
    // Properties
    int _id;         // Database ID
    int product;    // Rental product
    int returned_at; // Return date
    int rented_at;   // Rental date
    int is_due_at;   // Due date
    float charge;    // Rental cost
    int user;       // Customer that rented the product
};

// Default constructor
Rental::Rental()
{
    // Nothing. Absolutely nothing.
}

// New Rental
Rental::Rental(int product, int returned_at, int rented_at, int is_due_at, float charge, int user)
{
    this->product = product;
    this->returned_at = returned_at;
    this->rented_at = rented_at;
    this->is_due_at = is_due_at;
    this->charge = charge;
    this->user = user;
}

// Export the schema
auto Rental::schema()
{
    return make_table<Rental>("rentals",
                              make_column("_id", &Rental::_id, unique(), primary_key().autoincrement()),
                              make_column("product", &Rental::product),
                              make_column("returned_at", &Rental::returned_at),
                              make_column("rented_at", &Rental::rented_at),
                              make_column("is_due_at", &Rental::is_due_at),
                              make_column("charge", &Rental::charge),
                              make_column("user", &Rental::user)

    );
}
