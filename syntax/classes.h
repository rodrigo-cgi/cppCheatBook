#pragma once
#include <iostream>

class Light {

private: // can only be accessed by Light

    std::string light_prefix_;
    std::string light_sufix_;
    int light_intensity_;

public:
   
    // Constructor:  
    Light(std::string prefix, std::string sufix, int intensity);
    // as soon as you have a virtual function, make sure your destructor is virtual, otherwise child classes 
    // will always use Parent's class destructor
    virtual ~Light();

    // Copy constructor
    // Remeber & before variable means Reference, after it , means address of the variable
    // Light(Light const &p); 

     // assignment operator. this way when you use =, it overrides 
    // Light& operator=(const Light& original_person_object);

    // Operator override. Re-implemeting the operater > to compare lights by its intensities
    bool operator> (Light const& light_to_compare) const;
    bool operator> (int i) const;  // comparing with int

    // Member functions:
    void SetIntensity(int num) {int light_intensity_ = num;}  // 1 line functions can be initialized in header.
    void SetPrefix(std::string & nm) {light_prefix_ = nm;}
    virtual std::string GetName() const; // use as much consts as you can, for every func that doesn't change the object.
    virtual int GetIntensity() const;

 
protected: // can be accessed by Light n SpotLight. For safety, use public setters and getters instead.

};

// reimplementing the operator > to compare with an int, but the int beeing before the > and Light after
bool operator>(int i, Light const& light);


class SpotLight :
    public Light{
    
    private:
        std::string lightgroup_; 

    public:
        SpotLight (std::string prefix, std::string sufix, int intensity, std::string lightgroup);
        virtual ~SpotLight();
        // const functions don't modify the object 
        virtual std::string GetName() const; 

};