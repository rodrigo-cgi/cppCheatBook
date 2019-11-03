#include <iostream>
#include <vector>

using namespace std;

int main(){

    // Data containers:

    // __________________________________________________________________________________________________
    // Fundamental data types 

    bool var_b = true;
    short int var_si = 32767; // from -32767 to 32767
    unsigned short int var_usi = 65535; // UNSIGNED types are only positive values, from 0 to 65535
    int var_i = 2; // from -2,147,483,648 to 2,147,483,647
    long long int var_lli = (2^63)-1; // from -(2^63) to (2^63)-1
    float var_f = 2.0; // .2E-38 to 3.4E+38
    double var_d = 2.0; // 3E-308 to 1.7E+308
    long double var_ld = 0.0; // 10 byte  - 4E-4932 to 1.1E+4932
    char var_c = 'c'; // It's an int that represents a char. -128 to 127
    wchar_t var_wc = 'ஹ'; // data type wide enough to store any kind of char in any existing language. 

    // __________________________________________________________________________________________________
    // Derived data containers
    cout << endl;

    //function
    bool & ref_b = var_b; // reference
    cout << "Referece: " << ref_b << endl;
    bool * ptr_b = &var_b; // pointer, which is initialized with the address for var_B
    cout << "Pointer: " << ptr_b << endl;
    // you can't interact with the var to which the pointers points, by just assigning a value to the pointer.
    // you need to expand the pointer to the original var first by usin *<pointer>
    cout << "Pointer expanded with *: " << *ptr_b << endl;
    *ptr_b = false;
    cout << "var_b after *ptr_b = false: " <<  var_b << endl;

    //___________________________________________________________________________________________________
    // arrays and list

    int var_array[] = {1, 2, 3, 4}; // array is a lightweight list, which size is unmutable and must be initialized in definition.
    std::vector<int> vec_i = {1, 2, 3, 4}; // a int vector, or, a list of integers elements. It acceps only one data type but can be expanded
    std::string var_str = "abcs" ; // strings are a specilized list of chars. 

    //___________________________________________________________________________________________________
    //User defined data types:

    // The only difference between a struct and class in C++ is the default accessibility
    // of member variables and methods. In a struct they are public; 
    // in a class they are privatestruct is similar
    // By convention, struct is usually used to store data, e.g. a website config
    struct Struct_B {};
    class Class_A{};


    //___________________________________________________________________________________________________
    // Some more useful abstract data types
    cout << endl;

    // Enum is a list of integers which uses strings to represents them in the code for convenience
    // It only accepts in types: int, long int, char, unsigned char etc;
    // Try to use as small datatype as possible. Suggestionc char, which is as small as 255

    enum enum_int : unsigned char {A=2, B=3, C};

    // enums can be defined inside class and use their namespaces:
    class FrutiBasket {
        public:
            FrutiBasket(){}
            enum TypesOfFruits: unsigned char {
                Apple, Banana, Orange
            };
            void Set_Fruit(TypesOfFruits f){ current_fruit_ = f;};
        private:
            TypesOfFruits current_fruit_ = Apple;
    };

    FrutiBasket basket;
    cout << "What's the number of the FruitBasket's apple?:  " << basket.Apple << endl;
    cout << "What's the number of the FruitBasket's banana?:  " << basket.Banana << endl;
    cout << "What's the number of the FruitBasket's orange?:  " << basket.Orange << endl;


    return 0;
}