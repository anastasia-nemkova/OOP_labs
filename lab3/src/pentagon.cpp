#include "pentagon.hpp"

Pentagon::Pentagon(std::istream &is) {
    for (int i = 0; i < 5; i++) {
        is >> points[i];
    }
}

void Pentagon::Print(std::ostream &os) const {
    for (const auto& p :points) {
        os << p << " ";
    }
    os << std::endl;
}

double Pentagon::Square() const {
    double area = 0.0;
    for (int i = 0; i < 4; ++i) {
        area += points[i].getX() * points[i + 1].getY() - points[i + 1].getX() * points[i].getY();
    }
    area += points[4].getX() * points[0].getY() - points[0].getX() * points[4].getY();
    return std::fabs(area) / 2.0;
}

Pentagon::Pentagon(const Pentagon& other) {
    for (int i = 0; i < 5; ++i) {
        points[i] = other.points[i];
    }
}

Pentagon::Pentagon(Pentagon&& other) noexcept {
    for (int i = 0; i < 5; ++i) {
        points[i] = std::move(other.points[i]);
    }
}

bool Pentagon::operator==(const Pentagon& other) const {
    for (int i = 0; i < 5; ++i) {
        if (points[i].getX() != other.points[i].getX() || points[i].getY() != other.points[i].getY()) {
            return false;
        }
    }
    return true;
}

Point Pentagon::Center() const {
    double centerX = 0.0;
    double centerY = 0.0;

    for (const Point& point : points) {
        centerX += point.getX();
        centerY += point.getY();
    }

    centerX /= 5.0;
    centerY /= 5.0;

    return Point(centerX, centerY);
}

