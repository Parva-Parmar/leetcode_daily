/*
https://leetcode.com/problems/permutation-difference-between-two-strings/
*/

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char,int> mp;
        for(int i = 0 ; i < s.length() ; i++){
            mp[s[i]] = i+1;
        }
        int ans = 0;
        for(int i = 0 ; i < t.length() ; i++){
            ans += abs(mp[t[i]] - (i+1));
        }
        return ans;
    }
};