class Spreadsheet {
    Cell** m_cells;
    int row;
    int column;
    
    bool valueCheck(const int &, const int &, int, int);
    bool valueCheck(const int &, const int &, bool , bool, std::string);

public:    
 
    //Spreadsheet(const int&,const int&);
    //Spreadsheet(const int,const int);
    Spreadsheet(int, int);


    void setCellAt(const int&, const int&,Cell );
    void setCellAt(const int&, const int&, const std::string &);
    Cell getCellAt(const int rows, const int columns) {return m_cells[rows][columns];}
    void addRow(int);
    void removeRow(int);
    void addColumn(int);
    void removeColumn(int);
    void swapRows(int, int);
    void swapColumns(int, int);
};

bool Spreadsheet::valueCheck(const int &a, const int &b, int max_row = 20, int max_col = 20) {
    if (a > max_row || b > max_col || a <= 0 || b <= 0) {
        std::cout << "Invalid value";
        return false;
    }
    return true;
}
/*
Spreadsheet::Spreadsheet(const int &rows, const int &columns) {
    if (!valueCheck(rows,columns))
        return;
    m_cells = new Cell*[rows];
    for (int i = 0; i < columns; ++i) {
        m_cells[i] = new Cell[columns];
    }
    this->row = rows;
    this->column = columns;
}

Spreadsheet::Spreadsheet(const int rows, const int columns) {
    if (!valueCheck(rows,columns))
        return;
    m_cells = new Cell*[rows];
    for (int i = 0; i < columns; ++i) {
        m_cells[i] = new Cell[columns];
    }
    this->row = rows;
    this->column = columns;
}
*/
Spreadsheet::Spreadsheet(int rows, int columns) {
    if (!valueCheck(rows,columns))
        return;
    m_cells = new Cell*[rows];
    for (int i = 0; i < columns; ++i) {
        m_cells[i] = new Cell[columns];
    }
    this->row = rows;
    this->column = columns;
}

bool Spreadsheet::valueCheck(const int & r, const int & c, bool r_b, bool c_b,std::string action) {
    if (action == "add") {
        if (r_b) {
            if (this->row >= 20 || r > 20 || r < 0) {
                std::cout << "Invalid input" <<std::endl;
                return false;
            }      
        }
        else if (this->column >= 20 || c > 20 || c < 0) {
            std::cout << "Invalid input" <<std::endl;
            return false;
        }
            
    } else if (action == "remove") {
        if (r_b) {
            if (r > this->row || r < 0) {
                std::cout << "Invalid input" <<std::endl;
                return false;
            }
        }
        else if (c > this->column || c < 0) {
            std::cout << "Invalid input" <<std::endl;
            return false;
        }

    } else if (r_b) {
        if (r == c) {
        std::cout << "imported the same value" <<std::endl;
        return false;
        }
        return valueCheck(r, c, this->row, this->row);
    } else {
        if (r == c) {
        std::cout << "imported the same value" <<std::endl;
        return false;
        } 
        return valueCheck(r, c, this->column, this->column);
    }
    return true;
}

void Spreadsheet::setCellAt (const int &rows, const int &columns, Cell cl) { 
    if (!valueCheck(rows, columns, this->row, this->column))
        return;
    m_cells[rows][columns].setValue(cl.getValue());
    m_cells[rows][columns].setColor(cl.getColor());
}

void Spreadsheet::setCellAt (const int &rows,const int &columns, const std::string &str) {
    if (!valueCheck(rows, columns, this->row, this->column))
        return;
    m_cells[rows][columns].setValue (str);
}

void Spreadsheet::addRow (const int  rows) {
    if(!valueCheck(rows,rows,true,false,"add"))
        return;
    ++(this->row);
    Cell ** temp_switch;
    Cell ** temp_m_cells = new Cell* [this->row];
    for (int i = 0; i < row; ++i) {
        temp_m_cells[i] = new Cell[this->column];
    }
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < column; ++j) {
            temp_m_cells[i][j].setColor(this->m_cells[i][j].getColor());
            temp_m_cells[i][j].setValue(this->m_cells[i][j].getValue());   
        }
    }
    for (int i = rows + 1; i < this->row; ++i) {
        for (int j = 0; j < column; ++j) {
            temp_m_cells[i][j].setColor(this->m_cells[i-1][j].getColor());
            temp_m_cells[i][j].setValue(this->m_cells[i-1][j].getValue()); 
        }
    }
    temp_switch = m_cells;
    m_cells = temp_m_cells;
    for (int i = 0;i < row - 1; ++i)
        delete [] temp_switch[i];
    delete [] temp_switch;
}

void Spreadsheet::removeRow (int rows) {
    if(!valueCheck(rows,rows,true,false,"remove"))
        return;
    --(this->row);
    if (this->row == 0) {
        for (int i = 0;i < this->row; ++i)
            delete [] m_cells[i];
        delete [] m_cells;
        std::cout << "array deleted" <<std::endl;
        return;
    } 
    Cell ** temp_switch;
    Cell ** temp_m_cells = new Cell* [this->row];
    for (int i = 0; i < this->row; ++i) {
        temp_m_cells[i] = new Cell[this->column];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < column; ++j) {
            temp_m_cells[i][j].setColor(this->m_cells[i][j].getColor());
            temp_m_cells[i][j].setValue(this->m_cells[i][j].getValue());   
        }
    }
    for (int i = rows + 1; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            temp_m_cells[i - 1][j].setColor(this->m_cells[i][j].getColor());
            temp_m_cells[i - 1][j].setValue(this->m_cells[i][j].getValue());   
        }
    }
    temp_switch = m_cells;
    m_cells = temp_m_cells;
    for (int i = 0;i < this->row + 1; ++i)
        delete [] temp_switch[i];
    delete [] temp_switch;
}

void Spreadsheet::addColumn (int columns) { 
    if(!valueCheck(columns,columns,false,true,"add"))
        return;
    ++(this->column);
    Cell ** temp_switch;
    Cell ** temp_m_cells = new Cell* [this->row];
    for (int i = 0; i < this->row; ++i) {
        temp_m_cells[i] = new Cell[this->column];
    }
    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < row; ++i) {
            temp_m_cells[i][j].setColor(this->m_cells[i][j].getColor());
            temp_m_cells[i][j].setValue(this->m_cells[i][j].getValue()); 
        }
    }
    for (int j = columns + 1; j < column; ++j) {
        for (int i = 0; i < row; ++i) { 
            temp_m_cells[i][j].setColor(this->m_cells[i][j - 1].getColor());
            temp_m_cells[i][j].setValue(this->m_cells[i][j - 1].getValue());  
        }
    }
    temp_switch = m_cells;
    m_cells = temp_m_cells;
    for (int i = 0;i < this->row; ++i)
        delete [] temp_switch[i];
    delete [] temp_switch;
}

void Spreadsheet::removeColumn (int columns) { 
    if(!valueCheck(columns,columns,false,true,"remove"))
        return;
    --(this->column);
    if (this->column == 0) {
        for (int i = 0;i < this->row; ++i)
            delete [] m_cells[i];
        delete [] m_cells;
        std::cout << "array deleted" <<std::endl;
        return;
    }
        
    Cell ** temp_switch;
    Cell ** temp_m_cells = new Cell* [this->row];
    for (int i = 0; i < this->row; ++i) {
        temp_m_cells[i] = new Cell[this->column];
    }
    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < row; ++i) {
            temp_m_cells[i][j].setColor(this->m_cells[i][j].getColor());
            temp_m_cells[i][j].setValue(this->m_cells[i][j].getValue()); 
        }
    }
    for (int j = columns + 1; j < column; ++j) {
        for (int i = 0; i < row; ++i) { 
            temp_m_cells[i][j].setColor(this->m_cells[i][j - 1].getColor());
            temp_m_cells[i][j].setValue(this->m_cells[i][j - 1].getValue());  
        }
    }
    temp_switch = m_cells;
    m_cells = temp_m_cells;
    for (int i = 0;i < this->row; ++i)
        delete [] temp_switch[i];
    delete [] temp_switch;
}

void Spreadsheet::swapRows(int rows_1, int rows_2) {
    if(!valueCheck(rows_1,rows_2,true,false,"swap"))
        return;
    int min = rows_1;
    if (min > rows_2) 
        min = rows_2;
    int max = min ^ rows_1 ^ rows_2;
    Cell *temp = new Cell[this->column];
    for (int j = 0; j < this->column; ++j) {
        temp[j].setColor(this->m_cells[min][j].getColor());
        temp[j].setValue(this->m_cells[min][j].getValue());
        this->m_cells[min][j].setColor(this->m_cells[max][j].getColor());
        this->m_cells[min][j].setValue(this->m_cells[max][j].getValue());
        this->m_cells[max][j].setColor(temp[j].getColor());
        this->m_cells[max][j].setValue(temp[j].getValue());
    }
    delete [] temp;
}   

void Spreadsheet::swapColumns(int columns_1, int columns_2) {
    if(!valueCheck(columns_1,columns_2,false,true,"swap"))
        return;
    int min = columns_1;
    if (min > columns_2) 
        min = columns_2;
    int max = min ^ columns_1 ^ columns_2;
    Cell *temp = new Cell[this->column];
    for (int i = 0; i < this->column; ++i) {
        temp[i].setColor(this->m_cells[i][min].getColor());
        temp[i].setValue(this->m_cells[i][min].getValue());
        this->m_cells[i][min].setColor(this->m_cells[i][min].getColor());
        this->m_cells[i][min].setValue(this->m_cells[i][min].getValue());
        this->m_cells[i][max].setColor(temp[i].getColor());
        this->m_cells[i][max].setValue(temp[i].getValue());
    }
    delete [] temp;
}


