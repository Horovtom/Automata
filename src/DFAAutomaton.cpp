//
// Created by lactosis on 8.1.18.
//

#include <algorithm>
#include <iostream>
#include "DFAAutomaton.h"
#include "util.h"

//region template definitions

template
class DFAAutomaton<string>;

template
class DFAAutomaton<int>;

template
class DFAAutomaton<char>;

template
class DFAAutomaton<double>;

template
class DFAAutomaton<long int>;

template
class DFAAutomaton<unsigned int>;

template
class DFAAutomaton<long unsigned int>;

template
class DFAAutomaton<float>;

//endregion


template<typename T>
string DFAAutomaton<T>::getAutomatonTable() {
    /*
     * Format: < length length ...
     */
    //TODO: ADD SUPPORT FOR CACHING OF THE RESULT

    auto length = this->getMaxLength() + 1;
    auto lengthStates = this->getMaxStates() + 1;

    //Two initial spaces for <> column
    string result = "  ";
    //State column
    padTo(result, lengthStates, "");

    //Transitions columns
    for (int i = 0; i < this->sigma.size(); ++i) {
        padTo(result, length, toString<T>(this->sigma[i]));
    }

    result.append("\n");

    //States
    for (int j = 0; j < this->states.size(); ++j) {
        if (std::find(this->finalStates.begin(), this->finalStates.end(), j) != this->finalStates.end()) {
            result.append("<");
        } else result.append(" ");
        if (this->initialState == j) {
            result.append(">");
        } else result.append(" ");

        //State column
        padTo(result, lengthStates, this->states[j]);

        //Transitions columns
        for (int i = 0; i < this->sigma.size(); ++i) {
            padTo(result, length, this->states[this->transitions[j][i]]);
        }
        result.append("\n");
    }

    return result;
}

template<typename T>
string DFAAutomaton<T>::getAutomatonTableHTML() {
    //TODO: ADD SUPPORT FOR CACHING OF THE RESULT

    string result = "<table>\n<tr><td></td><td></td>";

    //Sigma:
    for (int i = 0; i < this->sigma.size(); ++i) {
        result.append("<td>").append(toString<T>(this->sigma[i])).append("</td>");
    }
    result.append("</tr>\n");

    //Transitions
    for (int j = 0; j < this->states.size(); ++j) {
        result.append("<tr><td>");
        if (std::find(this->finalStates.begin(), this->finalStates.end(), j) != this->finalStates.end()) {
            if (j == this->initialState) {
                result.append("&harr;");
            } else {
                result.append("&larr;");
            }
        } else if (j == this->initialState) {
            result.append("&rarr;");
        }

        //State name
        result.append("</td><td>").append(this->states[j]).append("</td>");

        //Sigma:
        for (int i = 0; i < this->sigma.size(); ++i) {
            result.append("<td>").append(this->states[this->transitions[j][i]]).append("</td>");
        }
        result.append("</tr>\n");
    }

    result.append("</table>");

    return result;
}

template<typename T>
string DFAAutomaton<T>::getAutomatonTableTEX() {
    //TODO: ADD CACHING OF RESULT
    string result = "\\begin{figure}[H]\n\t\\centering\n\t\\begin{tabular}{cc|";
    //Definition of table
    for (int i = 0; i < this->sigma.size(); ++i) {
        result.append("|c");
    }
    result.append("}\n\t\t");

    //Header line
    result.append("\t\t\t\t &");
    for (int k = 0; k < this->sigma.size(); ++k) {
        result.append("\t& ").append(toString<T>(this->sigma[k]));
    }

    result.append(" \\\\\\hline\n\t\t");

    //State lines
    for (int j = 0; j < this->states.size(); ++j) {
        if (this->initialState == j) {
            if (std::find(this->finalStates.begin(), this->finalStates.end(), j) != this->finalStates.end()) {
                result.append("$\\leftrightarrow$\t");
            } else {
                result.append("$\\rightarrow$\t");
            }
        } else if (std::find(this->finalStates.begin(), this->finalStates.end(), j) != this->finalStates.end()) {
            result.append("$\\leftarrow$\t");
        } else {
            result.append("\t\t\t\t");
        }
        result.append(" & ");
        //StateName
        result.append(this->states[j]);
        //Transitions
        for (int i = 0; i < this->sigma.size(); ++i) {

            result.append("\t& ").append(this->states[this->transitions[j][i]]);
        }
        if (j != this->states.size() - 1)
            result.append(" \\\\\n\t\t");
        else
            result.append("\n\t");
    }

    result.append("\\end{tabular}\n\\end{figure}\n");

    return result;
}

template<typename T>
string DFAAutomaton<T>::getAutomatonTIKZ() {
    //TODO: IMPLEMENT
    return nullptr;
}

template<typename T>
void DFAAutomaton<T>::printAutomatonTable() {
    cout << getAutomatonTable() << endl;
}

template<typename T>
void DFAAutomaton<T>::interactiveGetStatesSigma(istream &ss) {
    int i = INTERACTIVE_MAXINPUTS;
    while (i--) {
        cout << "Number of states: ";
        ss >> this->numStates;
        if (this->numStates > 0) break;
        if (i == 0) {
            cerr << "Exceeded maximum number of invalid inputs!" << endl;
            exit(-2);
        }
        cerr << "Number of states must be positive!" << endl;
    }
    cout << "Enter " << this->numStates << " state names, separated by ' '" << endl;
    string loadedStateName;
    for (int j = 0; j < this->numStates; ++j) {
        ss >> loadedStateName;
        this->states.emplace_back(loadedStateName);
    }

    T loadedLetterName;
    i = INTERACTIVE_MAXINPUTS;
    while (i--) {
        cout << "Number of letters: ";
        ss >> this->numLetters;
        if (this->numLetters > 0) break;
        if (i == 0) {
            cerr << "Exceeded maximum number of invalid inputs!" << endl;
            exit(-2);
        }
        cerr << "Number of states must be positive!" << endl;
    }

    cout << "Enter " << this->numLetters << " letter names, separated by ' '" << endl;
    for (int j = 0; j < this->numLetters; ++j) {
        ss >> loadedLetterName;
        this->sigma.push_back(loadedLetterName);
    }
}

template<typename T>
void DFAAutomaton<T>::interactiveGetStatesTable(istream &ss) {
    cout << "Now enter the states table for this automaton. Each pointer will be separated by ' '" << endl <<
         "First element of each row should be <, >, <> or -, meaning accepting state, initial state, both or either one respectively"
         << endl;

    //Print the header
    cout << "state_name I/A ";
    for (int j = 0; j < this->numLetters; ++j) {
        cout << this->sigma[j] << " ";
    }
    cout << endl;


    for (unsigned int i = 0; i < this->numStates; ++i) {
        interactiveGetStateRow(ss, i);
    }

}

template<typename T>
void DFAAutomaton<T>::interactiveGetStateRow(istream &ss, unsigned int i) {
    cout << this->states[i] << " ";
    string s;
    vector<int> stateLine;
    ss >> s;

    if (s == "<") {
        finalStates.emplace_back(i);
    } else if (s == ">") {
        if (initialState != -1) {
            cerr << "Initial state already specified for this automaton! Ignoring this one!" << endl;
        } else {
            initialState = i;
        }
    } else if (s == "<>") {
        if (initialState != -1) {
            cerr << "Initial state already specified for this automaton! Ignoring this one!" << endl;
        } else {
            initialState = i;
        }
        finalStates.emplace_back(i);
    } else if (s != "-") {
        cerr << endl << "Specify the I/A of this state!" << endl;
        string flushing;
        getline(ss, flushing);
        return this->interactiveGetStateRow(ss, i);
    }

    for (int j = 0; j < this->numLetters; ++j) {
        ss >> s;
        int index = this->getStateIndex(s);
        if (index == -1) return this->interactiveGetStateRow(ss, i);
        stateLine.push_back(index);
    }

    transitions.emplace_back(stateLine);
}

template<typename T>
string DFAAutomaton<T>::transition(const string &state, T letter) {
    int stateIndex = this->getStateIndex(state);
    int letterIndex = this->getLetterIndex(letter);
    if (stateIndex == -1 || letterIndex == -1) {
        return nullptr;
    }
    return this->states[transitions[stateIndex][letterIndex]];
}

template<typename T>
int DFAAutomaton<T>::transition(int state, int letter) {
    if (state < 0 || state >= this->numStates) {
        cerr << "Invalid state index: " << state << endl;
        return -1;
    }
    if (letter < 0 || letter >= this->numLetters) {
        cerr << "Invalid letter index: " << letter << endl;
        return -1;
    }
    return transitions[state][letter];
}

template<typename T>
DFAAutomaton<T>::DFAAutomaton(istream &ss) {
    cout << "Interactive mode" << endl << "Now you will be asked to enter specifics for this automaton" << endl;
    interactiveGetStatesSigma(ss);
    interactiveGetStatesTable(ss);
    this->type = AutomatonType::DFA;
}

template<typename T>
string DFAAutomaton<T>::getInitialState() {
    return this->states[initialState];
}

template<typename T>
vector<string> DFAAutomaton<T>::getAcceptingStates() {
    vector<string> finals;
    for (int i = 0; i < this->finalStates.size(); ++i) {
        finals.emplace_back(this->states[finalStates[i]]);
    }
    return finals;
}


template<typename T>
bool DFAAutomaton<T>::accepts(vector<T> word) {
    int current = initialState;
    for (int i = 0; i < word.size(); ++i) {
        int letterIndex = this->getLetterIndex(word[i]);
        if (letterIndex == -1) return false;
        current = transition(current, letterIndex);
    }

    return isFinalState(current);
}

template<typename T>
bool DFAAutomaton<T>::isFinalState(int state) {
    return std::find(this->finalStates.begin(), this->finalStates.end(), state) != this->finalStates.end();
}

template<typename T>
bool DFAAutomaton<T>::isFinalState(string state) {
    int stateIndex = this->getStateIndex(state);
    return this->isFinalState(stateIndex);
}

template<typename T>
DFAAutomaton<T>::DFAAutomaton(vector<string> states, vector<T> letters, map<string, map<T, string>> transitions,
                              string starting, vector<string> finishing) {

    initializeVariables(states, letters, transitions, starting, finishing);
    this->type = AutomatonType::DFA;
}


template<typename T>
DFAAutomaton<T>::DFAAutomaton(map<string, map<T, string>> transitions, string starting, vector<string> final) {
    //Get all keys of the map to get to state names

    vector<string> states;
    map<T, string> that;
    string s;
    for (auto &transition : transitions) {
        s = transition.first;
        that = transition.second;
        states.emplace_back(s);
    }

    vector<T> letters;
    T in;

    for (auto &transition : that) {
        in = transition.first;
        letters.emplace_back(in);
    }

    initializeVariables(states, letters, transitions, starting, final);
    this->type = AutomatonType::DFA;
}

template<typename T>
void
DFAAutomaton<T>::initializeVariables(vector<string> states, vector<T> letters, map<string, map<T, string>> transitions,
                                     string starting, vector<string> finishing) {
    this->states = states;
    this->numStates = static_cast<unsigned int>(states.size());
    this->sigma = letters;
    this->numLetters = static_cast<unsigned int>(letters.size());
    this->initialState = this->getStateIndex(starting);
    for (auto &i : finishing) {
        this->finalStates.emplace_back(this->getStateIndex(i));
    }

    for (int j = 0; j < this->states.size(); ++j) {
        vector<int> transitionsRow;
        for (int i = 0; i < this->sigma.size(); ++i) {
            transitionsRow.emplace_back(this->getStateIndex(transitions[this->states[j]][this->sigma[i]]));
        }
        this->transitions.emplace_back(transitionsRow);
    }
}

template<typename T>
void DFAAutomaton<T>::reduce() {
    //TODO: IMPLEMENT
}

