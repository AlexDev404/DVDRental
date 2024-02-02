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

I tried to make the code as simple as possible. Here is a generalization of how
the code for the schemas are structured