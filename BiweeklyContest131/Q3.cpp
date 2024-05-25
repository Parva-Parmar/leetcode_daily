/*
https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/
*/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        set<int> s1;
        map<int,int> s2;
        map<int,int> mp;
        for(auto i : queries){
            if(s1.count(i[0])){
                s2[mp[i[0]]]--;
                if(s2[mp[i[0]]] == 0){
                    s2.erase(mp[i[0]]);
                }
            }
            s1.insert(i[0]);
            s2[i[1]]++;
            mp[i[0]] = i[1];
            ans.push_back(min(s1.size(),s2.size()));
        }
        return ans;
    }
};