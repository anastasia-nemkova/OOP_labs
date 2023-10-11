#pragma once

#include "figure.hpp"
#include "point.hpp"

class Pentagon : public Figure {
private:
    Point points[5];
public:
    Pentagon() = default;
    Pentagon(std::istream &is);

    void Print(std::ostream &os) const override;
    double Square() const override;
    Point Center() const override;
   
    Pentagon(const Pentagon& other); // Конструктор копирования
    Pentagon(Pentagon&& other) noexcept; // Конструктор перемещения
    bool operator==(const Pentagon& other) const; // Оператор сравнения
    
    virtual ~Pentagon() = default;
};
