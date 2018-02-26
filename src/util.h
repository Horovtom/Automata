//
// Created by lactosis on 26.2.18.
//

#ifndef AUTOMATA_UTIL_H
#define AUTOMATA_UTIL_H

#include <iostream>
#include <sstream>

/**
     * This method pads appendix to have specified length with paddingChar and then it appends it to str
     * @param str To this appendix will be appended
     * @param appendix This will be padded to length len and then appended to str
     */
void padTo(std::string &str, int len, std::string appendix, char paddingChar = ' ');

template<typename T>
std::string toString(T t) {
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

#endif //AUTOMATA_UTIL_H
