#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

char getRandomVariable(int numVariables) {
    // Generate a random variable (A, B, C, ...)
    return static_cast<char>('A' + rand() % numVariables);
}

string generateRandom3SATFormula(int numVariables, int numClauses) {
    srand(static_cast<unsigned>(time(nullptr)));

    vector<string> clauses;

    for (int i = 0; i < numClauses; ++i) {
        string clause;
        for (int j = 0; j < 3; ++j) {
            char variable = getRandomVariable(numVariables);
            bool negate = rand() % 2 == 0;

            if (negate) {
                clause += "~";
            }

            clause += variable;

            if (j < 2) {
                clause += " | ";
            }
        }

        clauses.push_back("(" + clause + ")");
    }

    return join(clauses, " & ");
}

int main() {
    // Sample input
    int numVariables = 3;
    int numClauses = 2;

    // Generate a random 3-SAT formula
    string randomFormula = generateRandom3SATFormula(numVariables, numClauses);

    // Output the result
    cout << randomFormula << endl;

    return 0;
}
