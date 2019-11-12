#pragma once
#include <iostream>
#include "classes.h"
// Templates are NOT classes or functions. In a certain way, you can say they are instructions to genetate
// functions on the compile time. The advantage is, you can create very generic and re-usable templates thata
// are not strong typed.

// Though possible, the compiler doesn't expect you to separate declaration from implementation of templates.
// More details; https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
// It is possible to include a template compilation in the header, after the template has been declared.
// It's a bit unusual, prefer to avoid it.

// Template functions
template <class T> // in templates, the T usually is used for a placeholder Type. 
T max(T const& t1, T const& t2){
    return t1 <t2 ? t2: t1;
};


// Template Class
template<class T>
class Accum
{
    private:
        T total_;
    public:
        Accum(T start): total_(start) {};
        T operator +=(T const& t){return total_ = total_ + t;};
        T GetTotal() const {return total_;};
};

// Templates specialization, 
// Want to make Accum to work with Light classe. Doesn't work with child classes

template <>
class Accum<Light> {
    private:
        int total_; // we know light intensity is an int
    public:
        // replace all occurence of T on the public declarations as well: 
        Accum(int start): total_(start) {};
        int operator +=(Light const& t){return total_ = total_ + t.GetIntensity();}; // we now whats GetIntensity
        int GetTotal() const {return total_;};

};