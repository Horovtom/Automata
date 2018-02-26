#include "automata_definitions.h"
#include <fstream>
#include "gtest/gtest.h"


DFAAutomaton<char> getDFA1() {
    map<string, map<char, string>> transitions{
            {"1", {
                          {'a', "2"},
                          {'b', "1"}
                  }},
            {"2", {
                          {'a', "2"},
                          {'b', "1"}
                  }},
            {"3", {
                          {'a', "7"},
                          {'b', "5"}
                  }},
            {"4", {
                          {'a', "7"},
                          {'b', "4"}
                  }},
            {"5", {
                          {'a', "2"},
                          {'b', "4"}
                  }},
            {"6", {
                          {'a', "6"},
                          {'b', "3"}
                  }},
            {"7", {
                          {'a', "7"},
                          {'b', "4"}
                  }}
    };


    DFAAutomaton<char> automaton(transitions, "5", {"2", "4", "6"});
    return automaton;
}