#include <iostream>
#include "include/figures.hpp"

int get_command() {
    int command;
    std::cin >> command;
    return command;
}

int main() {
    int command1, command2;

    Figures<double> figuresArray;

    std::cout << "1 - add figure to the array\n"
                 "2 - delete figure from the array\n"
                 "3 - call common functions for the whole array\n"
                 "4 - get the total area of figures in the array\n"
                 "0 - exit\n";

    while ((command1 = get_command()) != 0) {
        if (command1 == 1) {
            std::unique_ptr<Figure<double>> f;  // Use smart pointers for Figure objects
            std::cout << "1 - Pentagon, 2 - Hexagon, 3 - Octagon" << std::endl;
            std::cin >> command2;
            if (command2 == 1) {
                std::vector<typename Figure<double>::point> points;
                for (int i = 0; i < 5; ++i) {
                    double x, y;
                    std::cout << "Enter x and y for point " << i + 1 << ": ";
                    std::cin >> x >> y;
                    points.emplace_back(x, y);
                }
                f = std::make_unique<Pentagon<double>>(points);
            } else if (command2 == 2) {
                std::vector<typename Figure<double>::point> points;
                for (int i = 0; i < 6; ++i) {
                    double x, y;
                    std::cout << "Enter x and y for point " << i + 1 << ": ";
                    std::cin >> x >> y;
                    points.emplace_back(x, y);
                }
                f = std::make_unique<Hexagon<double>>(points);
            } else if (command2 == 3) {
                std::vector<typename Figure<double>::point> points;
                for (int i = 0; i < 8; ++i) {
                    double x, y;
                    std::cout << "Enter x and y for point " << i + 1 << ": ";
                    std::cin >> x >> y;
                    points.emplace_back(x, y);
                }
                f = std::make_unique<Octagon<double>>(points);
            } else {
                std::cout << "Wrong input" << std::endl;
            }
            if (f) {
                figuresArray.addFigure(std::move(f));
            }
        } else if (command1 == 2) {
            std::cout << "Enter index" << std::endl;
            std::cin >> command2;
            figuresArray.deleteFigureAtIndex(command2);
        } else if (command1 == 3) {
            for (size_t i = 0; i < figuresArray.getSize(); ++i) {
                auto figure = figuresArray.getFigureForIndex(i);
                if (figure) {
                    std::cout << figure->Center().first << "," << figure->Center().second << std::endl;
                    std::cout << figure->Square() << std::endl;
                }
            }
        } else if (command1 == 4) {
            double totalArea = figuresArray.calculateTotalArea();
            std::cout << "Total area of figures: " << totalArea << std::endl;
        } else if (command1 == 0) {
            break;
        }
    }

    return 0;
}
