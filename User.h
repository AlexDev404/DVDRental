#pragma once
#include <string>
#include <QtSql/qtsqlglobal.h>
using std::string;

class User
{
public:
    // Constructors!
    User();
    User(string firstName, string lastName, string sk, string addr, bool role);
    // Properties
    // Getters
    int id() const;          // Getter for _id
    string firstName() const; // Getter for firstName
    string lastName() const;  // Getter for lastName
    string sk() const;        // Getter for sk
    string addr() const;      // Getter for addr
    bool role() const;        // Getter for role
    
    // Setters
    void setId(int id);         // Setter for _id
    void setFirstName(string firstName); // Setter for firstName
    void setLastName(string lastName);   // Setter for lastName
    void setSk(string sk);       // Setter for sk
    void setAddr(string addr);   // Setter for addr
    void setRole(bool role);     // Setter for role
    
    // Utilities
    void delete_(int id);               // Delete a user by ID
private:
    int _id;          // Database ID
    string _firstName; // First name
    string _lastName;  // Last name
    string _sk;        // Security key (password, essentially)
    string _addr;      // Customer/user address
    bool _role;        // User role (admin or customer)
};
