//
// Created by lactosis on 8.1.18.
//

#ifndef AUTOMATA_DFAAUTOMATON_H
#define AUTOMATA_DFAAUTOMATON_H

#include <map>
#include <sstream>
#include "Automaton.h"
#define INTERACTIVE_MAXINPUTS 100

using namespace std;

template<typename T>
class DFAAutomaton : public Automaton<T> {
private:
    vector<vector<int>> transitions;
    int initialState = -1;
    vector<int> finalStates;

    void interactiveGetStatesSigma(istream& ss);

    void interactiveGetStatesTable(istream& ss);

    void interactiveGetStateRow(istream& ss, unsigned int i);

protected:
    int transition(int state, int letter) override;


public:

    bool accepts(vector<T> word) override;

    //region CONSTUCTORS

    DFAAutomaton(vector<string> states, vector<T> letters, map<string, map<T, string>> transitions, string starting,
                 vector<string> finishing);

    DFAAutomaton(map<string, map<T, string>> transitions, string starting, vector<string> final);

    /**
     * Interactive constructor will ask for user input and create Automaton based on that input
     */
    DFAAutomaton() : DFAAutomaton(cin) {};

    /**
     * Implementation of an interactive constructor.
     * @param ss Stream to get data from
     */
    explicit DFAAutomaton(istream& ss);

    string getAutomatonTable() override;

    string getAutomatonTableHTML() override;

    string getAutomatonTableTEX() override;

    string getAutomatonVisualTIKZ() override;
    void printAutomatonTable() override;

    //endregion

    string transition(const string &state, T letter) override;

    string getInitialState();

    bool isFinalState(int state) override;

    bool isFinalState(string state) override;

    vector<string> getAcceptingStates();

    void
    initializeVariables(vector<string> states, vector<T> letters, map<string, map<T, string>> transitions,
                        string starting,
                        vector<string> finishing);
};




#endif //AUTOMATA_DFAAUTOMATON_H
