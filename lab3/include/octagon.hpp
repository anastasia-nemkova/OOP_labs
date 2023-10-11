#pragma once

#include "figure.hpp"
#include "point.hpp"

class Octagon : public Figure {
private:
    Point points[8];
public:
    Octagon() = default;
    Octagon(std::istream &is);

    void Print(std::ostream &os) const override;
    double Square() const override;
    Point Center() const override;
   
    Octagon(const Octagon& other); // Конструктор копирования
    Octagon(Octagon&& other) noexcept; // Конструктор перемещения
    bool operator==(const Octagon& other) const; // Оператор сравнения
    
    virtual ~Octagon() = default;
};
