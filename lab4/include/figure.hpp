#pragma once

#include <iostream>
#include <utility>
#include <cmath>
#include <vector>

template <typename T>
class Figure{
    public:
    using point = std::pair<T, T>;
    Figure() = default;

    virtual T Square() const = 0;
    virtual point Center() const = 0;

    virtual ~ Figure() = default;

    virtual explicit operator double() const {
        return 0.0;
    }
};