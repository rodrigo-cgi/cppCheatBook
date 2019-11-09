// to compile use:
// g++ -g -Wall -o /home/rodrigoj/_Projects/cppCheatBook/stl/compiled/sorting.out sorting_classes.h sorting_classes.cpp sorting.cpp; ./compiled/sorting.out
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
    // In the example, Tony Stark and James bond have the same index
    // The operator < was overriden to compare the Character.index_ element of the class while sorting
    // With normal sort, the order of elements with same index number is not guaranteed to be consistent
    // with stable_sort, the order is guaranteed. stable_sort is slower
    
    Character t_char ("A", "B", 32);

    vector <Character> characters;
    characters.push_back( Character("Bilbo", "Baggins", 13));
    characters.push_back( Character("Optimus", "Prime", 12));
    characters.push_back( Character("James", "Bond", 7));
    characters.push_back( Character("Tony", "Spark", 7));
    
    for (int i = 0; i < 1000; i++) {
        // TODO: Find a better way of demonstrate unstable sort
        auto vec_copy = characters;
        sort(begin(vec_copy), end(vec_copy));
        cout << "Unstable Sort. first sort element 01: " << vec_copy[0].GetName() << endl;
    }

    cout << "Stable sort: " << endl;
    stable_sort(begin(characters), end(characters));
    cout << characters[0].GetName() << endl;
    cout << characters[1].GetName() << endl;
    cout << characters[2].GetName() << endl;
    cout << characters[3].GetName() << endl;

    return 0;

}
