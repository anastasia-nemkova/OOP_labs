#pragma once

#include "figure.hpp"

template <typename T>
class Pentagon : public Figure<T> {
    public:
    std::vector<std::pair<T, T>> points;

    Pentagon(){
        points.resize(5, {0,0});
    }

    Pentagon(const std::vector<std::pair<T, T>>& v) :  points(v) {
         if (v.size() != 5) {
            throw std::invalid_argument("Pentagon needs 5 vertices.");
        }
    }

    T Square() const override {
        T area = 0;
        for (int i = 0; i < 4; ++i) {
            area += points[i].first * points[i + 1].second - points[i + 1].first * points[i].second;
        }
        area += points[4].first * points[0].second - points[0].first * points[4].second;
        return std::abs(area) / 2;
    }

    typename Figure<T>::point Center() const override {
        T centerX = 0, centerY = 0;
        for (const auto &point : points) {
            centerX += point.first;
            centerY += point.second;
        }
        centerX /= 5;
        centerY /= 5;
        return {centerX, centerY};
    }

    Pentagon& operator=(const Pentagon<T>& other) {
        points = other.points;
        return *this;
    }

    Pentagon& operator=(Pentagon<T>&& other) {
        points = std::move(other.points);
        return *this;
    }

    bool operator==(const Pentagon& other) const {
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

    ~Pentagon() = default;

}; 

template <typename T>
std::ostream& operator<<(std::ostream& os, const Pentagon<T>& pent) {
    for (size_t i = 0; i != 5; ++i) {
        os << "(" << pent.points[i].first << ", " << pent.points[i].second << ")";
    }
    return os;
}

template <typename T>
 std::istream& operator>>(std::istream& is, Pentagon<T>& fig) {
    for (size_t i = 0; i != 5; ++i) {
        is >> fig.points[i].first >> fig.points[i].second;
    }

    return is;
}

template <typename T>
inline Pentagon<T>::operator double() const {
    return static_cast<double>(this->Square());
}


