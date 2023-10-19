#include "octagon.hpp"

Octagon::Octagon(std::istream &is) {
    for (int i = 0; i < 8; i++) {
        is >> points[i];
    }
}

void Octagon::Print(std::ostream &os) const {
    for (const auto& p :points) {
        os << p << " ";
    }
    os << std::endl;
}

double Octagon::Square() const {
    double result = 0;
    for(unsigned i = 0; i < 8; ++i) {
        Point p1 = i ? points[i - 1] : points[7];
        Point p2 = points[i];
        result += (p1.getX() - p2.getX()) * (p1.getY() + p2.getY());
    }
    return fabs(result) / 2.0;
}

Figure& Octagon::operator=(const Figure& other){
    const Octagon* otherOctagon = dynamic_cast<const Octagon*>(&other);
    for (int i = 0; i < 5; ++i) {
        points[i] = otherOctagon->points[i];
    }
    return *this;
}

Figure& Octagon::move(Figure&& other) noexcept {
    const Octagon* otherOctagon = dynamic_cast<const Octagon*>(&other);
    for (int i = 0; i < 5; ++i) {
        points[i] = std::move(otherOctagon->points[i]);
    }
    return *this;
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* otherOctagon = dynamic_cast<const Octagon*>(&other);
    for (int i = 0; i < 5; ++i) {
        if (points[i].getX() != otherOctagon->points[i].getX() || points[i].getY() != otherOctagon->points[i].getY()) {
            return false;
        }
    }
    return true;
}


Point Octagon::Center() const {
    double centerX = 0.0;
    double centerY = 0.0;

    for (const Point& point : points) {
        centerX += point.getX();
        centerY += point.getY();
    }

    centerX /= 8.0;
    centerY /= 8.0;

    return Point(centerX, centerY);
}

