
#ifndef AUTOMATA_DEFINITIONS_TESTS
#define AUTOMATA_DEFINITIONS_TESTS

#include <DFAAutomaton.h>

/**
 * Ex. 3.2.3. in script. Image: test/dfa_tests/1.png
 *
 * This automaton is <b>not</b> reduced and accepts this language:
 * <br><b>L = { w | w &isin; &Sigma;<sup>*</sup>, w starts and ends with the same character }, &Sigma; = {a,b}</b>
 * <hr>
 * <table><tr><th colspan="2">Q</th><th>a<br></th><th>b</th></tr><tr><td></td><td>1</td><td>2</td><td>1</td></tr><tr><td>&lt;</td><td>2</td><td>2</td><td>1</td></tr><tr><td></td><td>3</td><td>7</td><td>5</td></tr><tr><td>&lt;</td><td>4</td><td>7</td><td>4</td></tr><tr><td>&gt;</td><td>5</td><td>2</td><td>4</td></tr><tr><td>&lt;</td><td>6</td><td>6</td><td>3</td></tr><tr><td></td><td>7</td><td>7</td><td>4</td></tr></table>
 * <hr>
 * <pre>
 * +-------+---+---+ <br>
 * | Q     | a | b | <br>
 * +-------+---+---+ <br>
 * |   | 1 | 2 | 1 | <br>
 * +---+---+---+---+ <br>
 * | ← | 2 | 2 | 1 | <br>
 * +---+---+---+---+ <br>
 * |   | 3 | 7 | 5 | <br>
 * +---+---+---+---+ <br>
 * | ← | 4 | 7 | 4 | <br>
 * +---+---+---+---+ <br>
 * | → | 5 | 2 | 4 | <br>
 * +---+---+---+---+ <br>
 * | ← | 6 | 6 | 3 | <br>
 * +---+---+---+---+ <br>
 * |   | 7 | 7 | 4 | <br>
 * +---+---+---+---+
 * </pre>
 *
 * After reduction (removal of unreachable states) it looks like this:
 * <hr>
 * <table><tr><th colspan="2">Q'<br></th><th>a</th><th>b</th></tr><tr><td>→</td><td>1<br></td><td>3<br></td><td>4<br></td></tr><tr><td><br></td><td>2</td><td>3<br></td><td>2<br></td></tr><tr><td>←</td><td>3</td><td>3<br></td><td>2<br></td></tr><tr><td>←</td><td>4</td><td>5<br></td><td>4</td></tr><tr><td></td><td>5</td><td>5</td><td>4</td></tr></table>
 * <hr>
 * <pre>
 * +-------+---+---+ <br>
 * | Q'    | a | b | <br>
 * +-------+---+---+ <br>
 * | → | 1 | 3 | 4 | <br>
 * +---+---+---+---+ <br>
 * |   | 2 | 3 | 2 | <br>
 * +---+---+---+---+ <br>
 * | ← | 3 | 3 | 2 | <br>
 * +---+---+---+---+ <br>
 * | ← | 4 | 5 | 4 | <br>
 * +---+---+---+---+ <br>
 * |   | 5 | 5 | 4 | <br>
 * +---+---+---+---+
 * </pre>
 *
 */
DFAAutomaton<char> getDFA1char();

/**
 * This outputs the same automaton as getDFA1, but it has abrakadabra and berries as sigma: <br>
 * <b> &Sigma; = {abrakadabra, berries}</b>
 *<hr>
 *<table><tr><th colspan="2">Q'<br></th><th>abrakadabra</th><th>berries</th></tr><tr><td><br></td><td>1<br></td><td>2<br></td><td>1<br></td></tr><tr><td>←</td><td>2</td><td>2<br></td><td>1<br></td></tr><tr><td><br></td><td>3</td><td>7<br></td><td>5<br></td></tr><tr><td>←</td><td>4</td><td>7<br></td><td>4</td></tr><tr><td>→</td><td>5</td><td>2<br></td><td>4</td></tr><tr><td>←</td><td>6</td><td>6</td><td>3</td></tr><tr><td></td><td>7</td><td>7</td><td>4</td></tr></table>
 * <hr>
 * <pre>
 * +-------+-------------+---------+ <br>
 * | Q'    | abrakadabra | berries | <br>
 * +-------+-------------+---------+ <br>
 * |   | 1 | 2           | 1       | <br>
 * +---+---+-------------+---------+ <br>
 * | ← | 2 | 2           | 1       | <br>
 * +---+---+-------------+---------+ <br>
 * |   | 3 | 7           | 5       | <br>
 * +---+---+-------------+---------+ <br>
 * | ← | 4 | 7           | 4       | <br>
 * +---+---+-------------+---------+ <br>
 * | → | 5 | 2           | 4       | <br>
 * +---+---+-------------+---------+ <br>
 * | ← | 6 | 6           | 3       | <br>
 * +---+---+-------------+---------+ <br>
 * |   | 7 | 7           | 4       | <br>
 * +---+---+-------------+---------+
 * </pre>
 */
DFAAutomaton<string> getDFA1string();

/**
 * This outputs the same automaton as getDFA1, but it has integers 0 and 1 as sigma. Also it's state names are different: <br>
 * <b>&Sigma; = {0, 1} </b>
 * <hr>
 *<table><tr><th colspan="2">Q'<br></th><th>0</th><th>1<br></th></tr><tr><td><br></td><td>dodge<br></td><td>crit</td><td>dodge<br></td></tr><tr><td>←</td><td>crit<br></td><td>crit<br></td><td>dodge<br></td></tr><tr><td><br></td><td>miss<br></td><td>evade<br></td><td>parry<br></td></tr><tr><td>←</td><td>block<br></td><td>evade<br></td><td>block<br></td></tr><tr><td>→</td><td>parry<br></td><td>crit<br></td><td>block<br></td></tr><tr><td>←</td><td>resist<br></td><td>resist<br></td><td>miss<br></td></tr><tr><td></td><td>evade<br></td><td>evade<br></td><td>block<br></td></tr></table>
 * <hr>
 * <pre>
 * +------------+--------+-------+ <br>
 * | Q'         | 0      | 1     | <br>
 * +------------+--------+-------+ <br>
 * |   | dodge  | crit   | dodge | <br>
 * +---+--------+--------+-------+ <br>
 * | ← | crit   | crit   | dodge | <br>
 * +---+--------+--------+-------+ <br>
 * |   | miss   | evade  | parry | <br>
 * +---+--------+--------+-------+ <br>
 * | ← | block  | evade  | block | <br>
 * +---+--------+--------+-------+ <br>
 * | → | parry  | crit   | block | <br>
 * +---+--------+--------+-------+ <br>
 * | ← | resist | resist | miss  | <br>
 * +---+--------+--------+-------+ <br>
 * |   | evade  | evade  | block | <br>
 * +---+--------+--------+-------+
 * </pre>
 */
DFAAutomaton<int> getDFA1int();

/**
 * Image test/dfa_tests/2.png
 *
 * This automaton is <b>reduced</b> and it accepts this language: <br>
 * <b> &Sigma; = {l,o,i,p}, L = {w | w &isin;&Sigma;<sup>*</sup>, w contains "lolipop" as a substring}</b>
 *
 * <hr>
 * <table><tr><th colspan="2">Q<br></th><th>l</th><th>o<br></th><th>i</th><th>p</th></tr><tr><td>&rarr;</td><td>0</td><td>1</td><td>0<br></td><td>0</td><td>0</td></tr><tr><td></td><td>1</td><td>0</td><td>2</td><td>0</td><td>0</td></tr><tr><td><br></td><td>2</td><td>3</td><td>0</td><td>0</td><td>0</td></tr><tr><td></td><td>3</td><td>0</td><td>0</td><td>4</td><td>0</td></tr><tr><td></td><td>4</td><td>0</td><td>0</td><td>0</td><td>5</td></tr><tr><td><br></td><td>5</td><td>0</td><td>6</td><td>0</td><td>0</td></tr><tr><td></td><td>6</td><td>0</td><td>0</td><td>0</td><td>7</td></tr><tr><td>&larr;<br></td><td>7</td><td>7</td><td>7</td><td>7</td><td>7</td></tr></table>
 * <hr>
 * <pre>
 * +-------+---+---+---+---+ <br>
 * | Q     | l | o | i | p | <br>
 * +-------+---+---+---+---+ <br>
 * | → | 0 | 1 | 0 | 0 | 0 | <br>
 * +---+---+---+---+---+---+ <br>
 * |   | 1 | 0 | 2 | 0 | 0 | <br>
 * +---+---+---+---+---+---+ <br>
 * |   | 2 | 3 | 0 | 0 | 0 | <br>
 * +---+---+---+---+---+---+ <br>
 * |   | 3 | 0 | 0 | 4 | 0 | <br>
 * +---+---+---+---+---+---+ <br>
 * |   | 4 | 0 | 0 | 0 | 5 | <br>
 * +---+---+---+---+---+---+ <br>
 * |   | 5 | 0 | 6 | 0 | 0 | <br>
 * +---+---+---+---+---+---+ <br>
 * |   | 6 | 0 | 0 | 0 | 7 | <br>
 * +---+---+---+---+---+---+ <br>
 * | ← | 7 | 7 | 7 | 7 | 7 | <br>
 * +---+---+---+---+---+---+
 * </pre>
 */
DFAAutomaton<char> getDFA2char();

/**
 * This outputs the same table as getDFA2, but has doubles as sigma: <br>
 * <b>&Sigma; = {0.12, -6.38, 0, 213.002}</b>
 * <hr>
 * <table><tr><th colspan="2">Q<br></th><th>0.12</th><th>-6.38<br></th><th>0</th><th>213.002</th></tr><tr><td>→</td><td>0</td><td>1</td><td>0<br></td><td>0</td><td>0</td></tr><tr><td></td><td>1</td><td>0</td><td>2</td><td>0</td><td>0</td></tr><tr><td><br></td><td>2</td><td>3</td><td>0</td><td>0</td><td>0</td></tr><tr><td></td><td>3</td><td>0</td><td>0</td><td>4</td><td>0</td></tr><tr><td></td><td>4</td><td>0</td><td>0</td><td>0</td><td>5</td></tr><tr><td><br></td><td>5</td><td>0</td><td>6</td><td>0</td><td>0</td></tr><tr><td></td><td>6</td><td>0</td><td>0</td><td>0</td><td>7</td></tr><tr><td>←</td><td>7</td><td>7</td><td>7</td><td>7</td><td>7</td></tr></table>
 * <hr>
 * <pre>
 * +-------+------+-------+---+-----------------+ <br>
 * | Q     | 0.12 | -6.38 | 0 | 213.002         | <br>
 * +-------+------+-------+---+-----------------+ <br>
 * | → | 0 | 1    | 0     | 0 | 0               | <br>
 * +---+---+------+-------+---+-----------------+ <br>
 * |   | 1 | 0    | 2     | 0 | 0               | <br>
 * +---+---+------+-------+---+-----------------+ <br>
 * |   | 2 | 3    | 0     | 0 | 0               | <br>
 * +---+---+------+-------+---+-----------------+ <br>
 * |   | 3 | 0    | 0     | 4 | 0               | <br>
 * +---+---+------+-------+---+-----------------+ <br>
 * |   | 4 | 0    | 0     | 0 | 5               | <br>
 * +---+---+------+-------+---+-----------------+ <br>
 * |   | 5 | 0    | 6     | 0 | 0               | <br>
 * +---+---+------+-------+---+-----------------+ <br>
 * |   | 6 | 0    | 0     | 0 | 7               | <br>
 * +---+---+------+-------+---+-----------------+ <br>
 * | ← | 7 | 7    | 7     | 7 | 7               | <br>
 * +---+---+------+-------+---+-----------------+
 * </pre>
 *
 *
 */
DFAAutomaton<double> getDFA2double();

#endif //AUTOMATA_DEFINITIONS_TESTS