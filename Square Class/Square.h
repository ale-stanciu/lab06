
#ifndef LAB04_SQUARE_H
#define LAB04_SQUARE_H


#include <iostream>
using namespace std;


class Square{
private:
    int id;
    double xA, xC, yA, yC;

public:
    Square();
    double get_xA();
    double get_xC();
    double get_yA();
    double get_yC();
    int get_square_id();
    double getDiagonal();
    double getSide();
    double getPerimeter();
    double getArea();
    void set_xA(double xA);
    void set_xC(double xC);
    void set_yA(double yA);
    void set_yC(double yC);
    void set_id(int id);
    Square& operator=(const Square &s);
    Square(int id, double xA, double yA, double xC, double yC);
    friend istream& operator>>(istream& input, Square& s);
    friend ostream& operator<<(ostream& input, Square& s);
    Square(const Square &s);
    bool operator<=(Square &s);
    bool operator>=(Square &s);
    bool operator==(Square &s);
    bool isPositive() const;
    ~Square();
};


#endif //LAB04_SQUARE_H
