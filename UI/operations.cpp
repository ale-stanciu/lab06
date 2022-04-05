#include "operations.h"
#include<iostream>
using namespace std;
#include "../Repo/Repo.h"
#include <vector>


/**
 * read "nr" squares
 * @param nr number of squares
 * @param array dynamically allocated array to store the squares
 */
void read_square(int &nr, Repo &repo)
{
    cout << "Enter how many squares you want to introduce in the array: ";
    cin >> nr;
    Square square;
    int nr_sq = 0;
    for (int i = 0; i < nr; i++) {
        cout << "Square: " << i + 1 << endl;
        cin >> square;
        cout << square;
        repo.add_square(square);
    }
}

/**
 * shows "nr_sq" squares
 * @param nr_sq number of squares
 * @param array dynamically allocated array to store the squares
 */
void show_squares(Repo repo) {
    for (auto& square: repo.get_all()) {
        cout << "Squares:" << square << endl;
    }
}
Square biggestSquare(double &maxDiagonal, Repo& repo)
{
    maxDiagonal = 0.0;
    Square sqr;
    for (auto& square: repo.get_all())
        if(square.getDiagonal() > maxDiagonal) {
            maxDiagonal = square.getDiagonal();
            sqr = square;
        }
    return sqr;
}

vector <Square> positiveSquares(Repo repo)
{
    int i;
    vector <Square> v = repo.get_all();
    vector <Square> v1 = {};
    for (i=0; i<v.size(); i++)
        if(v[i].isPositive())
            v1.push_back(v[i]);
    return v1;
}



vector <Square> equalSequence(Repo repo) {
    int lc = 0, pc=0, pmax=0, lmax = 0,i;
    vector <Square> v = repo.get_all();
    vector <Square> v1 = {};
    for(i = 0; i < v.size()-1; i++) {
        if(v[i] == v[i + 1])
            lc++;
        else
            if (lc > lmax) {
                lmax =lc;
                pc = i - lc;
                pmax = i + lc - 1;
                lc=0;
            }
    }
    if(lc > lmax)
    {
        lmax =lc;
        pc = i - lc;
        pmax = i + lc - 1;
    }
    for(i=pc; i<pmax; i++)
        v1.push_back(v[i]);

    return v1;
}

