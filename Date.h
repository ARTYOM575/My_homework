class Date {
    int year;
    int month;
    int day;
public:
    Date();
    void set_year(int year_){this->year = year_;}
    void set_month(int month_){this->month = month_;}
    void set_day(int day_){this->day = day_;}
    int get_year(){return this->year;}
    int get_month(){return this->month;}
    int get_day(){return this->day;}
};
Date::Date() {
    this->year = 0;
    this->month = 0;
    this->day = 0;
}
