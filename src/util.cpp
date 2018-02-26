//
// Created by lactosis on 26.2.18.
//

#include "util.h"
#include <sstream>
#include <iomanip>

void padTo(std::string &str, int len, std::string appendix, char paddingChar) {
//    std::string append = std::move(appendix);
//    if (len > append.size()) {
//        append.insert(append.size() - 1, len, paddingChar);
//    }
//
//    str.append(append);

    std::ostringstream oss;
    oss << std::left << std::setw(len) << appendix;
    str.append(oss.str());
}

