#include "automata_definitions.h"
#include <fstream>
#include "gtest/gtest.h"


DFAAutomaton<char> getDFA1char() {
    vector<char> sigma = {'a', 'b'};
    vector<string> states = {"1", "2", "3", "4", "5", "6", "7"};
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


    DFAAutomaton<char> automaton(states, sigma, transitions, "5", {"2", "4", "6"});
    return automaton;
}

DFAAutomaton<string> getDFA1string() {
    vector<string> states = {"1", "2", "3", "4", "5", "6", "7"};
    vector<string> sigma = {"abrakadabra", "berries"};

    map<string, map<string, string>> transitions{
            {"1", {
                          {"abrakadabra", "2"},
                          {"berries", "1"}
                  }},
            {"2", {
                          {"abrakadabra", "2"},
                          {"berries", "1"}
                  }},
            {"3", {
                          {"abrakadabra", "7"},
                          {"berries", "5"}
                  }},
            {"4", {
                          {"abrakadabra", "7"},
                          {"berries", "4"}
                  }},
            {"5", {
                          {"abrakadabra", "2"},
                          {"berries", "4"}
                  }},
            {"6", {
                          {"abrakadabra", "6"},
                          {"berries", "3"}
                  }},
            {"7", {
                          {"abrakadabra", "7"},
                          {"berries", "4"}
                  }}
    };
    DFAAutomaton<string> automaton(states, sigma, transitions, "5", {"2", "4", "6"});
    return automaton;
}

DFAAutomaton<int> getDFA1int() {
    vector<int> sigma = {0, 1};
    vector<string> states = {"dodge", "crit", "miss", "block", "parry", "resist", "evade"};

    map<string, map<int, string>> transitions{
            {"dodge",  {
                               {0, "crit"},
                               {1, "dodge"}
                       }},
            {"crit",   {
                               {0, "crit"},
                               {1, "dodge"}
                       }},
            {"miss",   {
                               {0, "evade"},
                               {1, "parry"}
                       }},
            {"block",  {
                               {0, "evade"},
                               {1, "block"}
                       }},
            {"parry",  {
                               {0, "crit"},
                               {1, "block"}
                       }},
            {"resist", {
                               {0, "resist"},
                               {1, "miss"}
                       }},
            {"evade",  {
                               {0, "evade"},
                               {1, "block"}
                       }}
    };
    DFAAutomaton<int> automaton(states, sigma, transitions, "parry", {"crit", "block", "resist"});
    return automaton;
}
