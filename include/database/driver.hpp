#pragma once
#include <sqlite-orm/sqlite_orm.h>
#include <database/schemas/user.h>
#include <database/schemas/product.h>
#include <database/schemas/rental.h>
#include <database/schemas/category.h>
using namespace sqlite_orm;

// https://github.com/fnc12/sqlite_orm

class database
{
public:
    // Return back the database
    auto newDatabase(string database_name);
};

auto database::newDatabase(string database_name)
{
    // Create a database
    try
    {
        // Schema import
        // Import the user schema
        User user;
        // Import the product schema
        Product product;
        // Import the rental schema
        Rental rental;
        // Import the category schema
        Category category;

        // Create the storage
        auto storage = make_storage(database_name + ".sqlite", user.schema(), product.schema(),
                                    rental.schema(), category.schema());
        // Sync the schemas and create the database if it doesn't exist already
        storage.sync_schema();
        return storage;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        throw e.what();
        // return nullptr;
    }
}