#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//This file is better visualised using the debbugger. 


int main(){

// copying
// You can copy collections with the following operations:
// = : equals creates an exact copy.
// copy(), copy_if(), copy_n, copy_backward()

vector<char> origin {'X', 'A', 'B', 'C', 'Y'};
vector<char> dest(5); // declares the vector and allocate the memory space for it

// a clone.
auto scratch_vector = origin;
// >> scratch_vector = {'X', 'A', 'B', 'C', 'Y'}

//_____________________________________________________________________________________________________________
// simple copy, takes iterators as arguments
copy(begin(origin), end(origin), begin(dest));
// >> dest = {'X', 'A', 'B', 'C', 'Y'}

//Doesn't Allow appending one collection to another, since it doesn't change vector's size
//though allow partial copies using iterators to define range.
copy(begin(origin), end(origin), end(scratch_vector) -1); 
// >> scractch_vector = {'X', 'A', 'B', 'C', 'X'}

//_____________________________________________________________________________________________________________
// copy_if, same as above, but takes a lambda to control what to copy.

vector<char> dest_2 (5);
copy_if(begin(origin), end(origin), begin(dest_2), [](char c){return c % 2 != 0;});
// >> dest_= {'A', 'C', 'Y', '\000', '\000'}


//_____________________________________________________________________________________________________________
// copy_n
// copies an arbitrary number of elements. More readable than just copy
vector<char> dest_3 (3);
copy_n(begin(origin), 3, begin(dest_3));
// >> {'X', 'A', 'B'}

//_____________________________________________________________________________________________________________
// copy_backwards
// copies element by element, starting from the back. It's good to handle some conflicts that may be caused
// when the copy is done from the first to the last item.  It DOESN'T change the order of the elemnts
// In the example bellow, we copied the values of Origin back into origin, but changing only the last 4 items.
// If we make a simple copy, that would cause errors, since the item [1], [2], [3] and [4] would be altered before
// they had the chance to be copied.

vector<char> dest_4(5);
copy_backward(begin(origin), end(origin) -1, end(origin));
// >> origin = {'X', 'X', 'A', 'B', 'C'}



};