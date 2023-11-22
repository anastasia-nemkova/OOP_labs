#pragma once

#include "figure.hpp"

template <typename T>
class Hexagon : public Figure<T> {
    public:
    std::vector<std::pair<T, T>> points;

    Hexagon(){
        points.resize(6, {0,0});
    }

    Hexagon(const std::vector<std::pair<T, T>>& v) :  points(v) {
         if (v.size() != 6) {
            throw std::invalid_argument("Hexagon needs 6 vertices.");
        }
    }

    T Square() const override {
        T area = 0;
        for (int i = 0; i < 5; ++i) {
            area += points[i].first * points[i + 1].second - points[i + 1].first * points[i].second;
        }
        area += points[5].first * points[0].second - points[0].first * points[5].second;
        return std::abs(area) / 2;
    }

    typename Figure<T>::point Center() const override {
        T centerX = 0, centerY = 0;
        for (const auto &point : points) {
            centerX += point.first;
            centerY += point.second;
        }
        centerX /= 6;
        centerY /= 6;
        return {centerX, centerY};
    }

    Hexagon& operator=(const Hexagon<T>& other) {
        points = other.points;
        return *this;
    }

    Hexagon& operator=(Hexagon<T>&& other) {
        points = std::move(other.points);
        return *this;
    }

    bool operator==(const Hexagon& other) const {
        if (points.size() != other.points.size()) {
            return false;
        }
        for (size_t i = 0; i < points.size(); i++) {
            if (points[i] != other.points[i]) {
                return false;
            }
        }
        return true;
    }
    
    operator double() const override;

    ~Hexagon() = default;

}; 

template <typename T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T>& pent) {
    for (size_t i = 0; i != 6; ++i) {
        os << "(" << pent.points[i].first << ", " << pent.points[i].second << ")";
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Hexagon<T>& fig) {
    for (size_t i = 0; i != 6; ++i) {
        is >> fig.points[i].first >> fig.points[i].second;
    }

    return is;
}

template <typename T>
inline Hexagon<T>::operator double() const {
    return static_cast<double>(this->Square());
}
