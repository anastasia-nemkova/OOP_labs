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
    double Square() const;
    Point Center() const override;
   
    Figure& operator=(const Figure& other) override; // Конструктор копирования
    Figure& move(Figure&& other) noexcept override; // Конструктор перемещения
    bool operator==(const Figure& other) const override; // Оператор сравнения
    
    virtual ~Hexagon() = default;
};
