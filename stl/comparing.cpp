// to compile use:
// g++ -g -Wall -o /home/rodrigoj/_Projects/cppCheatBook/stl/compiled/comparing.out comparing.cpp; ./compiled/comparing.out
#include <iostream>
#include <vector>
#include <algorithm> // contains the comparing algorithms
using namespace std;

int main(){
    
    vector <int> v {2, 4, 5, 7, 7, 9, -12, 54, 321, 3};
    vector <int> v2 {2, 4, 5, 7, 7, 2, 3 };

    // comparing size is easy:
    bool same = v.size() == v2.size();

    // equal, takes 2 pairs of iterators and 

    same = equal(begin(v), end(v), begin(v2), end(v2));  // False
    cout << "Are v and v2 equals? " << same << endl;
    same = equal(begin(v), begin(v) +5, begin(v2), begin(v2) + 5);  // True
    cout << "Are V[0:5] and v2 equals? " << same << endl;

    // mismatch 
    // functions that generates an object of Pair type, containing the first mismatch between 2 sequences
    // THe pair contains 2 iterators. Note that in the cout line bellow, it is necessary to de-reference the 
    // iterator to be able to read the original value of the element inside the vector.

    auto firstchange = mismatch(begin(v), end(v), begin(v2));
    cout << endl;
    cout << "First mismatch between V1 and V2: ( " << *(firstchange.first) << ", " << *(firstchange.second) << " )" << endl;

    auto distance = firstchange.first - begin(v);
    cout << "v and v2 are equals for " << distance << " first members" << endl;

    // Acumulating elelemtns



}
