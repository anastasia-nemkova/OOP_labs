#pragma once

#include "allocator.hpp"
#include "iterator.hpp"
#include "const_iterator.hpp"
#include <functional>



namespace lists {
	
	template<class T, class Allocator = std::allocator<T>>
    class List{
    private:
        struct Node;
        using NodeAllocator = typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;
        using NodePointer = std::unique_ptr<Node, std::function<void(Node*)>>;

        struct Node {
            T value;
            NodePointer next;
            Node* prev;
            explicit Node(const T& value, Node* prev = nullptr)
                : value(value), next(nullptr), prev(prev) {}
        };

        size_t size;
        NodePointer first;
        Node* tail;

    public:
    
        using iterator = iterators::Iterator<Node, T>;
        using const_iterator = const_iterators::ConstIterator<Node, T>;

        
        List() : size(0), first(nullptr, NodeDeleter{ nullptr }), tail(nullptr) {}
        
        const_iterator cbegin() const {
            return const_iterator(first.get());
        }

        const_iterator cend() const {
            return const_iterator(nullptr);
        }

        iterator begin() {
            return iterator(first.get());
        }

        iterator end() {
            return iterator(nullptr);
        }

        void push_back(const T& value) {
            Node* newNode = allocateNode(value);
            if (size == 0) {
                first = NodePointer(newNode, NodeDeleter{ &nodeAllocator });
                tail = first.get();
            } else {
                tail->next = NodePointer(newNode, NodeDeleter{ &nodeAllocator });
                newNode->prev = tail;
                tail = newNode;
            }
            size++;
        }

        void push_front(const T& value) {
            Node* newNode = allocateNode(value);
            newNode->next = std::move(first);
            if (first) {
                first->prev = newNode;
            }
            first = NodePointer(newNode, NodeDeleter{ &nodeAllocator });
            if (size == 0) {
                tail = first.get();
            }
            size++;
        }

        void pop_front() {
            if (size == 0) {
                throw std::logic_error("Can't pop from an empty List");
            }
            first = std::move(first->next);
            if (first) {
                first->prev = nullptr;
            } else {
                tail = nullptr;
            }
            size--;
        }

        void pop_back() {
            if (size == 0) {
                throw std::logic_error("Can't pop from an empty List");
            }
            if (tail->prev) {
                tail = tail->prev;
                tail->next = nullptr;
            } else {
                first = nullptr;
                tail = nullptr;
            }
            size--;
        }

        T& front() {
            if (size == 0) {
                throw std::logic_error("List is empty");
            }
            return first->value;
        }

        T& back() {
            if (size == 0) {
                throw std::logic_error("List is empty");
            }
            return tail->value;
        }

        size_t length() const {
            return size;
        }

        bool empty() const {
            return size == 0;
        }

        List& operator=(const List& other) {
            if (this != &other) {
                clear();
                for (const auto& value : other) {
                    push_back(value);
                }
            }
            return *this;
        }

        T& operator[](size_t index) {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of bounds");
            }
            auto it = this->begin();
            for (size_t i = 0; i < index; i++) {
                it++;
            }
            return *it;
        }

        void insert(iterator position, const T& value) {
            if (position == this->begin()) {
                this->push_front(value);
                return;
            } else if (position == this->end()) {
                this->push_back(value);
                return;
            } else {
                Node* newNode = allocateNode(value);
                Node* prevNode = position.get()->prev;
                newNode->next = std::move(prevNode->next);
                newNode->prev = prevNode;
                prevNode->next = NodePointer(newNode, NodeDeleter{ &nodeAllocator });
                newNode->next->prev = newNode;
                size++;
            }
        }

        void erase(iterator position) {
            if (position == this->end()) {
                throw std::logic_error("Can't erase end Iterator");
            }
            if (position == this->begin()) {
                this->pop_front();
                return;
            }
            if (position.get() == tail) {
                this->pop_back();
                return;
            }
            
            Node* nodeToDelete = position.get();
            if (nodeToDelete->prev) {
                nodeToDelete->prev->next = std::move(nodeToDelete->next);
            } else {
                first = std::move(nodeToDelete->next);
            }
            if (nodeToDelete->next) {
                nodeToDelete->next->prev = nodeToDelete->prev;
            } else {
                tail = nodeToDelete->prev;
            }
            size--;
        }

        void clear() {
            first = nullptr;
            tail = nullptr;
            size = 0;
        }

    private:

        NodeAllocator nodeAllocator;

        struct NodeDeleter {
            NodeAllocator* allocator;

            void operator()(Node* ptr) const {
                if (ptr != nullptr) {
                    std::allocator_traits<NodeAllocator>::destroy(*allocator, ptr);
                    allocator->deallocate(ptr, 1);
                }
            }
        };

        Node* allocateNode(const T& value) {
            Node* newNode = nodeAllocator.allocate(1);
            std::allocator_traits<NodeAllocator>::construct(nodeAllocator, newNode, value);
            return newNode;
        }
    };
} 