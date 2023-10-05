#pragma once

#include <iostream>
#include <initializer_list>
#include <stdexcept>

class BitString {
public:
    BitString(); // конструктор, создает пустую битовую строку
    BitString(const size_t& n, unsigned char t); // конструктор, создает битовую строку заданной длины
    BitString(const std::initializer_list<unsigned char>& value); // конструктор, создает битовую строку из инициализирующего списка
    BitString(const std::string& binaryString); // конструктор, создает битовую строку из строки битов
    BitString(const BitString& other); // конструктор копирования
    BitString(BitString&& other) noexcept; // конструктор перемещения

    // Операции сравнения
    bool operator==(const BitString& other) const;
    bool operator!=(const BitString& other) const;
    bool operator>(const BitString& other) const;
    bool operator<(const BitString& other) const;
    bool operator>=(const BitString& other) const;
    bool operator<=(const BitString& other) const;

    // Арифметические операции
    BitString operator+(const BitString& other) const;
    BitString operator-(const BitString& other) const;

    // Операции присваивания
    BitString& operator=(const BitString& other);
    BitString& operator+=(const BitString& other) ;
    BitString& operator-=(const BitString& other) ;

    // Операции побитового И, ИЛИ, исключающего ИЛИ, и отрицания
    BitString operator&(const BitString& other) const;
    BitString operator|(const BitString& other) const;
    BitString operator^(const BitString& other) const;
    BitString operator~() const;

    std::ostream&  print(std::ostream& os);
    virtual ~BitString() noexcept;

private:
    unsigned char* data;
    size_t size;  
};