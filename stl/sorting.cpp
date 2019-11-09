// to compile use:
// g++ -Wall -Wextra -pedantic -O2 -o compiled/sorting.out sorting.cpp; ./compiled/sorting.out

#include <iostream>
#include <vector>
#include <algorithm>
#include "sorting_classes.h"
using namespace std;
using namespace sorting_classes;

int main(){

    //sorting
    vector <int> v {2, 4, 5, 7, 7, 1, -12, 54, 321, 3};
    auto v2 = v; //copying v for keeping it on its original form

    sort(begin(v2), end(v2)); // simple sort
    sort(begin(v2), end(v2), [](int elem1, int elem2) {return abs(elem1) > abs(elem2);}); // sorting with a lambda, which is a small function that executes 2 elements comparison

    // stable sort
    // Stable sort guarantee that repeated elements of a list will always be sorted in the same way.
    
    vector <Char> characters;
    characters.push_back( Char("Bilbo", "Baggins", 7));
    characters.push_back (Char("Optimus", "Prime", 12));
    characters.push_back( Char("James", "Bond", 7));

    stable_sort(begin(characters), end(characters));
    cout << characters[0].GetName() << endl;
    cout << characters[1].GetName() << endl;
    cout << characters[2].Getname() << endl; 

    return 0;

}