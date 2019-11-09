#pragma once
#include "sorting_classes.h"
#include  <iostream>
 
using namespace sorting_classes;

sorting_classes::Character::Character(std::string name, std::string role, int index):
                name_(name), role_(role), index_(index)
{

};


bool sorting_classes::Character::operator <(const Character & character) const{

    return this->GetIndex() < character.GetIndex(); 

};
