#pragma once
class database; // Forward declaration because C++ sucks. 

#include <string>
using std::string;

class Product
{
    friend class database;  // Lol
public:
    // Constructors!
    Product(database& db);
    Product(database& db, string name, string desc, bool rnt_status, bool type, float rating);
    // Properties
    // Getters
    int id() const;          // Getter for _id
    int c_id() const;        // Getter for c_id
    string name() const;     // Getter for name
    string desc() const;     // Getter for desc
    bool rnt_status() const; // Getter for rnt_status
    bool type() const;       // Getter for type
    float rating() const;    // Getter for rating
    
    // Setters
    void setId(int _id);              // Setter for _id
    void setcId(int c_id);            // Setter for c_id
    void setName(string name);        // Setter for name
    void setDesc(string desc);        // Setter for desc
    void setStatus(bool rnt_status);  // Setter for rnt_status
    void setType(bool type);          // Setter for type
    void setRating(float rating);     // Setter for rating
                                      
    // Utility
    void delete_(int id);  // Delete product by ID
    void write();  // Write or overwrite object to database
private:
    int _id;          // Database ID
    int _c_id;        // Category ID
    string _name;     // Product name
    string _desc;     // Product description
    bool _rnt_status; // Rental status
    bool _type;       // Product type (DVD or videogame)
    float _rating;    // Rating
    // Database object
    database& db;       // Database instance object reference
};
