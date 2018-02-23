#include <iostream>
#include <vector>
#include <DFAAutomaton.h>

using namespace std;

int main() {
    DFAAutomaton<char> dfa;
    string str;
    while (true) {
        cout << "Enter string to evaluate: ";
        cin >> str;

        vector<char> data(str.begin(), str.end());
        if (dfa.accepts(data)) {
            cout << "Accepts" << endl;
        } else {
            cout << "Does not accept" << endl;
        }

    }
}