// Include the necessary headers
#include "customer.h"
#include <mysqlx/xdevapi.h>
#include <iostream>

#include <mysqlx/xdevapi.h>
#include <iostream>
#include <string>

void CreateCustomerRow(mysqlx::Session* session, 
                       int customer_id,
                       std::string name, 
                       std::string phone_number,  
                       std::string email,
                       std::string address) {
    try {
        mysqlx::Schema schema = session->getSchema("carInventory");
        mysqlx::Table customerTable = schema.getTable("Customer");

        // Create a TableInsert object for the table
        mysqlx::TableInsert insert = customerTable.insert("Name", "Phone_Number", "Email", "Address");

        // Insert values directly without creating a Row object
        insert.values(name, phone_number, email, address);

        // Perform the insert operation
        mysqlx::Result result = insert.execute();

        // Check if the insert was successful
        if (result.getAffectedItemsCount() == 0) {
            std::cerr << "Error: No rows were inserted." << std::endl;
        } else {
            std::cout << "Successfully inserted a new customer." << std::endl;
        }
    } catch (const std::exception& e) {
        // Handle any exceptions thrown by the insert operation
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void MakeNewCustomer(mysqlx::Session* session,
                   int empId,
                   int custId,
                   const std::string& vin, 
                   double price, 
                   const std::string& saleDateString) {
    try {
        mysqlx::Schema schema = session->getSchema("carInventory");
        mysqlx::Table salesTable = schema.getTable("sale");

        // Create a TableInsert object for the table
        mysqlx::TableInsert insert = salesTable.insert();

        // Create a Row object and set its values using the 'set' method for each column
        mysqlx::Row row;
        row.set(1, empId);
        row.set(2, custId);
        row.set(3, vin);
        row.set(4, price);
        row.set(5, mysqlx::expr("STR_TO_DATE('" + saleDateString + "', '%Y-%m-%d')"));

        // Add the Row object to the insert operation
        insert.values(row);

        // Perform the insert operation
        mysqlx::Result result = insert.execute();
        std::cout << saleDateString << std::endl;

        // Check if the insert was successful
        if (result.getAffectedItemsCount() == 0) {
            std::cerr << "Error: No rows were inserted." << std::endl;
        } else {
            std::cout << "Successfully inserted a new row." << std::endl;
        }
    } catch (const std::exception& e) {
        // Handle any exceptions thrown by the insert operation
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
