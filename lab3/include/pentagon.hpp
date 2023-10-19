#pragma once

#include "figure.hpp"
#include "point.hpp"

class Pentagon : public Figure {
private:
    Point points[5];
public:
    Pentagon() = default;
    Pentagon(std::istream &is);
    Pentagon(const Point& p1,const Point& p2, const Point& p3,  const Point& p4, const Point& p5);

    void Print(std::ostream &os) const override;
    double Square() const;
    Point Center() const override;
   
    Figure& operator=(const Figure& other) override; // Конструктор копирования
    Figure& move(Figure&& other) noexcept override; // Конструктор перемещения
    bool operator==(const Figure& other) const override; // Оператор сравнения
    
    virtual ~Pentagon() = default;
};
