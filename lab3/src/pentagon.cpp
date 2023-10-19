#include "pentagon.hpp"

Pentagon::Pentagon(std::istream &is) {
    for (int i = 0; i < 5; i++) {
        is >> points[i];
    }
}

Pentagon::Pentagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
    points[4] = p5;
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

Figure& Pentagon::operator=(const Figure& other){
    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
    for (int i = 0; i < 5; ++i) {
        points[i] = otherPentagon->points[i];
    }
    return *this;
}

Figure& Pentagon::move(Figure&& other) noexcept {
    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
    for (int i = 0; i < 5; ++i) {
        points[i] = std::move(otherPentagon->points[i]);
    }
    return *this;
}

bool Pentagon::operator==(const Figure& other) const {
    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
    for (int i = 0; i < 5; ++i) {
        if (points[i].getX() != otherPentagon->points[i].getX() || points[i].getY() != otherPentagon->points[i].getY()) {
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

