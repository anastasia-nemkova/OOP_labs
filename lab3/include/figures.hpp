#pragma once

#include "figure.hpp"
#include "point.hpp"
#include "octagon.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"

class Figures {
public:
    Figures();
    Figures(const size_t& n, unsigned char t);
    Figures(const std::initializer_list<unsigned char>& t);

    void addFigure(Figure *figure);
    void deleteFigureAtIndex(size_t index);
    double calculateTotalArea() const;
    Figure* getFigureForIndex(size_t index);
    size_t getSize() const;

    ~Figures();

private:
    size_t size;
    Figure** data;
};