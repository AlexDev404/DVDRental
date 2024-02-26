#pragma once
class database; // Forward declaration because C++ sucks. 

#include <string>
using std::string;

class Category
{
    friend class database;  // Lol
public:
    // Constructors!
    Category(database& db);
    Category(database& db, string name, string desc);
    // Properties
    // Getters
    int id() const;       // Getter for _id
    string name() const;  // Getter for name
    string desc() const;  // Getter for desc

    // Setters
    void setId(int _id);        // Setter for _id
    void setName(string name);  // Setter for name
    void setDesc(string desc);  // Setter for desc

    // Utility
    void delete_(int id);  // Delete category by ID
    void write();  // Write or overwrite object to database
private:
    int _id;      // Database ID
    string _name;  // Category name
    string _desc;  // Category description
    // Database object
    database& db;       // Database instance object reference
};
