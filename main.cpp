#include <iostream>
#include <vector>
#include <DFAAutomaton.h>

void displayMenu();

void displayMenuLoaded();

void userCreateAutomaton();

void userCreateDFA();

void userCreateNFA();

void userCreateENFA();

void loadPredefinedAutomaton();

void isWordInL();

void getInString();

void reduceIt();

using namespace std;

Automaton<char> *current = nullptr;

DFAAutomaton<char> *dfa = nullptr;


int main() {
    displayMenu();
}

void displayMenu() {
    if (current != nullptr) {
        displayMenuLoaded();
        return;
    } else {

        cout << "Main menu:" << endl;
        cout << "No automaton loaded!" << endl;
        cout << "Select one option from the following:" << endl;
        cout << "1: Enter a new automaton" << endl;
        cout << "2: Use pre-defined automaton" << endl;
        cout << "3: Exit" << endl;

        cout << "Your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                userCreateAutomaton();
                break;
            case 2:
                loadPredefinedAutomaton();
                break;
            case 3:
                return;
            default:
                cerr << "Your choice was invalid!" << endl;
                displayMenu();
                return;
        }
    }
}

void loadPredefinedAutomaton() {
    //TODO: IMPLEMENT
    cerr << "Not implemented yet!" << endl;
    displayMenu();
}

void userCreateAutomaton() {
    cout << "Which type of automaton do you want to create?" << endl;
    cout << "1: DFA" << endl;
    cout << "2: NFA" << endl;
    cout << "3: e-NFA" << endl;
    cout << "4: Back" << endl;
    cout << "Your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            userCreateDFA();
            break;
        case 2:
            userCreateNFA();
            break;
        case 3:
            userCreateENFA();
            break;
        case 4:
            break;
        default:
            cerr << "Your choice was invalid!" << endl;
            userCreateAutomaton();
            return;
    }

    displayMenu();
}

void userCreateENFA() {
    //TODO: IMPLEMENT
    cerr << "Not implemented yet!" << endl;
    userCreateAutomaton();
}

void userCreateNFA() {
    //TODO: IMPLEMENT
    cerr << "Not implemented yet!" << endl;
    userCreateAutomaton();
}

void userCreateDFA() {
    dfa = new DFAAutomaton<char>();
    current = dfa;

}

void displayMenuLoaded() {
    cout << "Automaton loaded: " << endl;
    current->printAutomatonTable();
    cout << "What do you want to do:" << endl;
    cout << "1: Check if a word is in L" << endl;
    cout << "2: Get automaton in string" << endl;
    cout << "3: Reduce" << endl;
    cout << "4: Delete this automaton" << endl;
    cout << "Your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            isWordInL();
            break;
        case 2:
            getInString();
            break;
        case 3:
            reduceIt();
            break;
        case 4:
            cout << "Are you sure? (Y/N): ";
            char res;
            cin >> res;
            if (res == 'Y' || res == 'y') {
                current = nullptr;
                dfa = nullptr;
                displayMenu();
                return;
            }
            break;
        default:
            cerr << "Your choice was invalid!" << endl;
            displayMenuLoaded();
            return;
    }


}

void reduceIt() {
    //TODO: IMPLEMENT
    cerr << "Not implemented yet!" << endl;
    displayMenu();
}

void getInString() {
    cout << "In which format do you want to get the automaton?" << endl;
    cout << "1: Plain text" << endl;
    cout << "2: HTML" << endl;
    cout << "3: TEX" << endl;
    cout << "4: TIKZ" << endl;
    cout << "5: Back" << endl;
    cout << "Your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << current->getAutomatonTable() << endl;
            break;
        case 2:
            cout << current->getAutomatonTableHTML() << endl;
            break;
        case 3:
            cout << current->getAutomatonTableTEX() << endl;
            break;
        case 4:
            cout << current->getAutomatonTIKZ() << endl;
            break;
        case 5:
            break;
        default:
            cerr << "Your choice was invalid!" << endl;
            getInString();
            return;
    }

    displayMenu();

}

void isWordInL() {
    cout << "Input a word to check, (two blank lines for Back): ";
    string input;
    bool blank = false;
    cin.get();
    while (true) {
        getline(cin, input);
        if (input.empty()) {
            if (blank) break;
            blank = true;
        } else {
            blank = false;
        }
        vector<char> data(input.begin(), input.end());

        cout << (current->accepts(data) ? "Accepts" : "Does not accept") << endl;
    }
    displayMenu();
}