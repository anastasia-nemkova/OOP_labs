#include "figures.hpp"

Figures::Figures() : size(0), data(nullptr) {};

Figures::Figures(const size_t& n, unsigned char t) : size(n) {
   data = new Figure*[size];
        for (size_t i = 0; i < size; ++i) {
           data[i] = nullptr;
        }
}

Figures::Figures(const std::initializer_list<unsigned char>& t) : size(t.size()) {
        data = new Figure*[size];
        size_t index = 0;
        for (const unsigned char& val : t) {
            if (val == 5) {
                data[index] = new Pentagon();
            } else if (val == 6) {
                data[index] = new Hexagon();
            } else if(val == 8) {
                data[index] = new Octagon();
            } else {
                data[index] = nullptr;
            }
            index++;
        }
    }

void Figures::addFigure(Figure* figure) {
    Figure** newFigures = new Figure*[size + 1];
        for (size_t i = 0; i < size; ++i) {
            newFigures[i] = data[i];
        }
        newFigures[size] = figure;
        delete[] data;
        data = newFigures;
        ++size;
}

void Figures::deleteFigureAtIndex(size_t index) {
    // Удаление фигуры по индексу
    if (index < size) {
        delete data[index];
        for (size_t i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    } else {
        std::cout << "Element with such index doesn't exist" << std::endl;
    }
}

double Figures::calculateTotalArea() const {
    double totalArea = 0.0;
    for (size_t i = 0; i < size; ++i) {
        if (data[i]) {
            totalArea += data[i]->Square();
        }
    }
    return totalArea;
}

Figure* Figures::getFigureForIndex(size_t index) {
    if (index < size) {
        return data[index];
    }
    return nullptr;
}

size_t Figures::getSize() const {
    return size;
}

Figures::~Figures() {
    for (size_t i = 0; i < size; ++i) {
        if (data[i]) {
            delete data[i];
        }
    }
    delete[] data;
}