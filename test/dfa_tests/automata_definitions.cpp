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

DFAAutomaton<char> getDFA2char() {

    vector<char> sigma = {'l', 'o', 'i', 'p'};
    vector<string> states = {"0", "1", "2", "3", "4", "5", "6", "7"};
    std::string initial = "0";
    std::vector<std::string> final = {"7"};
    map<string, map<char, string>> transitions = {
            {"0", {
                          {'l', "1"},
                          {'o', "0"},
                          {'i', "0"},
                          {'p', "0"}}},
            {"1", {
                          {'l', "0"},
                          {'o', "2"},
                          {'i', "0"},
                          {'p', "0"}}},
            {"2", {
                          {'l', "3"},
                          {'o', "0"},
                          {'i', "0"},
                          {'p', "0"}}},
            {"3", {
                          {'l', "0"},
                          {'o', "0"},
                          {'i', "4"},
                          {'p', "0"}}},
            {"4", {
                          {'l', "0"},
                          {'o', "0"},
                          {'i', "0"},
                          {'p', "5"}}},
            {"5", {
                          {'l', "0"},
                          {'o', "6"},
                          {'i', "0"},
                          {'p', "0"}}},
            {"6", {
                          {'l', "0"},
                          {'o', "0"},
                          {'i', "0"},
                          {'p', "7"}}},
            {"7", {
                          {'l', "7"},
                          {'o', "7"},
                          {'i', "7"},
                          {'p', "7"}}},
    };

    return DFAAutomaton<char>(states, sigma, transitions, initial, final);
}

DFAAutomaton<double> getDFA2double() {
    vector<double> sigma = {0.12, -6.38, 0, 213.002};
    vector<string> states = {"0", "1", "2", "3", "4", "5", "6", "7"};
    std::string initial = "0";
    std::vector<std::string> final = {"7"};
    map<string, map<double, string>> transitions = {
            {"0", {
                          {0.12, "1"},
                          {-6.38, "0"},
                          {0, "0"},
                          {213.002, "0"}}},
            {"1", {
                          {0.12, "0"},
                          {-6.38, "2"},
                          {0, "0"},
                          {213.002, "0"}}},
            {"2", {
                          {0.12, "3"},
                          {-6.38, "0"},
                          {0, "0"},
                          {213.002, "0"}}},
            {"3", {
                          {0.12, "0"},
                          {-6.38, "0"},
                          {0, "4"},
                          {213.002, "0"}}},
            {"4", {
                          {0.12, "0"},
                          {-6.38, "0"},
                          {0, "0"},
                          {213.002, "5"}}},
            {"5", {
                          {0.12, "0"},
                          {-6.38, "6"},
                          {0, "0"},
                          {213.002, "0"}}},
            {"6", {
                          {0.12, "0"},
                          {-6.38, "0"},
                          {0, "0"},
                          {213.002, "7"}}},
            {"7", {
                          {0.12, "7"},
                          {-6.38, "7"},
                          {0, "7"},
                          {213.002, "7"}}},
    };
    return DFAAutomaton<double>(states, sigma, transitions, initial, final);
}

DFAAutomaton<string> getDFA3string() {
    vector<string> sigma = {"\\alpha", "\\beta"};
    vector<string> states = {"0", "1"};
    vector<string> finals = {"0"};
    string initial = "0";
    map<string, map<string, string>> transitions = {
            {"0", {
                          {"\\alpha", "0"},
                          {"\\beta", "1"}
                  }},
            {"1", {
                          {"\\alpha", "1"},
                          {"\\beta", "1"}
                  }}
    };

    return DFAAutomaton<string>(states, sigma, transitions, initial, finals);
}
