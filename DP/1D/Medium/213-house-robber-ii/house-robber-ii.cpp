class Solution {
private:
    int dp(int n, int end, vector<int>& nums, vector<int>& arr) {
        if (n < end)return 0;

        if (arr[n] != -1)return arr[n];
        if (n == end)
            return nums[n];
 
        int non_pick = dp(n - 1, end, nums, arr);
        int pick = dp(n - 2, end, nums, arr) + nums[n];

        return arr[n] = max(pick, non_pick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> arr1(n, -1);
        vector<int> arr2(n, -1);

        int a1 = dp(n - 1, 1, nums, arr1);
        int a2 = dp(n - 2, 0, nums, arr2);
        return max(a2, a1);
    }
};