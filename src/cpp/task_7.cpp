#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minRabbits(vector<int>& answers) {
    unordered_map<int, int> count;

    for (int ans : answers) {
        count[ans]++;
    }

    int result = 0;

    for (auto it : count) {
        int group_size = it.first + 1;  // Number of rabbits with the same color in a clique
        int rabbits_count = it.second;

        // Calculate the minimum number of cliques needed for this group
        int cliques = (rabbits_count + group_size - 1) / group_size;

        // Update the total number of rabbits
        result += cliques * group_size;
    }

    return result;
}

int main() {
    // Sample input
    vector<int> answers1 = {1, 1, 2};
    vector<int> answers2 = {3, 3, 3, 3, 3};

    // Calculate the minimum number of rabbits for each case
    int result1 = minRabbits(answers1);
    int result2 = minRabbits(answers2);

    // Output the results
    cout << "Result 1: " << result1 << endl;  // 5
    cout << "Result 2: " << result2 << endl;  // 5

    return 0;
}
