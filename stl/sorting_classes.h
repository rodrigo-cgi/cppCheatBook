#pragma once
#include <iostream>

class Char {

    private:
        std::string name_;
        std::string role_;
        int index_;
    
    public:
        Char(std::string name, std::string role, int index);
        ~Char();
        std::string GetName() const {return name_;};
        int GetIndex() const {return index_;};
};
