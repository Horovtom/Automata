
#ifndef AUTOMATA_DEFINITIONS_TESTS
#define AUTOMATA_DEFINITIONS_TESTS

#include <DFAAutomaton.h>

/**
 * Ex. 3.2.3. in script. Image: test/dfa_tests/1.png
 *
 * This automaton is <b>not</b> reduced and accepts this language:
 * <br><b>L = { w | w starts and ends with the same character }</b>
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
 * +---+---+---+---+ <br>
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
 * +---+---+---+---+ <br>
 * </pre>
 *
 */
DFAAutomaton<char> getDFA1();

#endif //AUTOMATA_DEFINITIONS_TESTS