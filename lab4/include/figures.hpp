#pragma once

#include "figure.hpp"
#include <memory>
#include "octagon.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"

template <class T>
class Figures {
public:
    Figures() : size(0), data(nullptr) {}

    Figures(const size_t& n, unsigned char t) : size(n) {
        data = std::make_unique<std::unique_ptr<Figure<T>>[]>(size);
        for (size_t i = 0; i < size; ++i) {
            data[i] = nullptr;
        }
    }

    Figures(const std::initializer_list<unsigned char>& t) : size(t.size()) {
        data = std::make_unique<std::unique_ptr<Figure<T>>[]>(size);
        size_t index = 0;
        for (const unsigned char& val : t) {
            if (val == 5) {
                data[index] = std::make_unique<Pentagon<T>>();
            } else if (val == 6) {
                data[index] = std::make_unique<Hexagon<T>>();
            } else if (val == 8) {
                data[index] = std::make_unique<Octagon<T>>();
            } else {
                data[index] = nullptr;
            }
            index++;
        }
    }

    void addFigure(std::unique_ptr<Figure<T>> figure) {
        auto newFigures = std::make_unique<std::unique_ptr<Figure<T>>[]>(size + 1);
        for (size_t i = 0; i < size; ++i) {
            newFigures[i] = std::move(data[i]);
        }
        newFigures[size] = std::move(figure);
        data = std::move(newFigures);
        ++size;
    }

    void deleteFigureAtIndex(size_t index) {
        if (index < size) {
            data[index].reset();
            for (size_t i = index; i < size - 1; i++) {
                data[i] = std::move(data[i + 1]);
            }
            size--;
        } else {
            std::cout << "Element with such index doesn't exist" << std::endl;
        }
    }

    double calculateTotalArea() const {
        double totalArea = 0.0;
        for (size_t i = 0; i < size; ++i) {
            if (data[i]) {
                totalArea += data[i]->Square();
            }
        }
        return totalArea;
    }

    std::unique_ptr<Figure<T>> getFigureForIndex(size_t index) {
        if (index < size) {
            return std::move(data[index]);
        }
        return nullptr;
    }

    size_t getSize() const {
        return size;
    }

private:
    size_t size;
    std::unique_ptr<std::unique_ptr<Figure<T>>[]> data;
};
