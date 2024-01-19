#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isSatisfied(const vector<vector<pair<char, bool>>>& formula, const unordered_map<char, bool>& assignment) {
    for (const auto& clause : formula) {
        bool clauseSatisfied = false;
        for (const auto& literal : clause) {
            char variable = literal.first;
            bool isNegated = literal.second;

            // Check if the variable in the assignment matches the current literal
            if ((assignment.find(variable) != assignment.end() && assignment.at(variable) && !isNegated) ||
                (assignment.find(variable) == assignment.end() && isNegated)) {
                clauseSatisfied = true;
                break;
            }
        }

        // If none of the literals in the clause are satisfied, the formula is not satisfied
        if (!clauseSatisfied) {
            return false;
        }
    }

    return true;
}

int main() {
    // Sample input
    vector<vector<pair<char, bool>>> formula = {{'A', false}, {'B', true}, {'C', false}};
    unordered_map<char, bool> assignment = {{'A', true}, {'B', false}, {'C', true}};

    // Check if the formula is satisfied by the assignment
    bool result = isSatisfied(formula, assignment);

    // Output the result
    cout << (result ? "Satisfied" : "Not Satisfied") << endl;  // Satisfied

    return 0;
}
