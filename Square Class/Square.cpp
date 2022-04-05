#include "Square.h"
#include<math.h>
#include<iostream>
using namespace std;

/**
 * constructor (create a square)
 */
Square::Square()
{
    this->id = 0;
    this->xA = 0.0;
    this->yA = 0.0;
    this->xC = 0.0;
    this->yC = 0.0;
}

/**
 * constructor with parameter
 * @param id the id of the square
 * @param xA the abscissa coordinate for the first point
 * @param yA the ordinate coordinate for the second point
 * @param xC the abscissa coordinate for the second point
 * @param yC the ordinate coordinate for the second point
 */
Square::Square(int id, double xA, double yA, double xC, double yC)
{
    this->id = id;
    this->xA = xA;
    this->yA = yA;
    this->xC = xC;
    this->yC = yC;
}

/**
 * create a square using info from another square
 * @param s a square s
 */
Square::Square(const Square &s)
{
    this->id = s.id;
    this->xA = s.xA;
    this->yA = s.yA;
    this->xC = s.xC;
    this->yC = s.yC;
}

/**
 * change xA
 * @param xA the abscissa coordinate for the first point
 */
void Square::set_xA(double xA)
{
    this->xA = xA;
}

/**
 * change xC
 * @param xC the abscissa coordinate for the second point
 */
void Square::set_xC(double xC)
{
    this->xC = xC;
}

/**
 * change yA
 * @param yA the ordinate coordinate for the first point
 */
void Square::set_yA(double yA)
{
    this->yA = yA;
}

/**
 * change yC
 * @param yC the ordinate coordinate for the second point
 */
void Square::set_yC(double yC)
{
    this->yC = yC;
}


void Square::set_id(int id)
{
    this->id = id;
}

/**
 * access the abscissa coordinate for the first point of a square
 * @return the abscissa coordinate for the first point
 */
double Square::get_xA()
{
    return this->xA;
}

/**
 * access the abscissa coordinate for the second point of a square
 * @return the abscissa coordinate for the second point
 */
double Square::get_xC()
{
    return this->xC;
}

/**
 * access the ordinate coordinate for the first point
 * @return the ordinate coordinate for the first point
 */
double Square::get_yA()
{
    return this->yA;
}
/**
 * access the ordinate coordinate for the second point
 * @return the ordinate coordinate for the second point
 */
double Square::get_yC()
{
    return this->yC;
}

int Square::get_square_id()
{
    return this->id;
}
/**
 * calculate the diagonal of a square and access it
 * @return the size of the diagonal
 */
double Square::getDiagonal()
{
    return sqrt((xC - xA) * (xC - xA) + (yC - yA) * (yC - yA));
}


/**
 * calculate the side of a square and access it
 * @return the size of the side
 */
double Square::getSide()
{
    return this->getDiagonal() / sqrt(2);
}

/**
 * calculate the perimeter of a square and access it
 * @return the perimeter
 */
double Square::getPerimeter()
{
    return 4 * this->getSide();
}

/**
 * calculate the area of a square and access it
 * @return the area
 */
double Square::getArea()
{
    return this->getSide() * this->getSide();
}

/**
 * assignment operator
 * @param s an instance of Square
 * @return the new state of the current instance (this)
 */
Square &Square::operator=(const Square &s){
    this->set_xA(s.xA);
    this->set_xC(s.xC);
    this->set_yA(s.yA);
    this->set_yC(s.yC);
    return *this;
}

/**
 * verify which square has the bigger/smaller area
 * @param s a square
 * @return true/false
 */
bool Square::operator<=(Square &s)
{
    return (this->getArea() <= s.getArea());
}

/**
 * verify which square has the bigger/smaller area
 * @param s a square
 * @return true/false
 */
bool Square::operator>=(Square &s)
{
    return (this->getArea() >= s.getArea());
}

/**
 * verify if 2 squares have the same area
 * @param s a square
 * @return true/false
 */
bool Square::operator==(Square &s)
{
    return abs(this->getArea()-s.getArea())<1e-9;
}


/**
 * destroy a square
 */
Square::~Square() = default; //asociaza valorile default pt. tipurile de date

/**
 * load a square from an input stream
 * @param input an input stream
 * @param s a new sqyare
 * @return a new square
 */
istream &operator>>(istream &input, Square &s)
{
    cout<<"Enter the id: ";
    input>>s.id;
    cout<<"Enter the coordinates of point A: "<<endl;
    cout<<"xA = ";
    input >> s.xA;
    cout<<"yA = ";
    input>>s.yA;
    cout<<"Enter the coordinates of point C: "<<endl;
    cout<<"xC = ";
    input>>s.xC;
    cout<<"yC = ";
    input>>s.yC;
    return input;
}

/**
 * save a square into an output stream
 * @param output an output stream
 * @param s a square
 * @return the output stream loaded by info about the square
 */
ostream &operator<<(ostream &output, Square &s)
{
    cout<<"id = ";
    output<<s.id;
    cout<<endl;
    cout<<"xA = ";
    output << s.xA << "; ";
    cout<<"yA = ";
    output<<s.yA << "; ";
    cout<<"xC = ";
    output << s.xC << "; ";
    cout<<"yC = ";
    output << s.yC << " " << endl;
    cout<<"Side: "<<s.getSide()<<endl;
    cout<<"Perimeter: "<<s.getPerimeter()<<endl;
    cout<<"Area: "<<s.getArea() << endl;
    return output;
}

bool Square::isPositive() const
{
    return(this->xA > 0 && this->yA > 0 && this-> xC > 0 && this->yC > 0);
}