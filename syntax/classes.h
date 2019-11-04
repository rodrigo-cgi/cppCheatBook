#pragma once
#include <iostream>

class Light {

private:

    std::string light_prefix_;
    std::string light_sufix_;
    int light_intensity_;

public:
    Light(std::string name, std::string surname, int number);
    // as soon as you have a virtual function, make sure your destructor is virtual
    virtual ~Light();

    // Copy constructor
    // Remeber & before variable means Reference, after it , means address of the variable
    // Light(Light const &p); 

     // assignment operator. this way when you use =, it overrides 
    // Light& operator=(const Light& original_person_object);

    void SetIntensity(int num) {int light_intensity_ = num;}
    void SetPrefix(std::string nm) {light_prefix_ = nm;}
    virtual std::string GetName() const;
    int GetIntensity();

};

class SpotLight :
    public Light{
    
    private:
        std::string lightgroup_; 

    public:
        SpotLight (std::string name, std::string surname, int number, std::string handle);
        virtual ~SpotLight();
        // const functions don't modify the object 
        virtual std::string GetName() const; 

};