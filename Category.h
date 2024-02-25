#pragma once
#include <string>
#include <QtSql/qtsqlglobal.h>
using std::string;

class Category
{
public:
    // Constructors!
    Category();
    Category(string name, string desc);
    // Properties
    // Getters
    int id() const;       // Getter for _id
    string name() const;  // Getter for name
    string desc() const;  // Getter for desc

    // Setters
    void setId(int _id);        // Setter for _id
    void setName(string name);  // Setter for name
    void setDesc(string desc);  // Setter for desc
private:
    int _id;      // Database ID
    string _name;  // Category name
    string _desc;  // Category description
};
