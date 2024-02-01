#pragma once
#include <string>
#include <sqlite-orm/sqlite_orm.h>
using std::string, sqlite_orm::make_table, sqlite_orm::make_column, sqlite_orm::unique, sqlite_orm::primary_key;

class Category
{
public:
    Category();
    Category(string name, string desc, int products);
    auto schema();
    // Properties
    int _id;       // Database ID
    string name;   // Category name
    string desc;   // Category description
    int products; // Products in category
};

// Default constructor
Category::Category()
{
    // Nothing. Absolutely nothing.
}

// New Category
Category::Category(string name, string desc, int products)
{
    this->name = name;
    this->desc = desc;
    this->products = products;
}

// Export the schema
auto Category::schema()
{
    return make_table<Category>("categorys",
                                make_column("_id", &Category::_id, unique(), primary_key().autoincrement()),
                                make_column("name", &Category::name),
                                make_column("description", &Category::desc),
                                make_column("products", &Category::products)

    );
}
