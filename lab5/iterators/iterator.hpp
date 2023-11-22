#pragma once

#include <memory>
#include <iterator>

namespace iterators {
    
    template <class Node, class T>
    class Iterator {
    private:
        Node* node;

    public:
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;
        using Iterator_category = std::forward_iterator_tag;

        explicit Iterator(Node* ptr) : node(ptr) {}

        Node* get() const {
            return node;
        }

        reference operator*() const {
            if (node == nullptr) {
                throw std::out_of_range("Iterator dereference out of bounds");
            }
            return node->value;
        }

        pointer operator->() const {
            if (node == nullptr) {
                throw std::out_of_range("Iterator dereference out of bounds");
            }
            return &node->value; 
        }

        Iterator& operator++() {
            if (node == nullptr) {
                throw std::out_of_range("Iterator increment out of bounds");
            }
            node = node->next.get();
            return *this;
        }

        Iterator operator++(int) {
            Iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const Iterator& other) const {
            return node == other.node;
        }

        bool operator!=(const Iterator& other) const {
            return node != other.node;
        }
    };
};
