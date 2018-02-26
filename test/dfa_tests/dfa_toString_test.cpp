#include <DFAAutomaton.h>
#include <fstream>
#include "gtest/gtest.h"
#include "util.h"
#include "automata_definitions.h"

TEST(to_string_test_char, test_dfa) {
    DFAAutomaton<char> dfa = getDFA1char();

    std::string s = dfa.getAutomatonTable();
    ASSERT_EQ(s,
              "    a b \n"
                      "  1 2 1 \n"
                      "< 2 2 1 \n"
                      "  3 7 5 \n"
                      "< 4 7 4 \n"
                      " >5 2 4 \n"
                      "< 6 6 3 \n"
                      "  7 7 4 \n");
}

TEST(to_string_test_int, test_dfa) {
    DFAAutomaton<int> dfa = getDFA1int();

    std::string s = dfa.getAutomatonTable();
    ASSERT_EQ(s, "         0      1      \n"
            "  dodge  crit   dodge  \n"
            "< crit   crit   dodge  \n"
            "  miss   evade  parry  \n"
            "< block  evade  block  \n"
            " >parry  crit   block  \n"
            "< resist resist miss   \n"
            "  evade  evade  block  \n");
}

TEST(to_string_test_string, test_dfa) {
    DFAAutomaton<string> dfa = getDFA1string();

    std::string s = dfa.getAutomatonTable();
    ASSERT_EQ(s, "    abrakadabra berries     \n"
            "  1 2           1           \n"
            "< 2 2           1           \n"
            "  3 7           5           \n"
            "< 4 7           4           \n"
            " >5 2           4           \n"
            "< 6 6           3           \n"
            "  7 7           4           \n");


}