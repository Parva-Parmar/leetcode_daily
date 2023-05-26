/*
https://leetcode.com/problems/stone-game-ii/description/
*/

class Solution {
public:
    int fun(vector<int> &piles,int m , int ind,int turn,vector<int> &sum ,vector<vector<vector<int>>> &dp){
        if(ind>=piles.size()){
            return 0;
        }
        if(dp[ind][m][turn]!=0){
            return dp[ind][m][turn];
        }
        if(turn==1){
            int ans = 0;
            for(int i = ind;i<ind + 2*m && i < piles.size() ; i++){
                ans = max(ans,query(ind, i,sum) + fun(piles,max(i-ind+1,m),i+1,2,sum,dp));
            }
            return dp[ind][m][turn] = ans;
        }
        else{
            int ans = INT_MAX;
            for(int i = ind;i<ind + 2*m && i < piles.size() ; i++){
                ans = min(ans,fun(piles,max(i-ind+1,m),i+1,1,sum,dp));
            }
            if(ans == INT_MAX){
                ans = 0;
            }
            return dp[ind][m][turn] = ans; 
        }
    }
    int query(int l,int r, vector<int> &sum){
        if(l==0){
            return sum[r];
        }
        else{
            return sum[r] - sum[l-1];
        }
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n+1,vector<int>(3)));
        vector<int> sum(n);
        for(int i = 0 ; i < n ; i++){
            if(i==0){
                sum[i] = piles[i];
            }
            else{
                sum[i] = sum[i-1] + piles[i];
            }
        }
        return fun(piles,1, 0,1, sum,dp);
    }
};
