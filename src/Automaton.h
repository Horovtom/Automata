//
// Created by lactosis on 8.1.18.
//

#ifndef AUTOMATA_AUTOMATON_H
#define AUTOMATA_AUTOMATON_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Automaton {
public:

    //region GETTERS

    unsigned long getStatesSize();

    unsigned long getSigmaSize();

    /**
     * @return -1 if the letter does not exist within Sigma, its index otherwise
     */
    int getLetterIndex(T letter);

    /**
     * @return -1 if the letter does not exist within Sigma, its index otherwise
     */
    int getStateIndex(string state);

    /**
     * @return States of the automaton
     */
    vector<string> getStates();

    /**
     * @return Sigma (Letters) of the automaton
     */
    vector<T> getSigma();

    /**
     * @return string containing formatted table
     */
    virtual string getAutomatonTable() = 0;

    /**
     * @return string containing automaton table formatted in HTML
     */
    virtual string getAutomatonTableHTML() = 0;

    /**
     * @return string containing the automaton table formatted for TEX
     */
    virtual string getAutomatonTableTEX() = 0;

    /**
     * @return string containing code for TEX library TIKZ that displays this automaton
     */
    virtual string getAutomatonVisualTIKZ() = 0;

    /**
     * @return string representing state that has transition from given state by given letter
     */
    virtual string transition(const string &state, T letter) = 0;

    //endregion

    /**
     * Prints the automaton table to the console
     */
    virtual void printAutomatonTable() = 0;

    virtual bool accepts(vector<T> word) = 0;

    virtual bool isFinalState(int state) = 0;

    virtual bool isFinalState(string state) = 0;

protected:
    unsigned int numStates, numLetters;
    vector<T> sigma;
    vector<string> states;

    /**
     * @return -1 if state or letter index is invalid, state index after transition otherwise
     */
    virtual int transition(int state, int letter) = 0;

    int getMaxLength();

    int getMaxSigma();

    int getMaxStates();
};


#endif //AUTOMATA_AUTOMATON_H
