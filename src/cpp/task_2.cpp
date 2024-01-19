#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Turing machine states
enum State {
    START,
    MOVE_RIGHT,
    WRITE_1,
    MOVE_LEFT,
    FIND_SEPARATOR,
    ERASE_SEPARATOR,
    END
};

// Perform unary addition using a Turing machine
string unaryAddition(const string& input) {
    string tape = "0" + input + "0";  // Add leading and trailing zeros as separators
    State currentState = START;
    int head = 1;  // Initial head position

    while (currentState != END) {
        char currentSymbol = tape[head];

        switch (currentState) {
            case START:
                currentState = MOVE_RIGHT;
                break;

            case MOVE_RIGHT:
                if (currentSymbol == '1') {
                    tape[head] = 'x';  // Mark the current '1' as visited
                    head++;
                } else if (currentSymbol == '0') {
                    currentState = WRITE_1;
                } else {
                    currentState = MOVE_RIGHT;
                    head++;
                }
                break;

            case WRITE_1:
                tape[head] = '1';  // Write '1'
                currentState = MOVE_LEFT;
                break;

            case MOVE_LEFT:
                head--;  // Move left
                currentState = FIND_SEPARATOR;
                break;

            case FIND_SEPARATOR:
                if (currentSymbol == '0') {
                    currentState = ERASE_SEPARATOR;
                } else {
                    currentState = MOVE_LEFT;
                    head--;
                }
                break;

            case ERASE_SEPARATOR:
                tape[head] = '0';  // Erase the separator '0'
                currentState = END;
                break;

            case END:
                break;
        }
    }

    // Trim leading and trailing zeros
    return tape.substr(1, tape.size() - 2);
}

int main() {
    // Sample input
    string input = "11101111";

    // Perform unary addition
    string result = unaryAddition(input);

    // Output the result
    cout << "Result: " << result << endl;

    return 0;
}
