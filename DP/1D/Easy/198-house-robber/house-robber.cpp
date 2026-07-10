class Solution {
private:
    int dp(int n, vector<int>& nums, vector<int>& arr){

        if(arr[n] != -1) return arr[n];
        if(n == 0) return nums[0];
        if(n == 1) return max(nums[1], nums[0]);

        int non_pick = dp(n-1, nums,arr);
        int pick = dp(n-2, nums,arr) + nums[n];

        return arr[n] = max(pick, non_pick);

    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, -1);
        return dp(n-1, nums, arr);
    }
};