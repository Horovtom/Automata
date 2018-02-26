#include <DFAAutomaton.h>
#include <fstream>
#include "gtest/gtest.h"
#include "util.h"

TEST(to_string_test1, test_dfa) {
    std::string s = toString('a');
    cout << s;
}