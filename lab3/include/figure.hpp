#pragma once

#include<iostream>
#include <vector>
#include "point.hpp"

class Figure {
public:
    ~Figure() = default;
    virtual void Print(std::ostream &os) const = 0;
    virtual double Square() const = 0;
    virtual Point Center() const = 0;
};

