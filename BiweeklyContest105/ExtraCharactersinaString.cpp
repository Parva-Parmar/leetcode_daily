/*
https://leetcode.com/contest/biweekly-contest-105/problems/extra-characters-in-a-string/
*/
class Solution { 
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> mp;
        for(auto i : dictionary){
            mp[i]=1;
        }
        // for(auto i : mp){
        //     cout << i.first << " ";
        // }
        // cout << endl;
        int n = s.length();
        vector<int> dp(n+1 , 0);
        cout << endl;
        for(int i = 1 ; i <= n ; i++){
            dp[i] = dp[i-1] + 1;
            for(int j = i ; j>=1 ; j--){
                string sub = s.substr(j-1 , (i-j)+1);
                // cout << sub << endl;
                if(mp[sub]>0){
                    // cout << "here" << endl;
                    dp[i] = min(dp[i],dp[j-1]);
                    // cout << "dp[i] " << i << " " << dp[i] << endl;
                }
            }
        }
        return dp[n];
    }
};
