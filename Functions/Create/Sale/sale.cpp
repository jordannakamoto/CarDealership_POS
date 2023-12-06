// Include the necessary headers
#include "sale.h"
#include <mysqlx/xdevapi.h>
#include <iostream>

// Change the function name to CreateSaleRow and add saleId parameter
void CreateSaleRow(mysqlx::Session* session, 
                   int saleId, 
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
        row.set(0, saleId);
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
