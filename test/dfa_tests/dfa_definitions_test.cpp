#include <DFAAutomaton.h>
#include <fstream>
#include "gtest/gtest.h"


using namespace std;

TEST(definition_explicit, test_dfa) {
    //      a   b
    // <S   A   A
    // >A   A   B
    //  B   C   S
    // <C   A   C

    vector<string> states;
    states.emplace_back("S");
    states.emplace_back("A");
    states.emplace_back("B");
    states.emplace_back("C");

    vector<string> letters;
    letters.emplace_back("a");
    letters.emplace_back("b");

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


//    DFAAutomaton<string> automaton(states, letters, transitions, starting, finishing);
//    ASSERT_EQ(automaton.transition("S", "a"), "A");
//    ASSERT_EQ(automaton.transition("S", "b"), "A");
//    ASSERT_EQ(automaton.transition("A", "a"), "A");
//    ASSERT_EQ(automaton.transition("A", "b"), "B");
//    ASSERT_EQ(automaton.transition("B", "a"), "C");
//    ASSERT_EQ(automaton.transition("B", "b"), "S");
//    ASSERT_EQ(automaton.transition("C", "a"), "A");
//    ASSERT_EQ(automaton.transition("C", "b"), "C");
}

TEST(definition_interactive_string, test_dfa) {
    // Input file
    //      a   b
    // <S   A   A
    // >A   A   B
    //  B   C   S
    // <C   A   C
    //  D   D   D

    ifstream ss("interactive_DFA_string.txt");
    ASSERT_TRUE(ss.good());
    DFAAutomaton<string> automaton(ss);
    //Test definition
    ASSERT_EQ(2, automaton.getSigma().size());
    ASSERT_EQ(5, automaton.getStates().size());
    ASSERT_EQ(2, automaton.getSigmaSize());
    ASSERT_EQ(5, automaton.getStatesSize());
    vector<string> states = automaton.getStates();
    ASSERT_EQ("S", states[0]);
    ASSERT_EQ("A", states[1]);
    ASSERT_EQ("B", states[2]);
    ASSERT_EQ("C", states[3]);
    ASSERT_EQ("D", states[4]);
    states[4] = "F";
    states = automaton.getStates();
    ASSERT_EQ(states[4], "D");
    vector<string> letters = automaton.getSigma();
    ASSERT_EQ("ahoj", letters[0]);
    ASSERT_EQ("bouda", letters[1]);
    //Test functionality
    ASSERT_EQ(automaton.transition("S", "ahoj"), "A");
    ASSERT_EQ(automaton.transition("S", "bouda"), "A");
    ASSERT_EQ(automaton.transition("A", "ahoj"), "A");
    ASSERT_EQ(automaton.transition("A", "bouda"), "B");
    ASSERT_EQ(automaton.transition("B", "ahoj"), "C");
    ASSERT_EQ(automaton.transition("B", "bouda"), "S");
    ASSERT_EQ(automaton.transition("C", "ahoj"), "A");
    ASSERT_EQ(automaton.transition("C", "bouda"), "C");
    ASSERT_EQ("D", automaton.transition("D", "ahoj"));
    ASSERT_EQ("D", automaton.transition("D", "bouda"));
    ASSERT_EQ("A", automaton.getInitialState());
    vector<string> finals = automaton.getAcceptingStates();
    ASSERT_TRUE(std::find(finals.begin(), finals.end(), "S") != finals.end());
    ASSERT_TRUE(std::find(finals.begin(), finals.end(), "C") != finals.end());
    vector<string> word {"ahoj", "ahoj", "bouda", "bouda"};
    ASSERT_TRUE(automaton.accepts(word));
    vector<string> word2 {"ahoj", "ahoj", "ahoj", "bouda"};
    ASSERT_FALSE(automaton.accepts(word2));
    vector<string> word3 {"nazdar", "karel"};
    ASSERT_FALSE(automaton.accepts(word3));

    cout << endl;
}

TEST(definition_interactive_int, test_dfa) {
    ifstream ss("interactive_DFA_int.txt");
    ASSERT_TRUE(ss.good());
    DFAAutomaton<int> automaton(ss);
    //Test definition
    ASSERT_EQ(2, automaton.getSigma().size());
    ASSERT_EQ(3, automaton.getStates().size());
    ASSERT_EQ(2, automaton.getSigmaSize());
    ASSERT_EQ(3, automaton.getStatesSize());
    vector<string> states = automaton.getStates();
    ASSERT_EQ("S", states[0]);
    ASSERT_EQ("A", states[1]);
    ASSERT_EQ("B", states[2]);
    vector<int> letters = automaton.getSigma();
    ASSERT_EQ(2, letters[0]);
    ASSERT_EQ(4, letters[1]);
    vector<int> word {2, 2};
    ASSERT_TRUE(automaton.accepts(word));
    vector<int> word2 {4, 4, 2, 2, 2, 2};
    ASSERT_FALSE(automaton.accepts(word2));
    cout << endl;
}