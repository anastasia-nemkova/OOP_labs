#include "lab1.hpp"

std::string symbolsChange(std::string &str, int n, char oldValue, char newValue){
    if (n > str.length() || n <= 0) {
        return str;
    }
    std::string result = str;
    int count = 0;
    for(int i = 0; i < result.length(); ++i){
        if (result[i] == oldValue){
            count++;
            if(count % n == 0){
                result[i] = newValue;
            }
        }
    }
    return result;
}

