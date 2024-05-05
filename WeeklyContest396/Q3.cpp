/*
"https://leetcode.com/problems/minimum-length-of-anagram-concatenation/"
*/

class Solution {
public:
    int minAnagramLength(string s) {
        if(s.length() == 1){
            return 1;
        }
        int ans = 0;
        string s1 = "";
        int cnt = 0;
        map<multiset<char>,int> mp;
        for(int i = 0 ; i < s.length() ; i++){
            if(s.length()%(i+1) != 0){
                    continue;
            }
            multiset<char> st;
            mp.clear();
            s1 = "";
            // cout << (i+1) << " " << " len" << endl;
            for(int j = 0 ; j < s.length() ; j++){
                if(s1.length()%(i+1) == 0 && s1.length() > 0){
                    mp[st]++;
                    if(mp.size() > 1){
                        break;
                    }
                    s1 = "";
                    st.clear();
                }
                s1.push_back(s[j]);
                st.insert(s[j]);
                // cout << s[j] << " " << j << " str" << endl;
                // cout << s1 << endl;
            }
            if(s1.length() >= 1){
                mp[st]++;
            }
            if(mp.size() == 1){
                // cout << i << " " << "here" << endl;
                ans = i+1;
                break;
            }
        }
        return ans;
    }
};