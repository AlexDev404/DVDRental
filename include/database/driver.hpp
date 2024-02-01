#pragma once
#include <sqlite-orm/sqlite_orm.h>
#include <database/schemas/user.h>
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
        // Import the user schema
        User user;
        auto storage = make_storage(database_name + ".sqlite", user.schema());
        // Sync the schemas
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