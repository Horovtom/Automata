#include "gtest/gtest.h"


using namespace std;

TEST(explicit_DFA, test_def) {
    //      a   b
    // <S   A   A
    // >A   A   B
    //  B   C   S
    // <C   A   C

    vector<string> states;
    states.push_back("S");
    states.push_back("A");
    states.push_back("B");
    states.push_back("C");

    vector<string> letters;
    letters.push_back("a");
    letters.push_back("b");

    map<string, map<string, string>> transitions{
            {"S", {
                          {"a", "A"},
                          {"b", "A"}
                  }},
            {"A", {
                          {"a", "A"},
                          {"b", "B"}
                  }},
            {"B", {
                          {"a", "C"},
                          {"b", "S"}
                  }},
            {"C", {
                          {"a", "A"},
                          {"b", "C"}
                  }}
    };

    string starting = "A";
    vector<string> finishing = {"S", "C"};


    DFAAutomaton automaton(states, letters, transitions, starting, finishing);
    ASSERT_EQ(automaton.fromBy("S", "a"), "A");
    ASSERT_EQ(automaton.fromBy("S", "b"), "A");
    ASSERT_EQ(automaton.fromBy("A", "a"), "A");
    ASSERT_EQ(automaton.fromBy("A", "b"), "B");
    ASSERT_EQ(automaton.fromBy("B", "a"), "C");
    ASSERT_EQ(automaton.fromBy("B", "b"), "S");
    ASSERT_EQ(automaton.fromBy("C", "a"), "A");
    ASSERT_EQ(automaton.fromBy("C", "b"), "C");

}