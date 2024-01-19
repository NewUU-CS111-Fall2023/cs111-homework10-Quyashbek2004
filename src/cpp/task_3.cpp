#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Turing machine states
enum State {
    START,
    MOVE_RIGHT_FIRST,
    MOVE_RIGHT_SECOND,
    COMPARE,
    OUTPUT_GREATER,
    OUTPUT_EQUAL,
    OUTPUT_SECOND_GREATER,
    END
};

// Perform comparison of two numbers using a Turing machine
string compareNumbers(const string& input) {
    string tape = input;
    State currentState = START;
    int head = 0;  // Initial head position

    while (currentState != END) {
        char currentSymbol = tape[head];

        switch (currentState) {
            case START:
                currentState = MOVE_RIGHT_FIRST;
                break;

            case MOVE_RIGHT_FIRST:
                head++;
                currentState = MOVE_RIGHT_SECOND;
                break;

            case MOVE_RIGHT_SECOND:
                head++;
                currentState = COMPARE;
                break;

            case COMPARE:
                if (currentSymbol == 'c') {
                    currentState = OUTPUT_EQUAL;
                } else if (currentSymbol == '1') {
                    currentState = OUTPUT_SECOND_GREATER;
                } else {
                    currentState = OUTPUT_GREATER;
                }
                break;

            case OUTPUT_GREATER:
                tape = "1";  // Output "1" for the first number being greater
                currentState = END;
                break;

            case OUTPUT_EQUAL:
                tape = "1 1";  // Output "1 1" for equal numbers
                currentState = END;
                break;

            case OUTPUT_SECOND_GREATER:
                tape = "";  // Output nothing for the second number being greater
                currentState = END;
                break;

            case END:
                break;
        }
    }

    return tape;
}

int main() {
    // Sample input
    string input = "0111c11110";

    // Perform comparison
    string result = compareNumbers(input);

    // Output the result
    cout << "Result: " <<
