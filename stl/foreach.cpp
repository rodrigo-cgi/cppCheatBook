// to compile use:
// g++ -g -Wall -o /home/rodrigoj/_Projects/cppCheatBook/stl/compiled/foreach.out foreach.cpp; ./compiled/foreach.out
#include <iostream>
#include <vector>
#include <algorithm> // contains the for_each algorithm
using namespace std;

int main(){
    
    vector <int> v {2, 4, 5, 7, 7, 9, -12, 54, 321, 3};
    vector <int> v2 {2, 4, 5, 7, 7, 2, 3 };

    // for each is a loop in disguise
    // it's readable and performs a function to every object of a list:
    // It allows iteratings partial collections

    auto iterator_at_7 = find(begin(v), end(v), 7);
    auto iterator_at_321 = find(begin(v), end(v), 321);

    for_each(iterator_at_7, iterator_at_321, [](int& elem){cout << "Elemem: " << elem << endl;});

    return 0;
}
