#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool evaluateClause(const vector<int>& clause, const vector<bool>& assignment) {
    for (int literal : clause) {
        int variable = abs(literal);
        bool isNegated = literal < 0;

        if ((assignment[variable] && !isNegated) || (!assignment[variable] && isNegated)) {
            return true; // Clause is satisfied by the assignment
        }
    }

    return false; // Clause is not satisfied by the assignment
}

bool evaluateCNFFormula(const vector<vector<int>>& cnf_formula, const vector<bool>& assignment) {
    for (const auto& clause : cnf_formula) {
        if (!evaluateClause(clause, assignment)) {
            return false; // Formula is not satisfied by the assignment
        }
    }

    return true; // Formula is satisfied by the assignment
}

bool solveSATBruteForce(const vector<vector<int>>& cnf_formula, int numVariables) {
    for (int i = 0; i < (1 << numVariables); ++i) {
        vector<bool> assignment(numVariables + 1, false);

        // Convert the current binary representation to a truth value assignment
        for (int j = 0; j < numVariables; ++j) {
            assignment[j + 1] = (i & (1 << j)) != 0;
        }

        if (evaluateCNFFormula(cnf_formula, assignment)) {
            return true; // Formula is satisfiable
        }
    }

    return false; // Formula is not satisfiable
}

int main() {
    // Sample input
    vector<vector<int>> cnf_formula1 = {{1, 2, -3}, {-1, -2, 3}, {2, -3}};
    vector<vector<int>> cnf_formula2 = {{1, 2}, {-1, 3}, {-2, -3}};
    vector<vector<int>> cnf_formula3 = {{1, 2, 3}, {-1, -2, 3}, {1, -3}};
    vector<vector<int>> cnf_formula4 = {{1, 2}, {-1, -2}, {1, -2}};

    int numVariables = 3;

    // Check if each formula is satisfiable
    cout << "Formula 1: " << (solveSATBruteForce(cnf_formula1, numVariables) ? "True" : "False") << endl;  // True
    cout << "Formula 2: " << (solveSATBruteForce(cnf_formula2, numVariables) ? "True" : "False") << endl;  // True
    cout << "Formula 3: " << (solveSATBruteForce(cnf_formula3, numVariables) ? "True" : "False") << endl;  // True
    cout << "Formula 4: " << (solveSATBruteForce(cnf_formula4, numVariables) ? "True" : "False") << endl;  // False

    return 0;
}
