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

Octagon::Octagon(const Octagon& other) {
    for (int i = 0; i < 8; ++i) {
        points[i] = other.points[i];
    }
}

Octagon::Octagon(Octagon&& other) noexcept {
    for (int i = 0; i < 8; ++i) {
        points[i] = std::move(other.points[i]);
    }
}

bool Octagon::operator==(const Octagon& other) const {
    for (int i = 0; i < 8; ++i) {
        if (points[i].getX() != other.points[i].getX() || points[i].getY() != other.points[i].getY()) {
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

