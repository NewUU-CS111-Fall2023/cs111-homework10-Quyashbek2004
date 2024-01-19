#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool hasZeroSumTriplet(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1, right = n - 1;
        int targetSum = -nums[i];

        while (left < right) {
            int currentSum = nums[left] + nums[right];

            if (currentSum == targetSum) {
                return true;
            } else if (currentSum < targetSum) {
                left++;
            } else {
                right--;
            }
        }
    }

    return false;
}

int main() {
    // Sample input
    vector<int> input_set1 = {-5, -17, 7, -4, 3, -2, 4};
    vector<int> input_set2 = {-6, 7, -4, -13, -2, 5, 13};
    vector<int> input_set3 = {-1, 2, 13, -4, 5, 4, 2, -13, 3, 0};

    // Test cases
    bool output1 = hasZeroSumTriplet(input_set1);
    bool output2 = hasZeroSumTriplet(input_set2);
    bool output3 = hasZeroSumTriplet(input_set3);

    // Output results
    cout << "Input Set 1: " << (output1 ? "True" : "False") << endl;  // True
    cout << "Input Set 2: " << (output2 ? "True" : "False") << endl;  // False
    cout << "Input Set 3: " << (output3 ? "True" : "False") << endl;  // True

    return 0;
}
