#include <iostream>
#include "templates.h"
// to run:
// g++ -g -Wall -o compiled/templates.out templates.h templates.cpp; ./compiled/templates.out


int main (){

    int a = 5;
    int b = 3;
    float f_a = 5.0;
    float f_b = 6.0;

    // Template Function:
    // most simple example of template. 
    // max was defined in the header
    // using an Int. the T of the template becomes an Integer
    std::cout << "Max between a and b: " << max(a, b) << std::endl;
    //using a Float, exact the same max() is used. the T of the template becomes a Foat
    std::cout << "Max between f_a and f_b: " << max(f_a, f_b) << std::endl;

    // Template Class:
    // Before c++17 you need to still explicity tell the T type to be used in the class:
    // e.g.: <int> <std::string> <CustomClass> 
    Accum<int> integers(6); 
    integers += 9;
    integers += 5;
    std::cout << "The total accumulated in Accum integers is: " << integers.GetTotal() << std::endl;

    // String example
    Accum<std::string> text("Once Upon");
    text += " a";
    text += " time";
    std::cout << "THe text built is: " << text.GetTotal() << std::endl;



    return 0;

}