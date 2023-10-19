#include "hexagon.hpp"

Hexagon::Hexagon(std::istream &is) {
    for (int i = 0; i < 6; i++) {
        is >> points[i];
    }
}

void Hexagon::Print(std::ostream &os) const {
    for (const auto& p :points) {
        os << p << " ";
    }
    os << std::endl;
}

double Hexagon::Square() const {
    double result = 0;
    for(unsigned i = 0; i < 6; ++i) {
        Point p1 = i ? points[i - 1] : points[5];
        Point p2 = points[i];
        result += (p1.getX() - p2.getX()) * (p1.getY() + p2.getY());
    }
    return fabs(result) / 2.0;
}

Figure& Hexagon::operator=(const Figure& other){
    const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
    for (int i = 0; i < 5; ++i) {
        points[i] = otherHexagon->points[i];
    }
    return *this;
}

Figure& Hexagon::move(Figure&& other) noexcept {
    const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
    for (int i = 0; i < 5; ++i) {
        points[i] = std::move(otherHexagon->points[i]);
    }
    return *this;
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
    for (int i = 0; i < 5; ++i) {
        if (points[i].getX() != otherHexagon->points[i].getX() || points[i].getY() != otherHexagon->points[i].getY()) {
            return false;
        }
    }
    return true;
}


Point Hexagon::Center() const {
    double centerX = 0.0;
    double centerY = 0.0;
    for (const Point& p : points) {
        centerX += p.getX();
        centerY += p.getY();
    }
    centerX /= 6.0;
    centerY /= 6.0;

    return Point(centerX, centerY);
}

