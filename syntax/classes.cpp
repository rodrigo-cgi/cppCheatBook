#include "classes.h"
#include <iostream>

//implementing the constructor of the Light,
//special syntax to attribute args directly to private vars.
Light::Light(std::string prefix, std::string sufix, int intensity):
            light_prefix_(prefix), 
            light_sufix_(sufix), 
            light_intensity_(intensity) 

{
std::cout << "initialized Light" << light_prefix_ << std::endl ;
}

// implementation of destructor
Light::~Light(){
}

// implements the override of the operator > in 3 scenarios
// the tricky part is to get the use of consts correct.
// The operators return a bool.

// in the first case, this is a member operator overload. Takes a single arg. 
// it's a const (unmutable) reference (not a copy, so fast) to a Light type obj
// this member function is also declared to be a const (last  const), so it won't change the object which it
// belongs to.
bool Light::operator> (Light const& light_to_compare) const{
    return light_intensity_ > light_to_compare.GetIntensity();

}

// member function that compares "this" with and integer. 
// since ints are light and simple, no need to be worried about referencing or copying
// though this is also declared to be a const, won't change the Light object which it belongs to.
bool Light::operator> (int i) const{
    return light_intensity_ > i;
}

// a free function, that takes 2 different types and comapres then
// int and a const reference to Light type objects, in this order. 
bool operator>(int i, Light const& light_to_compare ){
    return i > light_to_compare.GetIntensity();
}


std::string Light::GetName() const {
    return light_prefix_ + " " + light_sufix_;
}

int Light::GetIntensity() const{
    return light_intensity_;
}

// Syntax of inheirit class
// note that Light is called and all the compatible args are passed to it
// Spotlight's unique arg is passed straight to the private var
SpotLight::SpotLight(std::string prefix, 
                     std::string sufix, 
                     int intensity,
                     std::string lightgroup):
                     Light(prefix, sufix, intensity), lightgroup_(lightgroup)
{
    
}

SpotLight::~SpotLight()
{

}

std::string SpotLight::GetName() const {
    return Light::GetName() + " " + lightgroup_;
}