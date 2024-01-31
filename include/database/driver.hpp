#pragma once
#include <sqlite-orm/sqlite_orm.h>
#include <database/schemas/user.h>
#include <database/schemas/product.h>

// https://github.com/fnc12/sqlite_orm

class database {
    public:
       int newDatabase(string database_name);
}

int database::newDatabase(string database_name){
    // Create a database

}