#include "classes.h"
#include <iostream>

Light::Light(std::string name, std::string surname, int number):
            light_prefix_(name), 
            light_sufix_(surname), 
            light_intensity_(number) 

{
std::cout << "initialized Light" << light_prefix_ << std::endl ;
}

Light::~Light(){
}
    

std::string Light::GetName() const {
    return light_prefix_ + " " + light_sufix_;
}

int Light::GetIntensity(){
    return light_intensity_;
}


SpotLight::SpotLight(std::string name, 
std::string surname, 
int number,
 std::string handle): Light(name, surname, number),
lightgroup_(handle)
{
    
}

SpotLight::~SpotLight()
{

}

std::string SpotLight::GetName() const {
    return Light::GetName() + " " + lightgroup_;
}