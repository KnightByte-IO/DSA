class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
            // cout << matrix[i][0] << " ";
        }

        vector<pair<int, int>> dir = {
            {-1, 0},  // Up
            {-1, -1}, // Upper-left
            {-1, 1}   // Upper-right
        };
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mini = INT_MAX;
                for (int k = 0; k < 3; k++) {
                    int nr = i + dir[k].first;
                    int nc = j + dir[k].second;
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                        mini = min(mini, dp[nr][nc]);
                        // cout << mini << " " << dp[nr][nc] << endl;

                    }
                }
                dp[i][j] = mini + matrix[i][j];
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};