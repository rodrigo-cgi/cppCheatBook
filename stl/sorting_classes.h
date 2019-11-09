#pragma once
#include <iostream>

namespace sorting_classes {

class Character {

    private:
        std::string name_;
        std::string role_;
        int index_;
    
    public:
        Character(std::string name, std::string role, int index);
        std::string GetName() const {return name_;};
        int GetIndex() const {return index_;};

        bool operator< (const Character& character) const;
};

}