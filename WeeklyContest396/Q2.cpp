/*
"https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/"
*/

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        map<string , int> mp;
        string s = "";
        for(int i = 0 ; i < word.length() ; i++){
            if(i%k == 0){
                s = "";
            }
            s.push_back(word[i]);
            if(i%k == k-1){
                mp[s]++;
            }
        }
        int num = word.length()/k;
        int cnt = 0;
        for(auto it : mp){
            cnt = max(cnt,it.second);
        }
        return (num-cnt);
    }
};