#pragma once

#include "figure.hpp"
#include "point.hpp"

class Hexagon : public Figure {
private:
    Point points[6];
public:
    Hexagon() = default;
    Hexagon(std::istream &is);

    void Print(std::ostream &os) const override;
    double Square() const override;
    Point Center() const override;
   
    Hexagon(const Hexagon& other); // Конструктор копирования
    Hexagon(Hexagon&& other) noexcept; // Конструктор перемещения
    bool operator==(const Hexagon& other) const; // Оператор сравнения
    
    virtual ~Hexagon() = default;
};
