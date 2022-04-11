#include "tests.h"
#include "assert.h"
#include "../Square Class/Square.h"
#include "../UI/operations.h"


void test_all()
{
    test_constructor_side();
    test_setter();
    test_getter_perimeter();
    test_getter_area();
    test_operations();
    test_constructor2();
    test_positiveSquares();
    test_biggestSquare();
    test_equalSequence();
}


void test_constructor_side()
{
    Square square;
    assert(square.get_xA() == 0.0);
    assert(square.get_yA() == 0.0);
    assert(square.get_xC() == 0.0);
    assert(square.get_yC() == 0.0);
}

void test_constructor2()
{
    Square square1(1,0,0,5,5);
    assert(square1.getSide() == 5.0);
}

void test_setter()
{
    Square square;
    square.set_xA(7.0);
    square.set_yA(7.0);
    square.set_xC(0.0);
    square.set_yC(0.0);
    assert(square.get_xA() == 7.0);
    assert(square.get_yA() == 7.0);
    assert(square.get_xC() == 0.0);
    assert(square.get_yC() == 0.0);
}

void test_getter_perimeter()
{
    Square square;
    square.set_xA(5.0);
    square.set_yA(5.0);
    square.set_xC(0.0);
    square.set_yC(0.0);
    assert(square.getPerimeter() == 20.0);
}

void test_getter_area()
{
    Square square;
    square.set_xA(5.0);
    square.set_yA(5.0);
    square.set_xC(0.0);
    square.set_yC(0.0);
    assert(square.getArea() == 25.0);
}

void test_operations()
{
    Square square1(1,3,5,7,8);
    Square square2(2,4,4,0,4);
    Square square3(3,9,6,4,7);
    Square square4(4,9,6,4,7);

    square2 = square1;

    assert(square3 == square4);
    assert(!(square1 == square4));
}


void test_biggestSquare()
{
    Square square1(1,33,0,0,33);
    Square square2(2,-3,-5,0,4);
    Square square3(3,9,0,4,0);

    Repo repo;
    repo.add_square(square1);
    repo.add_square(square2);
    repo.add_square(square3);
    double maxDiagonal = 0;
    Square a = biggestSquare(maxDiagonal, repo);
    assert(a.get_xA() == 33);
    assert(a.get_xC() == 0);
    assert(a == square1);

}


void test_positiveSquares()
{
    Square square1(1,3,5,7,8);
    Square square2(2,-3,-5,0,4);
    Square square3(3,9,0,4,0);

    Repo repo;

    repo.add_square(square1);
    repo.add_square(square2);
    repo.add_square(square3);

    vector <Square> v = positiveSquares(repo);
    assert(v[0] == square1);
}


void test_equalSequence()
{
    Square square1(1,5,5,7,8);
    Square square2(2,5,5,7,8);
    Square square3(3,5,5,7,8);
    Square square4(3,9,0,4,0);
    Square square5(1,5,5,6,8);
    Square square6(2,5,3,7,8);

    Repo repo;

    repo.add_square(square1);
    repo.add_square(square2);
    repo.add_square(square3);
    repo.add_square(square4);
    repo.add_square(square5);
    repo.add_square(square6);

    vector <Square> v = equalSequence(repo);

    assert(v.size()==3);
    assert(v[0] == square1);
    assert(v[1]==square2);
}
