#include "database.h"

// Default constructor-Moved from header to here because compilation bugs out when in there
database::database() {  // Default constructor--does nothing
}


database::database(string database_name) {
	// Let's start by loading this extinct driver
    please = QSqlDatabase::addDatabase("QMYSQL");
    // Set the connection credentials
    please.setHostName("127.0.0.1");
    please.setUserName("root");
    please.setPassword("root");
    please.setDatabaseName("DVDRental");

    //exception handling
    try
    {
        if (please.open())
        {
            qDebug("Successfully connected to database!");

        }
        else
            // Lets the program know that it didnt connect to the server
        {
            QString error = please.lastError().text();
            throw error.toStdString().c_str();
        }


    }
    catch (const char* message)  //catches the exception as a char pointer
    {
        try {
            // Create a new database
            // TODO: SQL code to create a new database
        }
        catch (const char* message) {
            qDebug("Connection to database failed! " + *message);
        }
    }

}

database database::newDatabase(string database_name) {
	database newDb(database_name);
	return newDb;
}