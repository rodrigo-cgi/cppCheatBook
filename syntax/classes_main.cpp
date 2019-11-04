// this example is composed of 3 files: classes_main.cpp, classes.cpp and classes.h
// to compile use

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
// Which means, in Case an object Twitter is passed to this function, the function will only consider the data
// that is carried by the parent of Twitter Class; Light. Which means, the function wouldn't be able to access
// the private tweeter_handle_ , since it's not part of Light's class.
// In order to avoid the slice of datas, always pass a object as reference to a function, never as a value.
// and preferentially, a const reference, since objects rarelly should be modified by functions.
// Slicing prevents objects from being polimorphic.
//e.g.:

std::string Dummy(Light const& p) { return p.SetPrefix();}

std::string DumbSlice(Light p) { return p.SetPrefix();}


int main(){

    Light Kate ("Default", "Light", 123);
    Light & rKate = Kate; // a reference to the object Kate. 
    Light* pKate = &Kate; // A pointer to a memory address which contains the Kate obj

    SpotLight RodrigoJ("Spot", "Light", 123, "key");
    Light* pRodrigoJ = &RodrigoJ; // A pointer to the memory address where RodrigoJ lives in
    Light & rPersonRodrigoj = RodrigoJ; // A memory address of Light type, or reference, to Rodrigoj
    SpotLight & rTweeterRodrigoj = RodrigoJ; // A reference of Tweeter type to Rodrigoj

    cout << rKate.GetName() << endl;
    cout << pKate->GetName() << endl;
    cout << RodrigoJ.GetName() << endl;
    cout << rPersonRodrigoj.GetName() << endl;
    cout << rTweeterRodrigoj.GetName() << endl;
    cout << pRodrigoJ->GetName() << endl;

    // Createing and deleting a Light *  that points to a Tweeter Object
    // if destructor of Light is not virtual, Tweeters' destructor won't be ran
    Light * desctructor_test = new SpotLight("Destructor", "test", 223, "@destroy");
    cout << desctructor_test->GetName() << endl;
    delete desctructor_test; 

    // a shared pointer of Light type recieves a new shared Tweeter
    // remember, the shared_ptr and make_shared are the same idea as creating a "new Tweeter" , except that 
    // it already handles the copy, operator and destruction of the objet. Making it better to memory errors that 
    // usually happens when you create pointers in the heap/free store manually.
    shared_ptr<Light> spKate = make_shared<SpotLight>("Third", "Name", 123, "@Third");
    cout << spKate->GetName() << endl;

    // Copying one inherited class to a Parent class doesn't work by default:
    // Persong Obj = Tweeter Obj; -> won't work r.g.:
    // Kate =  RodrigoJ; 
    // For this to work, you need to implement the operator = for Light that receives Twitter Objs as argument
    // And then implement the copy function to fill the missing data with some kind of default. E.g. a default
    // for the tweeter_handle_ = "@unknown"
    
    std::string x;
    x = DumbSlice(RodrigoJ);
    cout << "RodrigoJ name from Light class " << x <<endl;
    x = Dummy(RodrigoJ);
    cout << "RodrigoJ name from Dummy class " << x <<endl;
    
    return 0;
}