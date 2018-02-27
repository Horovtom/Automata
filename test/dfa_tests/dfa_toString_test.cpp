#include <DFAAutomaton.h>
#include <fstream>
#include "gtest/gtest.h"
#include "util.h"
#include "automata_definitions.h"

TEST(to_string_test_char, test_dfa) {
    DFAAutomaton<char> dfa = getDFA1char();

    std::string s = dfa.getAutomatonTable();
    ASSERT_EQ(s,
              "    a b \n"
                      "  1 2 1 \n"
                      "< 2 2 1 \n"
                      "  3 7 5 \n"
                      "< 4 7 4 \n"
                      " >5 2 4 \n"
                      "< 6 6 3 \n"
                      "  7 7 4 \n");
}

TEST(to_string_test_int, test_dfa) {
    DFAAutomaton<int> dfa = getDFA1int();

    std::string s = dfa.getAutomatonTable();
    ASSERT_EQ(s, "         0      1      \n"
            "  dodge  crit   dodge  \n"
            "< crit   crit   dodge  \n"
            "  miss   evade  parry  \n"
            "< block  evade  block  \n"
            " >parry  crit   block  \n"
            "< resist resist miss   \n"
            "  evade  evade  block  \n");
}

TEST(to_string_test_string, test_dfa) {
    DFAAutomaton<string> dfa = getDFA1string();

    std::string s = dfa.getAutomatonTable();
    ASSERT_EQ(s, "    abrakadabra berries     \n"
            "  1 2           1           \n"
            "< 2 2           1           \n"
            "  3 7           5           \n"
            "< 4 7           4           \n"
            " >5 2           4           \n"
            "< 6 6           3           \n"
            "  7 7           4           \n");


}

TEST(to_HTML_test_string, test_dfa) {
    DFAAutomaton<string> dfa = getDFA1string();

    std::string s = dfa.getAutomatonTableHTML();

    ASSERT_EQ(s, "<table>\n"
            "<tr><td></td><td></td><td>abrakadabra</td><td>berries</td></tr>\n"
            "<tr><td></td><td>1</td><td>2</td><td>1</td></tr>\n"
            "<tr><td>&#8592;</td><td>2</td><td>2</td><td>1</td></tr>\n"
            "<tr><td></td><td>3</td><td>7</td><td>5</td></tr>\n"
            "<tr><td>&#8592;</td><td>4</td><td>7</td><td>4</td></tr>\n"
            "<tr><td>&#8594;</td><td>5</td><td>2</td><td>4</td></tr>\n"
            "<tr><td>&#8592;</td><td>6</td><td>6</td><td>3</td></tr>\n"
            "<tr><td></td><td>7</td><td>7</td><td>4</td></tr>\n"
            "</table>");

}

TEST(to_HTML_test_int, test_dfa) {
    DFAAutomaton<int> dfa = getDFA1int();

    std::string s = dfa.getAutomatonTableHTML();

    ASSERT_EQ(s, "<table>\n"
            "<tr><td></td><td></td><td>0</td><td>1</td></tr>\n"
            "<tr><td></td><td>dodge</td><td>crit</td><td>dodge</td></tr>\n"
            "<tr><td>&#8592;</td><td>crit</td><td>crit</td><td>dodge</td></tr>\n"
            "<tr><td></td><td>miss</td><td>evade</td><td>parry</td></tr>\n"
            "<tr><td>&#8592;</td><td>block</td><td>evade</td><td>block</td></tr>\n"
            "<tr><td>&#8594;</td><td>parry</td><td>crit</td><td>block</td></tr>\n"
            "<tr><td>&#8592;</td><td>resist</td><td>resist</td><td>miss</td></tr>\n"
            "<tr><td></td><td>evade</td><td>evade</td><td>block</td></tr>\n"
            "</table>");
}


TEST(to_TEX_test_int, test_dfa) {
    DFAAutomaton<int> dfa = getDFA1int();

    std::string s = dfa.getAutomatonTableTEX();

    vector<string> rightAnswer = {
            "\\begin{figure}[H]",
            "\\centering",
            "\\begin{tabular}{cc||c|c}",
            "&", "&", "0", "&", "1", R"(\\\hline)",
            "&", "dodge", "&", "crit", "&", "dodge", "\\\\",
            "$\\rightarrow$", "&", "crit", "&", "crit", "&", "dodge", "\\\\",
            "&", "miss", "&", "evade", "&", "parry", "\\\\",
            "$\\rightarrow$", "&", "block", "&", "evade", "&", "block", "\\\\",
            "$\\leftarrow$", "&", "parry", "&", "crit", "&", "block", "\\\\",
            "$\\rightarrow$", "&", "resist", "&", "resist", "&", "miss", "\\\\",
            "&", "evade", "&", "evade", "&", "block",
            "\\end{tabular}",
            "\\end{figure}"
    };


    std::vector<string> wordVector;
    std::stringstream stringStream(s);
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

    ASSERT_EQ(wordVector.size(), rightAnswer.size());

    for (int i = 0; i < rightAnswer.size(); ++i) {
        ASSERT_EQ(wordVector[i], rightAnswer[i]);
    }
}

TEST(to_TEX_test_string, test_dfa) {
    DFAAutomaton<string> dfa = getDFA1string();
    std::string s = dfa.getAutomatonTableTEX();

    vector<string> rightAnswer = {
            "\\begin{figure}[H]",
            "\\centering",
            "\\begin{tabular}{cc||c|c}",
            "&", "&", "abrakadabra", "&", "berries", R"(\\\hline)",
            "&", "1", "&", "2", "&", "1", "\\\\",
            "$\\rightarrow$", "&", "2", "&", "2", "&", "1", "\\\\",
            "&", "3", "&", "7", "&", "5", "\\\\",
            "$\\rightarrow$", "&", "4", "&", "7", "&", "4", "\\\\",
            "$\\leftarrow$", "&", "5", "&", "2", "&", "4", "\\\\",
            "$\\rightarrow$", "&", "6", "&", "6", "&", "3", "\\\\",
            "&", "7", "&", "7", "&", "4",
            "\\end{tabular}",
            "\\end{figure}"
    };

    std::vector<string> wordVector;
    std::stringstream stringStream(s);
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

    ASSERT_EQ(wordVector.size(), rightAnswer.size());

    for (int i = 0; i < rightAnswer.size(); ++i) {
        ASSERT_EQ(wordVector[i], rightAnswer[i]);
    }
}