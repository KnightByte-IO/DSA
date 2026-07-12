class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>> dp(m, vector<int>(n, 1e9));
        // dp[0][0] = triangle[0][0];

        vector<pair<int, int>> dir {{-1, -1}, {-1, 0}};
        for(int i = 0; i < m; i++){
            int sz = triangle[i].size();
            for(int j = 0; j < sz; j++){
                int mini = INT_MAX;
                for(int k = 0; k < 2; k++){
                    int nr = i + dir[k].first;
                    int nc = j + dir[k].second;
                    if(nr >= 0 && nc >= 0 && nr < m && nc < sz){
                        mini = min(dp[nr][nc], mini);
                    }
                }
                if(mini == INT_MAX) dp[i][j] = triangle[i][j];
                else dp[i][j] = mini + triangle[i][j];
            }
        }

        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};