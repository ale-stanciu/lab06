//
// Created by User on 3/31/2022.
//

#include "Repo.h"
#include "../Square Class/Square.h"

Repo::Repo() {
}

void Repo::add_square(Square sqr)
{
    this->squares.push_back(sqr);
}


Square& Repo::get_square_id(int id) {
    for(Square& sqr: squares)
        if(sqr.get_square_id() == id)
            return sqr;
    throw runtime_error("No entity with specified id found");

}

std::vector<Square> Repo::get_all() {
    return squares;
}
