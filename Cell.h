#include <iostream>

class Cell {
    Color col;
    std::string cell;
public:
    Cell ();
    void setValue(std::string const &);
    const std::string getValue();
    int toInt();
    double toDouble();
    Date toDate();
    void reset();
    void setColor(Color col_){this->col = col_;}
    void setColor(int);
    Color getColor() {return col;}
};

Cell::Cell() {
    col = white;
    cell = "";
}

void Cell::setValue(std::string const &var) {
    this->cell = var;
}

const std::string Cell::getValue() {
    return this->cell;
}

int Cell::toInt() {
    // 4 byte  int kareli er grel sizeof funkciaov uxak  ...... 
    int i = 0;
    int size_int = 10;
    int size_number = this->cell.length();
    if (this->cell[0] == '-') {
        ++i;
        ++size_int;
    }
    if (size_int < this->cell.length()) {
        std::cout << "!!! Value is'nt integer !!!" << std::endl;
        return -1; 
    }
    for (; this->cell[i] != '\0'; ++i) {
        if (this->cell[i] < 48 || this->cell[i] > 57) {
            std::cout << "!!! Value is'nt integer !!!" << std::endl;
            return -1;
        }
    }
    long number = stol(this->cell);
    if (size_int == 11) {
        if (number < -2147483648) {
            std::cout << "!!! Value is'nt integer , that's small int !!!" << std::endl;
            return -1; 
        }       
    }
    else {
        if (number > 2147483647) {
            std::cout << "!!! Value is'nt integer , that's big int !!!" << std::endl;
            return -1; 
        }
    }
    return stoi(this->cell);
}

double Cell::toDouble() {
    //paymanakanoren vercnenq vor double-i simvolner@ chen karox mec linel 15 ic 
    int count_pointer = 0;
    int pointer_index;
    int size_number = this->cell.length();
    if (size_number > 15) {
        std::cout << "!!! Value is'nt double !!!" << std::endl;
        return -1;
    }
    for (int i = 0; this->cell[i] != '\0'; ++i) {
        if (this->cell[i] == 46) {
            pointer_index = i;
            ++count_pointer;
            continue;
        }
        if (count_pointer > 1 || this->cell[i] < 48 || this->cell[i] > 57) {
            std::cout << "!!! Value is'nt double !!!" << std::endl;
            return -1;
        }
    }
    if (pointer_index == 0) {
        std::cout << "!!! Value is'nt double !!!" << std::endl;
        return -1;
    }
    return stod(this->cell);
}

Date Cell::toDate() {
    Date d;
    int date[3];
    int index_date;
    std::string var;
    int pointer_count = 0;
    for (int i = 0; this->cell[i] != '\0'; ++i) {
        if (this->cell[i] == 46) {
            ++pointer_count;
            continue;
        }
        if (pointer_count > 2 || this->cell[i] < 48 || this->cell[i] > 57) {
            std::cout << "!!! value in'nt Date " << std::endl;
            return d;
        }
    }
    for (int i = 0; this->cell[i] != '\0'; ++i) {
        var = "";
        while (true) {
            if (this->cell[i] != '.') {
                var += cell[i];
            }
            else 
                break;
        }
        date[index_date] = stoi(var);
        ++index_date;
    }
    if (date[0] <= 0 || date[1] <= 0 || date[2] <= 0 || date[0] >31 || date[1] > 12) {
        std::cout << "!!! value in'nt Date " << std::endl;
        return d;
    }
    if (date[1] == 2) {
        if (date[2] % 4 == 0)
        {
            if (date[0] > 28) {
                std::cout << "!!! value in'nt Date , day is big" << std::endl;
                return d;
            } else if (date[0] > 27) {
                std::cout << "!!! value in'nt Date , day is big" << std::endl;
                return d;
            }
        }
    }
    else if (date[1] == 1 || date[1] == 3 || date[1] == 5 || date[1] == 7 || date[1] == 8 || date[1] == 10 || date[1] == 12) {
        if (date[0] > 31) {
            std::cout << "!!! value in'nt Date , day is big" << std::endl;
            return d;
        }
    }
    else if (date[0] > 30) {
        std::cout << "!!! value in'nt Date , day is big" << std::endl;
        return d;
    }
    d.set_day(date[0]);
    d.set_month(date[1]);
    d.set_year(date[2]);
    return d;
}

void Cell::reset() {
    this->col = white;
    this->cell = "";
}


void Cell::setColor(int const col_) {
    if (col_ == 0) 
        this->col = Red;
    else if (col_ == 1) 
        this->col = Gern;
    else if (col_ == 2) 
        this->col = Blue;
    else if (col_ == 3) 
        this->col = Yelow;
    else if (col_ == 4) 
        this->col = white;
    else 
        std::cout << "there is no such color" <<std::endl;
}
