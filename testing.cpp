#include <iostream>
#include "Date.h"
#include "Color.h"
#include "Cell.h"
#include "Spreadsheet.h"

void testCellValueInt(Cell c) {
    std::string input = "47";
    c.setValue(input);
    if(c.toInt() != 47)
        std::cout << "!!!!!! Test failed value is'nt 47 !!!!!!" << std::endl;
    else 
        std::cout << "Test passed value is 47" << std::endl;
    std::string input = "-7";
    c.setValue(input);
    if(c.toInt() != (-7))
        std::cout << "!!!!!! Test failed value is'nt -7 !!!!!!" << std::endl;
    else 
        std::cout << "Test passed value is -7" << std::endl;
}

void testCellValueDouble(Cell c) {
    std::string input = "55.5";
    c.setValue(input);
    if(c.toDouble() != 55.5)
        std::cout << "!!!!!! Test failed value is'nt 55.5 !!!!!!" << std::endl;
    else 
        std::cout << "Test passed value is 55.5" << std::endl;
    std::string input = "-55.5";
    c.setValue(input);
    if(c.toDouble() != (-55.5))
        std::cout << "!!!!!! Test failed value is'nt -55.5 !!!!!!" << std::endl;
    else 
        std::cout << "Test passed value is -55.5" << std::endl;
}

void testCellValueDate(Cell c) {
    std::string input = "25.1.2000";
    c.setValue(input);
    Date date_ = c.toDate();
    if (date_.get_year() != 2000 || date_.get_day() != 25 || date_.get_month() != 1)
        std::cout << "!!!!!! Test failed ValueDate() function !!!!!!"<< std::endl;
    else 
        std::cout << "Test passed ValueDate() function"<< std::endl;
}

void testCellGetValue(Cell cell_) {
    std::string input = "eeeee";
    cell_.setValue(input);
    std::string var = cell_.getValue();
    if (var != input) 
        std::cout << "Test failed GetValue() function" << std::endl;
    else
        std::cout << "Test passed GetValue() function" << std::endl;
}

void testCellValueReset(Cell cell_) {
    std::string var = cell_.getValue();
    if (var != "")
        std::cout << "Test failed ValueReset() function" << std::endl;
    else 
        std::cout << "Test passed ValueReset() function" << std::endl;
}
/*
void testSpreadsheetGetCellAt(Spreadsheet spread_, Cell cell_) {
    cell_.setValue("7");
    spread_.setCellAt(2,3, cell_);
    Cell get_cel = spread_.getCellAt(2, 3);
    
}
*/
void testSpreadsheetSetCellAt(Spreadsheet spread_, Cell cell_) {
    cell_.setValue("7");
    spread_.setCellAt(2,3, cell_);
    Cell get_cel = spread_.getCellAt(2, 3);
    if (get_cel.getValue() != "7")
        std::cout << "Test failed SetCellAt" << std::endl;
    else 
        std::cout << "Test passed SetCellAt" << std::endl;
}

void testSpreadSetCellAt(Spreadsheet spread_,Cell cell_) {
    
}

int main() {
    Cell cell_;
    Spreadsheet spread_(4, 5);
    testCellGetValue(cell_);
    testCellValueInt(cell_);
    testCellValueDouble(cell_);
    testCellValueDate(cell_);
    testCellValueReset(cell_);

    //testSpreadsheetGetCellAt(spread_,cell_);
    testSpreadSetCellAt(spread_,cell_);
    testSpreadsheetSetCellAt(spread_, cell_);
    
    return 0;
}