// to compile use:
// g++ -g -Wall -o /home/rodrigoj/_Projects/cppCheatBook/stl/compiled/accumulating.out accumulating.cpp; ./compiled/accumulating.out
#include <iostream>
#include <vector>
#include <numeric> // contains the accumulation algorithms
using namespace std;

int main(){
    
    vector <int> v {2, 4, 5, 7, 7, 9, -12, 54, 321, 3};
    vector <int> v2 {2, 4, 5, 7, 7, 2, 3 };
    
    // accumulate 
    int accumulation;
    accumulation = accumulate(begin(v), end(v), 0);  // the last 0 is the initial value.

    cout << "Sum of the values in v: " << accumulation << endl;

    // accumulate also accepts a lambda do validate. 
    // even numbers. Note that the initial value is now 1.
    // The lambda takes 2 arguments, First is the current total, the second the current item of the list.
    // The total and the returning type must be the same
    // Accumulate also works with other da types
    // such as string, to generate  "Hello World" out of {"Hello", " ", "World"}

    accumulation = accumulate(begin(v), end(v), 1, 
                             [](int total, int i){ if (i % 2 ==0); return total * i; return total; });


    cout << "Result of Multiplying of all even umbers in v: " << accumulation << endl;

    return 0;
}
