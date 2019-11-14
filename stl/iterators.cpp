// to compile
//g++ -g -Wall -o compiled/iterators.out iterators.cpp; ./compiled/iterators.out

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // iota
#include <iterator> // back inserter, front_inserter etc
#include <deque>
#include <array>

using namespace std;

int main() {

    // Iterators are objects that store position and a reference to the value in a given collection
    // to access the value of the iterator at a certain position, use *
    // *iterator
    
    //_____________________________________________________________________________________________________________
    //Prelocating
    // Using vectors and the algorithms bellow have some issues since the size is pre allocated

    vector<int> example01(5); // creates vector with default values of int; >> {0, 0, 0, 0, 0}
    // fill
    fill(begin(example01), end(example01), 1); // fills all the spaces with 1 >> {1, 1, 1, 1, 1}
    fill_n(begin(example01), 3, 2); // fills the n(3) elements with 2 >> {2, 2, 2, 1, 1}
    iota(begin(example01), end(example01), 1); // Fills the range [first, last) with sequentially increasing values, 
                                 //starting with value and repetitively evaluating ++value.

    //_____________________________________________________________________________________________________________
    // using iterator algorithms
    // avoiding prelocating vectors
    // inserter iterators works very well with fill_n, generate_n, transform, copy, copy_if, unique_copy, reverse_copy

    vector<int> example02; // no preallocated size

    // back_inserter
    fill_n(back_inserter(example02), 6, 2); // expands the size of vector to 6 and fills it with 2s
                                            // >> {2, 2, 2, 2, 2, 2,}

    // Bellow: generate_n creates new elements after the elements that are in there. 
    // the lambda has an Alias Capture [n = 0] - uses an argument by reference without the need to create
    // a loose variable that won't be used after lambda is done. 
    // mutable says that the variables of the lambda can be changed by the lambda. 
    //  this way, n will have its value maintained to each execution fo that lambda performed by the 
    // generate_n
    generate_n(back_inserter(example02), 5, [n = 0]()mutable{return n += 5;});  // >> {2, 2, 2, 2, 2, 2, 5, 10, 15, 20, 25}
    for_each(begin(example02), end(example02), [](auto& i){cout << i << endl;}); 

    // vector doesn't support front_inserter, but dequie does.
    cout << endl;
    deque<int> example03;
    fill_n(front_inserter(example03), 6, 2);
    generate_n(front_inserter(example03), 5, [n = 0]()mutable{return n += 5;}); // >> {25, 20, 15, 10, 5, 2, 2, 2, 2, 2, 2}
    for_each(begin(example03), end(example03), [](auto& i){cout << i << endl;}); 

    // the back_ and front_inserter works with the same algorithms, but they allow some more complex tasks, like copying each
    // element from one vector and appending to another, exceuting a lambda in the process.
    transform(begin(example01), end(example01), back_inserter(example02), [](int elem){return elem *5;});

    vector<int> example04;
    unique_copy(begin(example02), end(example02), back_inserter(example04)); // copies no duplicated items 
                                                                             // {2, 5, 10, 15, 20, 25}

    cout << "" << endl;

    //_____________________________________________________________________________________________________________
    //rend and rbegin , reverted algorithims
    //rend is the same of begin -1, which doesn't exist but means the memory slot before the beginning
    //rbegin means end -1. 
    //rbegin + 1 is the same of end -2. You see, the progression is inverted. xx 

    example02.clear();
    vector<int> example05 = {1, 2, 3, 4};
    copy(rbegin(example05), rend(example05), back_inserter(example02)); // >> {4, 3, 2, 1}

    // can use rbegin and rend to find the last occurance of an elemnt
    example04[9] = 5; // {2, 5, 10, 15, 20, 25, 5, 10, 15, 5, 25}

    auto last_five = find(rbegin(example04), rend(example04), 5);
    auto distance = last_five - rbegin(example04); // The distance is 1. since there is only one
                                                   // element after the last 5.
    last_five++; // iterator is at 25, which means, the element 10 of the list
    

    //_____________________________________________________________________________________________________________
    // Arithmetic
    // + , -, < , >, 

    // legal: end(example01) - begin(example01)
    //not legal: end(example01) - rbegin(example01)

    //_____________________________________________________________________________________________________________
    // const iterators
    // cbegin and cend - > good express of intent and const correctness

    array<int const, 5> constant_array01 = {3, 4, 3, 2, 1};
    auto const_interator = cbegin(constant_array01);
    const_interator++;

    return 0;

}
