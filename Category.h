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
    Category(database& db, string name, string descr);
    // Properties
    // Getters
    int id() const;       // Getter for _id
    string name() const;  // Getter for name
    string descr() const;  // Getter for descr

    // Setters
    void setId(int _id);        // Setter for _id
    void setName(string name);  // Setter for name
    void setDescr(string descr);  // Setter for descr

    // Utility
    void delete_(int id);  // Delete category by ID
    void write();  // Write or overwrite object to database
private:
    int _id;      // Database ID
    string _name;  // Category name
    string _descr;  // Category descrription
    // Database object
    database& db;       // Database instance object reference
};
