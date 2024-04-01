#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum < target || (sum + target) % 2 == 1) {
            return 0;
        }
        int t = (sum + abs(target)) / 2;
        vector<int> dp(t + 1, 0);
        dp[0] = 1;

        for(auto& num: nums){
            for(int j = t; j >= num; j--){
                dp[j] += dp[j - num];
            }
        }
        return dp[t];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << s.findTargetSumWays(nums, target) << endl;
    return 0;
}
