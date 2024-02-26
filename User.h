#pragma once
class database; // Forward declaration because C++ sucks. 

#include <string>
using std::string;

class User
{
    friend class database;  // Lol
public:
    // Constructors!
    User(database &db);
    User(database &db, string userName, string firstName, string lastName, string sk, string addr, bool role);
    // Properties
    // Getters
    int id() const;          // Getter for _id
    string userName() const; // Getter for userName
    string firstName() const; // Getter for firstName
    string lastName() const;  // Getter for lastName
    string sk() const;        // Getter for sk
    string addr() const;      // Getter for addr
    bool role() const;        // Getter for role
    
    // Setters
    void setId(int id);         // Setter for _id
    void setUserName(string userName); // Setter for userName
    void setFirstName(string firstName); // Setter for firstName
    void setLastName(string lastName);   // Setter for lastName
    void setSk(string sk);       // Setter for sk
    void setAddr(string addr);   // Setter for addr
    void setRole(bool role);     // Setter for role
    
    // Utilities
    void delete_(int id);  // Delete a user by ID
    void write();          // Write object to database
private:
    int _id;           // Database ID
    string _userName; // User name
    string _firstName; // First name
    string _lastName;  // Last name
    string _sk;        // Security key (password, essentially)
    string _addr;      // Customer/user address
    bool _role;        // User role (admin or customer)
    // Database object
    database &db;       // Database instance object reference
};
