#include <iostream>
#include "templates.h"
#include "classes.h"
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


    // Using Classes
    // In this sample, we need to decide what does it mean to accumulate a class.
    // I'll use the sum of the Light intensities.

    Light dome_01 ("dome", "_01", 20);
    Light sun_01 ("sun", "_01", 30);
    SpotLight spot_01 ("spot", "_01", 30, "lightgroup");

    // creting an accum object that will have the sum of all lights
    Accum<Light> sky(0);

    sky += dome_01;
    sky += sun_01;
    sky += spot_01;

    std::cout << "The new light, sky, has intensity of " << sky.GetTotal() <<std::endl;

    return 0;

}