#pragma once

#include<iostream>
#include <vector>
#include <string>
#include "point.hpp"

class Figure {
public:
    virtual Figure& operator=(const Figure& other)= 0; // Конструктор копирования
    virtual Figure& move(Figure&& other) noexcept = 0; // Конструктор перемещения
    virtual bool operator==(const Figure& other) const = 0; // Оператор сравнения

    virtual void Print(std::ostream &os) const = 0;
    virtual double Square() const = 0;
    virtual Point Center() const = 0;

    virtual ~Figure() = default;
};

