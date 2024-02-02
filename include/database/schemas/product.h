#pragma once
#include <string>
#include <sqlite-orm/sqlite_orm.h>
using std::string, sqlite_orm::make_table, sqlite_orm::make_column, sqlite_orm::unique, sqlite_orm::primary_key;

class Product
{
public:
    Product();
    Product(string name, string desc, bool rnt_status, bool type, float rating);
    auto schema();
    // Properties
    int _id;         // Database ID
    string name;     // Product name
    string desc;     // Product description
    bool rnt_status; // Rental status
    bool type;       // Product type (DVD or videogame)
    float rating;    // Rating
};

// Default constructor
Product::Product()
{
    // Nothing. Absolutely nothing.
}

// New Product
Product::Product(string name, string desc, bool rnt_status, bool type, float rating)
{
    this->name = name;
    this->desc = desc;
    this->rnt_status = rnt_status;
    this->type = type;
    this->rating = rating;
}

// Export the schema
auto Product::schema()
{
    return make_table<Product>("products",
                               make_column("_id", &Product::_id, unique(), primary_key().autoincrement()),
                               make_column("name", &Product::name),
                               make_column("description", &Product::desc),
                               make_column("rental_status", &Product::rnt_status),
                               make_column("type", &Product::type),
                               make_column("rating", &Product::rating)

    );
}