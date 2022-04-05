#include "console.h"
#include "../UI/operations.h"
#include "../Square Class/Square.h"
#include "../Repo/Repo.h"
#include<iostream>
using namespace std;

void menu()
{
    cout << "1. Read square" << endl;
    cout << "2. Show squares" << endl;
    cout << "3. Biggest square" << endl;
    cout << "4. Identify the squares that are completely in the first quadrant" << endl;
    cout << "5. Identify the longest sequence of equal squares" << endl;
    cout << "x. Exit" << endl;
}

void console()
{
    int ok=0, nr;
    char option;
    Repo repo;
    double maxDiagonal = 0.0;
    while(ok != 1)
    {
        menu();
        cout << "Give option:";
        cin >> option;
        switch(option) {
            case '1': {
                read_square(nr, repo);
                break;
            }
            case '2': {
                show_squares(repo);
                break;
            }
            case '3': {

                Square a = biggestSquare(maxDiagonal, repo);
                cout << a;
                break;
            }
            case '4':{
                vector <Square> v1 = positiveSquares(repo);
                for(auto& s:v1)
                    cout<<s<<endl;
                break;
            }
            case '5': {
                vector <Square> v1 = equalSequence(repo);
                for(auto& s: v1)
                    cout<<s<<endl;
                break;
            }
            case 'x': {
                ok = 1;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}