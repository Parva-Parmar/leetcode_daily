/*
https://leetcode.com/problems/maximum-difference-score-in-a-grid/
*/


class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        int row_min = INT_MIN;
        int col_min = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            row_min = grid[i][0];
            
            for(int j = 0 ; j < m ; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                if(j > 0){
                    row_min = min(row_min,grid[i][j-1]);
                    dp[i][j] = min(dp[i][j],row_min);
                }
                if(i > 0 ){
                    dp[i][j] = min(dp[i][j],dp[i-1][j]);
                    dp[i][j] = min(dp[i][j],grid[i-1][j]);
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(dp[i][j] == INT_MAX){
                    continue;
                }
                ans = max(ans, (grid[i][j] - dp[i][j]));
            }
        }
        return ans;
    }
};