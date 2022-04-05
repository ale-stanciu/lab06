//
// Created by User on 3/31/2022.
//

#ifndef LAB04_REPO_H
#define LAB04_REPO_H
#include<iostream>
#include <vector>
#include "../Square Class/Square.h"

using namespace std;

class Repo {

private:
    vector<Square> squares;

public:
    Repo();
    void add_square(Square sqr);
    Square& get_square_id(int id);
    vector<Square> get_all();
};


#endif //LAB04_REPO_H
