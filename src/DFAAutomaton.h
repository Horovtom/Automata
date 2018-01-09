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



public:

    bool accepts(vector<T> word) override;

protected:
    int transition(int state, int letter) override;

public:
    //region CONSTUCTORS

    /**
     * Interactive constructor will ask for user input and create Automaton based on that input
     */
    DFAAutomaton() : DFAAutomaton(cin) {};

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
};




#endif //AUTOMATA_DFAAUTOMATON_H
