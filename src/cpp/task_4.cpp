#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Turing machine states
enum State {
    START,
    MOVE_RIGHT_TO_SEPARATOR,
    CONVERT_TO_SEPARATOR,
    MOVE_LEFT_FROM_SEPARATOR,
    CONVERT_TO_X,
    MOVE_RIGHT_TO_ZERO,
    CONVERT_TO_Y,
    MOVE_LEFT_FROM_Y,
    CONVERT_TO_B,
    MOVE_RIGHT_FROM_B,
    CHECK_X_OR_C,
    CONVERT_X_TO_X,
    MOVE_LEFT_FROM_X,
    CONVERT_C_TO_C,
    MOVE_LEFT_FROM_C,
    CONVERT_Y_TO_Y,
    MOVE_LEFT_FROM_Y_FINAL,
    CONVERT_B_TO_ZERO,
    MOVE_LEFT_FROM_B_FINAL,
    CONVERT_ZERO_TO_ZERO,
    MOVE_LEFT_TO_FINAL_STATE,
    FINAL_STATE,
    END
};

// Perform multiplication of two numbers using a Turing machine
string multiplyNumbers(const string& input) {
    string tape = input;
    State currentState = START;
    int head = 0;  // Initial head position

    while (currentState != END) {
        char currentSymbol = tape[head];

        switch (currentState) {
            case START:
                currentState = MOVE_RIGHT_TO_SEPARATOR;
                break;

            case MOVE_RIGHT_TO_SEPARATOR:
                if (currentSymbol != '0' && currentSymbol != 'c') {
                    head++;
                } else if (currentSymbol == 'c') {
                    currentState = CONVERT_TO_SEPARATOR;
                }
                break;

            case CONVERT_TO_SEPARATOR:
                tape[head] = 'c';
                currentState = MOVE_LEFT_FROM_SEPARATOR;
                break;

            case MOVE_LEFT_FROM_SEPARATOR:
                head--;
                currentState = CONVERT_TO_X;
                break;

            case CONVERT_TO_X:
                if (currentSymbol != '0') {
                    tape[head] = 'X';
                    currentState = MOVE_RIGHT_TO_ZERO;
                } else {
                    currentState = CONVERT_TO_Y;
                }
                break;

            case MOVE_RIGHT_TO_ZERO:
                head++;
                currentState = CONVERT_TO_Y;
                break;

            case CONVERT_TO_Y:
                if (currentSymbol != '0') {
                    tape[head] = 'Y';
                    currentState = MOVE_LEFT_FROM_Y;
                } else {
                    currentState = CONVERT_TO_B;
                }
                break;

            case MOVE_LEFT_FROM_Y:
                head--;
                currentState = CONVERT_TO_B;
                break;

            case CONVERT_TO_B:
                tape[head] = 'B';
                currentState = MOVE_RIGHT_FROM_B;
                break;

            case MOVE_RIGHT_FROM_B:
                head++;
                currentState = CHECK_X_OR_C;
                break;

            case CHECK_X_OR_C:
                if (currentSymbol == 'X') {
                    currentState = CONVERT_X_TO_X;
                } else if (currentSymbol == 'C') {
                    currentState = MOVE_LEFT_FROM_C;
                } else {
                    currentState = CHECK_X_OR_C;
                    head++;
                }
                break;

            case CONVERT_X_TO_X:
                tape[head] = 'X';
                currentState = MOVE_LEFT_FROM_X;
                break;

            case MOVE_LEFT_FROM_X:
                head--;
                currentState = CONVERT_C_TO_C;
                break;

            case CONVERT_C_TO_C:
                tape[head] = 'C';
                currentState = MOVE_LEFT_FROM_C;
                break;

            case MOVE_LEFT_FROM_C:
                head--;
                currentState = CONVERT_Y_TO_Y;
                break;

            case CONVERT_Y_TO_Y:
                tape[head] = 'Y';
                currentState = MOVE_LEFT_FROM_Y_FINAL;
                break;

            case MOVE_LEFT_FROM_Y_FINAL:
                head--;
                currentState = CONVERT_B_TO_ZERO;
                break;

            case CONVERT_B_TO_ZERO:
                tape[head] = '0';
                currentState = MOVE_LEFT_FROM_B_FINAL;
                break;

            case MOVE_LEFT_FROM_B_FINAL:
                head--;
                currentState = CONVERT_ZERO_TO_ZERO;
                break;

            case CONVERT_ZERO_TO_ZERO:
                tape[head] = '0';
                head--;
                currentState = MOVE_LEFT_TO_FINAL_STATE;
                break;

            case MOVE_LEFT_TO_FINAL_STATE:
                if (currentSymbol != '0') {
                    head--;
                } else {
                    currentState = FINAL_STATE;
                }
                break;

            case FINAL_STATE:
                tape = tape.substr(0, head + 1);
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
    string input = "0111c110";

    // Perform multiplication
    string result = multiplyNumbers(input);

    // Output the result
    cout << "Result: " << result << endl;

    return 0;
}
