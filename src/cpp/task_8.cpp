#include <iostream>
#include <vector>

using namespace std;

bool canPartition(vector<int>& nums) {
    int totalSum = 0;
    
    // Calculate the total sum of the array
    for (int num : nums) {
        totalSum += num;
    }
    
    // If the total sum is odd, it cannot be partitioned into two equal sum subsets
    if (totalSum % 2 != 0) {
        return false;
    }
    
    int targetSum = totalSum / 2;
    int n = nums.size();
    
    // Create a 2D array to store intermediate results
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

    // Initialize base case
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the DP array
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            // If the current element is greater than the current sum, skip it
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Either include or exclude the current element
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][targetSum];
}

int main() {
    // Sample input
    vector<int> nums1 = {1, 5, 11, 5};
    vector<int> nums2 = {1, 2, 3, 5};
    vector<int> nums3 = {12, 2, 31, 0, 5};

    // Check if a valid partition exists for each case
    bool result1 = canPartition(nums1);
    bool result2 = canPartition(nums2);
    bool result3 = canPartition(nums3);

    // Output the results
    cout << "Result 1: " << (result1 ? "True" : "False") << endl;  // True
    cout << "Result 2: " << (result2 ? "True" : "False") << endl;  // False
    cout << "Result 3: " << (result3 ? "True" : "False") << endl;  // False

    return 0;
}
