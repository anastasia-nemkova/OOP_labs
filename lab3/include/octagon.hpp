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
    double Square() const;
    Point Center() const override;
   
    Figure& operator=(const Figure& other) override; // Конструктор копирования
    Figure& move(Figure&& other) noexcept override; // Конструктор перемещения
    bool operator==(const Figure& other) const override; // Оператор сравнения
    
    virtual ~Octagon() = default;
};
