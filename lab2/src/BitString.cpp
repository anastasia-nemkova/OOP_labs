#include "BitString.hpp"

BitString::BitString() : data(nullptr), size(0) {

}

BitString::BitString(const size_t &n, unsigned char t) {

    data = new unsigned char[n];
    for(size_t i = 0; i < n; ++i) {
        data[i] = t;
    }
    size = n;
}

BitString::BitString(const std::initializer_list<unsigned char>& value) {
    data = new unsigned char[value.size()];
    size_t index{0};
    for (const auto& bit : value) {
        if (bit != '0' && bit != '1') {
            throw std::invalid_argument("Initializer list must contain only 0 and 1");
        }
        data[index++] = bit -'0';
    }
    size = value.size();
}

BitString::BitString(const std::string& binaryString) {
    data = new unsigned char[binaryString.size()];
    size = binaryString.size();
    for (size_t i = 0; i < size; ++i) {
        if (binaryString[i] != '0' && binaryString[i] != '1') {
            throw std::invalid_argument("Input string must contain only '0's and '1'");
        }
        data[i] = binaryString[i];
    }
}

BitString::BitString(const BitString& other) {
    data = new unsigned char[size];
    size = other.size;
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

BitString::BitString(BitString&& other) noexcept {
    size = other.size;
    data = other.data;

    other.size = 0;
    other.data = nullptr;
}

bool BitString::operator==(const BitString& other) const {
    if (size == other.size) {
        for(size_t i = 0; i < size; ++i){
            if (data[i] != other.data[i]){
                return false;
            }
        }
    }
    return true;
}

bool BitString::operator!=(const BitString& other) const {
    if (*this == other) {
        return false;
    }
    return true;
}

bool BitString::operator>(const BitString& other) const {
    if (size > other.size) {
        return true;
    } else if (size < other.size) {
        return false;
    } else {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] > other.data[i]) {
                return true;
            } else if (data[i] < other.data[i]) {
                return false;
            }
        }
        return false;
    }
}

bool BitString::operator<(const BitString& other) const {
    if ((*this == other) || (*this > other)) {
        return false;
    }
    return true;
}

bool BitString::operator>=(const BitString& other) const {
    if ((*this > other) || (*this == other)) {
        return true;
    }
    return false;
}

bool BitString::operator<=(const BitString& other) const {
    if ((*this < other) || (*this == other)) {
        return true;
    }
    return false;
}

BitString BitString::operator+(const BitString& other) const{
    size_t maxSize = std::max(size, other.size) + 1;
    BitString res(maxSize, '0');
    int count = 0;

    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char bit1 = (i < size) ? data[size - 1 - i] : 0;
        unsigned char bit2 = (i < other.size) ? other.data[other.size - 1 - i] : 0;

        int sum = bit1 + bit2 + count;

        res.data[maxSize - 1 -  i] = sum % 2;
        count = sum / 2;
    }
    // Удаляем лидирующие нули из результата
    size_t first = 0;
    while (first < maxSize - 1 && res.data[first] == 0) {
        first++;
    }
    BitString newres(maxSize - first, '0');
    for (size_t i = first; i < maxSize; ++i) {
        newres.data[i - first] = res.data[i];
    }

    return newres;
}

BitString BitString::operator-(const BitString& other) const {
    size_t maxSize = std::max(size, other.size);
    BitString res(maxSize, '0');
    int count = 0;


    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char bit1 = (i < size) ? data[size - 1 - i] : 0;
        unsigned char bit2 = (i < other.size) ? other.data[other.size - 1 - i] : 0;

        int diff = bit1 - bit2 - count;

        if (diff < 0) {
            diff += 2;
            count = 1;
        } else {
            count = 0;
        }
        res.data[maxSize - 1 - i] = diff;
    }

    // Удаляем лидирующие нули из результата
    size_t first = 0;
    while (first < maxSize - 1 && res.data[first] == 0) {
        first++;
    }
    BitString newres(maxSize - first, '0');
    for (size_t i = first; i < maxSize; ++i) {
        newres.data[i - first] = res.data[i];
    }

    return newres;

}

BitString& BitString::operator=(const BitString& other){
    if (this == &other) {
        return *this;
    }
    ~(*this);
    size = other.size;
    data = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

BitString& BitString::operator+=(const BitString& other) {
    *this = *this + other;
    return *this;
 }

BitString& BitString::operator-=(const BitString& other) {
    *this = *this - other;
    return *this;
 }


BitString BitString::operator&(const BitString& other) const {
    if (size != other.size) {
        throw std::invalid_argument("BitStrings must have the same size for bitwise AND operation");        
    }
    BitString res(size, '0');
    for (size_t i = 0; i < size; ++i) {
        res.data[i] = data[i] & other.data[i];
    }
    return res;
}

BitString BitString::operator|(const BitString& other) const {
    if (size != other.size) {
        throw std::invalid_argument("BitStrings must have the same size for bitwise OR operation");        
    }
    BitString res(size, '0');
    for (size_t i = 0; i < size; ++i) {
        res.data[i] = data[i] | other.data[i];
    }
    return res;
}

BitString BitString::operator^(const BitString& other) const {
    if (size != other.size) {
        throw std::invalid_argument("BitStrings must have the same size for bitwise XOR operation");        
    }
    BitString res(size, '0');
    for (size_t i = 0; i < size; ++i) {
        res.data[i] = data[i] ^ other.data[i];
    }
    return res;
}

BitString BitString::operator~() const {
    BitString res(size, '0');
    for (size_t i = 0; i < size; ++i) {
        res.data[i] = ~data[i] & 1;
    }
    return res;
}


BitString::~BitString() noexcept{
    // Destructor
    if (size > 0) {
        size = 0;
        delete[] data;
        data = nullptr;
    }
}

std::ostream &BitString::print(std::ostream &os) {
    for (size_t i = 0; i < size; ++i) { 
        os << static_cast<int>(data[i]);
    }
    return os;
}
