// this example is composed of 3 files: classes_main.cpp, classes.cpp and classes.h
// to compile use:
// g++ -Wall -Wextra -pedantic -O2 -o compiled/classes.out classes.h classes.cpp classes_main.cpp;./compiled/classes.out

#include <iostream>
#include "classes.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

// function used to show Slicing - End of Main.
// int Dummy(Light p) { return p.GetIntensity;}
// when the Object Light is passed by value. It may cause Slicing.
// Which means, in Case an object SpotLight is passed to this function, the function will only consider the data
// that is carried by the parent of SpotLight Class; Light. Which means, the function wouldn't be able to access
// the private lightgroup, since it's not part of Light's class.
// In order to avoid the slice of datas, always pass a object as reference to a function, never as a value.
// and preferentially, a const reference, since objects rarelly should be modified by functions.
// Slicing prevents objects from being polimorphic.
//e.g.:

std::string Dummy(Light const& p) { return p.GetName();}

std::string DumbSlice(Light p) { return p.GetName();}


int main(){

    Light Dome ("Default", "Light", 123);
    Light & rDome = Dome; // a reference to the object Dome. 
    Light* pDome = &Dome; // A pointer to a memory address which contains the Dome obj

    SpotLight Key("Spot", "Light", 113, "keylight_grp");
    Light* pKey = &Key; // A pointer to the memory address where Key lives in
    Light & rPersonKey = Key; // A memory address of Light type, or reference, to Key
    SpotLight & rSpotLightKey = Key; // A reference of SpotLight type to Key

    cout << endl;
    cout << rDome.GetName() << endl;
    cout << pDome->GetName() << endl;
    cout << Key.GetName() << endl;
    cout << rPersonKey.GetName() << endl;
    cout << rSpotLightKey.GetName() << endl;
    cout << pKey->GetName() << endl;

    // Createing and deleting a Light *  that points to a SpotLight Object
    // if destructor of Light is not virtual, SpotLights' destructor won't be ran
    Light * desctructor_test = new SpotLight("Destructor", "test", 223, "destroy_grp");
    cout << desctructor_test->GetName() << endl;
    delete desctructor_test; 

    // a shared pointer of Light type recieves a new shared SpotLight
    // remember, the shared_ptr and make_shared are the same idea as creating a "new SpotLight" , except that 
    // it already handles the copy, operator and destruction of the objet. Making it better to memory errors that 
    // usually happens when you create pointers in the heap/free store manually.
    // it's good to use if you are aware the object will be used in multiple scopes
    shared_ptr<Light> spDome = make_shared<SpotLight>("Third", "Name", 123, "third_grp");
    cout << spDome->GetName() << endl;

    // Copying one inherited class to a Parent class doesn't work by default:
    // Light Obj = SpotLight Obj; -> won't work e.g.:
    // Dome =  Key; 
    // For this to work, you need to implement the operator = for Light that receives SpotLight Objs as argument
    // And then implement the copy function to fill the missing data with some kind of default. E.g. a default
    // for the Spotlight's lightgroup_ = "deafult_grp"
    
    std::string x;
    x = DumbSlice(Key);
    cout << "Key name from Light class " << x <<endl;
    x = Dummy(Key);
    cout << "Key name from Dummy class " << x <<endl;

    // comparing sizes using the operator overloads
    cout << endl;
    cout << "Is Dome > Key? In this case, comparting intensities: " << endl;
    bool comparison = Dome > Key;
    cout << "Dome intensity: " << Dome.GetIntensity() << endl;
    cout << "Key intensity: " << Key.GetIntensity() << endl; 
    cout << "Dome > key = " << comparison << endl;
    cout << "Dome > 999 = " << (Dome > 999) << endl;
    
    return 0;
}