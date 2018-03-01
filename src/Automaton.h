//
// Created by lactosis on 8.1.18.
//

#ifndef AUTOMATA_AUTOMATON_H
#define AUTOMATA_AUTOMATON_H

#include <iostream>
#include <vector>

using namespace std;

enum class AutomatonType : char {
    DFA, NFA, ENFA
};

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
    virtual string getAutomatonTIKZ() = 0;

    /**
     * @return string representing state that is the result of transition from given state by given letter
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

    AutomatonType getType();

protected:
    unsigned int numStates, numLetters;
    vector<T> sigma;
    vector<string> states;
    AutomatonType type;

    /**
     * @return -1 if state or letter index is invalid, state index after transition otherwise
     */
    virtual int transition(int state, int letter) = 0;

    int getMaxLength();

    int getMaxSigma();

    int getMaxStates();

    /**
     * This finds all the indices of elements of sigma that label the edge from A to B
     * @param from Index of the state A
     * @param to Index of the state B
     * @return Vector of indices of sigma that label edge from A to B
     */
    virtual vector<int> getLettersFromTo(int from, int to) = 0;

    /**
     * Returns true if there is some letter in sigma such that we can get from A to B using this letter.
     * @param from Index of the state A
     * @param to Index of the state B
     * @return Whether there is an edge from A to B
     */
    virtual bool hasEdgeFromTo(int from, int to) = 0;
};

#endif //AUTOMATA_AUTOMATON_H
