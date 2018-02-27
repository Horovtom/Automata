#include <DFAAutomaton.h>
#include <fstream>
#include "gtest/gtest.h"
#include "util.h"
#include "automata_definitions.h"

TEST(to_tikz_code_char, test_dfa) { // NOLINT
    DFAAutomaton<char> dfa = getDFA1char();

    vector<string> expected = {
            "\\begin{tikzpicture}[->,>=stealth',shorten", ">=1pt,auto,node", "distance=2.8cm,semithick]",
            "\\node[state]", "(0)", "{$1$};",
            "\\node[state,accepting]", "(1)", "[right", "of=0]", "{$2$};",
            "\\node[state]", "(2)", "[right", "of=1]", "{$3$};",
            "\\node[state,accepting]", "(3)", "[right", "of=2]", "{$4$};",
            "\\node[initial,state]", "(4)", "[right", "of=3]", "{$5$};",
            "\\node[state,accepting]", "(5)", "[right", "of=4]", "{$6$};",
            "\\node[state]", "(6)", "[right", "of=5]", "{$7$};",
            "\\path",
            "(0)",
            "edge", "[bend", "left]", "node", "{$a$}", "(1)",
            "edge", "[loop", "above]", "node", "{$b$}", "(0)",
            "(1)",
            "edge", "[loop", "above]", "node", "{$a$}", "(1)",
            "edge", "[bend", "left]", "node", "{$b$}", "(0)",
            "(2)",
            "edge", "", "node", "{$a$}", "(6)",
            "edge", "", "node", "{$b$}", "(4)",
            "(3)",
            "edge", "[bend", "left]", "node", "{$a$}", "(6)",
            "edge", "[loop", "above]", "node", "{$b$}", "(3)",
            "(4)",
            "edge", "", "node", "{$a$}", "(1)",
            "edge", "", "node", "{$b$}", "(3)",
            "(5)",
            "edge", "[loop", "above]", "node", "{$a$}", "(5)",
            "edge", "", "node", "{$b$}", "(2)",
            "(6)",
            "edge", "[loop", "above]", "node", "{$a$}", "(6)",
            "edge", "[bend", "left]", "node", "{$b$}", "(3);",
            "\\end{tikzpicture}"
    };

    std::vector<string> wordVector;
    std::stringstream stringStream(dfa.getAutomatonTIKZ());
    std::string line;
    while (std::getline(stringStream, line)) {
        std::size_t prev = 0, pos;
        while ((pos = line.find_first_of(" \t\n", prev)) != std::string::npos) {
            if (pos > prev)
                wordVector.push_back(line.substr(prev, pos - prev));
            prev = pos + 1;
        }
        if (prev < line.length())
            wordVector.push_back(line.substr(prev, std::string::npos));
    }

    ASSERT_EQ(wordVector.size(), expected.size());

    for (int i = 0; i < expected.size(); ++i) {
        ASSERT_EQ(wordVector[i], expected[i]);
    }
}

TEST(to_tikz_code_string, test_dfa) { // NOLINT
    DFAAutomaton<string> dfa = getDFA3string();

    vector<string> expected = {
            "\\begin{tikzpicture}[->,>=stealth',shorten", ">=1pt,auto,node", "distance=2.8cm,semithick]",
            "\\node[initial,state,accepting]", "(0)", "{$0$};",
            "\\node[state]", "(1)", "[right of=0]", "{$1$};",
            "\\path",
            "(0)",
            "edge", "[loop", "above]", "node", "{$\\alpha$}", "(0)",
            "edge", "node", "{$\\beta$}", "(1)",
            "(1)",
            "edge", "[loop", "above]", "node", "{$\\alpha,\\beta$}", "(1);",
            "\\end{tikzpicture}"
    };

    std::vector<string> wordVector;
    std::stringstream stringStream(dfa.getAutomatonTIKZ());
    std::string line;
    while (std::getline(stringStream, line)) {
        std::size_t prev = 0, pos;
        while ((pos = line.find_first_of(" \t\n", prev)) != std::string::npos) {
            if (pos > prev)
                wordVector.push_back(line.substr(prev, pos - prev));
            prev = pos + 1;
        }
        if (prev < line.length())
            wordVector.push_back(line.substr(prev, std::string::npos));
    }

    ASSERT_EQ(wordVector.size(), expected.size());

    for (int i = 0; i < expected.size(); ++i) {
        ASSERT_EQ(wordVector[i], expected[i]);
    }
}

