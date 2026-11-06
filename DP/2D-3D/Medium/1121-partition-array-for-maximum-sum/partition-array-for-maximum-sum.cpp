class Solution {
public:
    int helper (vector<int>& a, int k, int n, int i, vector<int>&dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxi = INT_MIN, maxAns = INT_MIN, len = 0, sum = 0;

        for(int j = i; j < min(n, i + k); j++){
            len++;
            maxi = max(maxi, a[j]);
            sum = (len*maxi) + helper(a, k, n , j+1, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[i] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n, -1);
        return helper(arr, k, n, 0, dp);
    }
};