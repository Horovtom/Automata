//
// Created by lactosis on 8.1.18.
//

#include "Automaton.h"
#include "util.h"

using namespace std;

//region template definitions

template
class Automaton<string>;

template
class Automaton<int>;

template
class Automaton<char>;

template
class Automaton<double>;

template
class Automaton<long int>;

template
class Automaton<unsigned int>;

template
class Automaton<long unsigned int>;

template
class Automaton<float>;

//endregion

template<typename T>
unsigned long Automaton<T>::getStatesSize() {
    return states.size();
}

template<typename T>
unsigned long Automaton<T>::getSigmaSize() {
    return sigma.size();
}

template<typename T>
int Automaton<T>::getLetterIndex(T letter) {
    for (int i = 0; i < sigma.size(); ++i) {
        if (sigma[i] == letter) return i;
    }
    return -1;
}

template<typename T>
int Automaton<T>::getStateIndex(string state) {
    for (int i = 0; i < states.size(); ++i) {
        if (states[i] == state) return i;
    }

    return -1;
}

template<typename T>
vector<string> Automaton<T>::getStates() {
    return states;
    //return vector<string>(states);
}

template<typename T>
vector<T> Automaton<T>::getSigma() {
    return sigma;
    //return vector<T>(sigma);
}

template<typename T>
int Automaton<T>::getMaxLength() {
    return max(getMaxSigma(), getMaxStates());
}

template<typename T>
int Automaton<T>::getMaxSigma() {
    int maxLen = 1;

    for (int i = 0; i < this->sigma.size(); ++i) {
        string element = toString<T>(this->sigma[i]);
        maxLen = max(maxLen, static_cast<int>(element.length()));
    }

    return maxLen;
}

template<typename T>
int Automaton<T>::getMaxStates() {
    int maxLen = 1;

    for (int i = 0; i < this->states.size(); ++i) {
        string element = this->states[i];
        maxLen = max(maxLen, static_cast<int>(element.length()));
    }

    return maxLen;
}

template<typename T>
AutomatonType Automaton<T>::getType() {
    return this->type;
}


