class Solution {
public:
    int func(vector<int>& a, int i, int j, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int k = i; k <= j; k++){
            int cost = a[i-1] * a[k] * a[j+1] + func(a, i, k-1, dp) + func(a, k+1, j, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return func(nums, 1, n, dp);
    }
};