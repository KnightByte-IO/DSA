class Solution {
public:  

int function(string &s, int i, int n, vector<int>&dp, vector<vector<bool>> &isPal)
{
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];
        int mini = INT_MAX;

        for(int j = i; j < n; j++){
            if(isPal[i][j]){
                int cost = 1 + function(s, j+1, n, dp, isPal);
                mini = min(mini, cost);
            }
        }        
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n, -1);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j - i <= 2 || isPal[i+1][j-1])){
                    isPal[i][j] = true;
                }
            }
        }
        return function(s, 0, n, dp, isPal) - 1;
    }
};