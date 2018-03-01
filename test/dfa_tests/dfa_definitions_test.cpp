#include <DFAAutomaton.h>
#include <fstream>
#include "gtest/gtest.h"
#include "automata_definitions.h"

//#define VERBOSE

using namespace std;

void testWords(DFAAutomaton<string> automaton) {
    std::random_device rd;
    std::mt19937_64 eng(rd());
    std::uniform_int_distribution<> distribution(0, 5000);
    std::string s;

    s.append("Testing word: a*bab* should be in L\nActual word generated: \n");

    vector<string> word;
    for (int j = 0; j < distribution(eng); ++j) {
        word.emplace_back("a");
        s.append("a");
    }
    word.emplace_back("b");
    s.append("b");
    word.emplace_back("a");
    s.append("a");
    for (int k = 0; k < distribution(eng); ++k) {
        word.emplace_back("b");
        s.append("b");
    }

    s.append("\n");
    ASSERT_TRUE(automaton.accepts(word));

    s.append("Testing word: bbba* should not be in L\nActual word generated: \n");
    vector<string> word2 = {"b", "b", "b"};
    s.append("bbb");
    for (int i = 0; i < distribution(eng); ++i) {
        word2.emplace_back("a");
        s.append("a");
    }
    s.append("\n");
    ASSERT_FALSE(automaton.accepts(word2));

    s.append("Testing word: a*baaa*b should not be in L\nActual word generated: \n");
    vector<string> word3;
    for (int l = 0; l < distribution(eng); ++l) {
        word3.emplace_back("a");
        s.append("a");
    }
    word3.emplace_back("b");
    s.append("b");
    word3.emplace_back("a");
    s.append("a");
    word3.emplace_back("a");
    s.append("a");
    for (int m = 0; m < distribution(eng); ++m) {
        word3.emplace_back("a");
        s.append("a");
    }
    word3.emplace_back("b");
    s.append("b\n");
    ASSERT_FALSE(automaton.accepts(word3));

    s.append("Testing word: abb should be in L\n");
    vector<string> word4 = {"a", "b", "b"};
    ASSERT_TRUE(automaton.accepts(word4));

    s.append("Testing empty word, it should not be in L\n");
    vector<string> word5;
    ASSERT_FALSE(automaton.accepts(word5));

    s.append("Testing word: b^(3*i)bab*abb should be in L\nActual word generated: \n");
    for (int r = 0; r < 3 * distribution(eng); ++r) {
        word5.emplace_back("b");
        s.append("b");
    }
    word5.emplace_back("b");
    s.append("b");
    word5.emplace_back("a");
    s.append("a");
    for (int n = 0; n < distribution(eng); ++n) {
        word5.emplace_back("b");
        s.append("b");
    }
    word5.emplace_back("a");
    s.append("a");
    word5.emplace_back("b");
    s.append("b");
    word5.emplace_back("b");
    s.append("b\n");

    ASSERT_TRUE(automaton.accepts(word5));

    s.append("Testing word: ba should be in L\n");
    vector<string> word6 = {"b", "a"};
    ASSERT_TRUE(automaton.accepts(word6));

#ifdef VERBOSE
    cout << s << endl;
#endif
}

TEST(definition_compact, test_dfa) {
    //      a   b
    // <S   A   A
    // >A   A   B
    //  B   C   S
    // <C   A   C

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

    DFAAutomaton<string> automaton(transitions, starting, finishing);
    ASSERT_EQ(automaton.transition("S", "a"), "A");
    ASSERT_EQ(automaton.transition("S", "b"), "A");
    ASSERT_EQ(automaton.transition("A", "a"), "A");
    ASSERT_EQ(automaton.transition("A", "b"), "B");
    ASSERT_EQ(automaton.transition("B", "a"), "C");
    ASSERT_EQ(automaton.transition("B", "b"), "S");
    ASSERT_EQ(automaton.transition("C", "a"), "A");
    ASSERT_EQ(automaton.transition("C", "b"), "C");

    testWords(automaton);
}

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


    DFAAutomaton<string> automaton(states, letters, transitions, starting, finishing);
    ASSERT_EQ(automaton.transition("S", "a"), "A");
    ASSERT_EQ(automaton.transition("S", "b"), "A");
    ASSERT_EQ(automaton.transition("A", "a"), "A");
    ASSERT_EQ(automaton.transition("A", "b"), "B");
    ASSERT_EQ(automaton.transition("B", "a"), "C");
    ASSERT_EQ(automaton.transition("B", "b"), "S");
    ASSERT_EQ(automaton.transition("C", "a"), "A");
    ASSERT_EQ(automaton.transition("C", "b"), "C");

    testWords(automaton);
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

TEST(test_automaton_1, test_dfa) {
    DFAAutomaton<char> automaton = getDFA1char();
    ASSERT_TRUE(automaton.accepts({'b', 'b', 'b', 'a', 'b', 'a', 'b'}));
    ASSERT_FALSE(automaton.accepts({'b', 'b', 'b', 'a', 'b', 'a', 'a'}));
    ASSERT_TRUE(automaton.accepts({'a', 'b', 'a', 'a', 'b', 'b', 'a'}));
    ASSERT_FALSE(automaton.accepts({'a', 'a', 'a', 'a', 'b', 'b', 'b'}));

    std::random_device rd;
    std::mt19937_64 eng(rd());
    std::uniform_int_distribution<> distribution(0, 2);
    std::uniform_int_distribution<> distribution2(100, 2000);

    for (int i = 0; i < 100; ++i) {
        vector<char> word;
        for (int j = 0; j < distribution2(eng); ++j) {
            int res = distribution(eng);
            if (res == 0) {
                word.emplace_back('a');
            } else {
                word.emplace_back('b');
            }
        }
        if (word[0] != word[word.size() - 1]) {
            ASSERT_FALSE(automaton.accepts(word));
        } else {
            ASSERT_TRUE(automaton.accepts(word));
        }
    }

    //cout << automaton.getAutomatonTable() << endl;
}