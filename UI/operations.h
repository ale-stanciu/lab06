
#ifndef LAB04_OPERATIONS_H
#define LAB04_OPERATIONS_H

#include "../Square Class/Square.h"
#include "../Repo/Repo.h"
#include<iostream>

void read_square(int &nr, Repo &repo);
void show_squares(Repo repo);
Square biggestSquare(double &maxDiagonal, Repo& repo);
vector <Square> positiveSquares(Repo repo);
vector <Square> equalSequence(Repo repo);

#endif //LAB04_OPERATIONS_H
