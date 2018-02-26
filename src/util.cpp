//
// Created by lactosis on 26.2.18.
//

#include "util.h"
#include <sstream>

void padTo(std::string &str, size_t len, std::string appendix, char paddingChar) {
    std::string append = std::move(appendix);
    if (len > append.size()) {
        append.insert(0, len - append.size(), paddingChar);
    }

    str.append(append);
}

