# DVDRental

A DVD Rental system.
This is a Windows Form application.
You can build this by using Visual Studio (2019).

Specifically, you need the...

- MSVC v142 - VS 2019 C++ x64/x86 build tools (Latest)
- .NET Framework 4 - 4.6 development tools
- .NET SDK (out of support)

Then, you can just open up the solution and then build and run.


# Explanation of code

Besides the GUI, the code is simple.
`main.cpp` is a driver that initializes the database and adds some sample data to it.
It doesn't add data to all tables.

The tables are created in the file `include/database/driver.hpp`
The schemas are in the files contained in `include/database/schemas/`

I am using the infamous [fnc12/sqlite_orm](https://github.com/fnc12/sqlite_orm) library for this project.
You can find some iffy documentation over at [their wiki on GitHub](https://github.com/fnc12/sqlite_orm/wiki) or some better
documentation [in these slides](https://sqliteorm.com/files/SQLITE_ORM%20Tutorial%203.2.pdf).

I tried to make the code as simple as possible. Here is a generalized overview/representation of how
the code for the schemas are structured:

```C++
// ...imports

class Table {
    public:
    // Functions
       Table(); // Empty, default constructor
       Table(type column, type column2, ...); // For creating a row
       auto schema(); // For returning a schema
    // Columns
       type column;
       type column2;
       // ...columns
}

// ...implementation

```

We then import this into `include/database/driver.hpp`:

```C++

// ...imports
// Import all the tables
#include <database/schemas/table1.h>
#include <database/schemas/table2.h>
#include <database/schemas/table....h>
// ...

// ...database class

auto database::newDatabase(string database_name) {
    // ...
    // Create new instances of these tables
    Table table1;
    Table2 table2;
    // ...
    auto storage = make_storage(database_name + ".sqlite", table1.schema(), table2.schema(), ...);

    // Synchronize the schemas and create a new database (if non-existent)
    storage.sync_schema();
    // Return the storage for usage
    return storage;
    // ...
}
```

And in the `main.cpp` file we have a function to create this for us

```C++
auto initDB()
{
    // Create the database
    database db;
    const auto database = db.newDatabase("database");
    Trace::WriteLine("Database created."); // Or `cout`, depending on the branch
    return database; // Return for usage
}

// Use the database
void main(){
    auto database = initDB();
    // ...
    Table row1("Alice", "Inwonder"); // Let's say `column1` and `column2` are of type "string"
    insertedID = database.insert(row1); // Insert the row
    Trace::WriteLine("insertedId = " + insertedID.ToString()); // Or `cout`, depending on the branch
    Trace::WriteLine(row1._id); // Print the row's ID
}
```
