/*
"https://leetcode.com/problems/valid-word/"
*/


class Solution {
public:
    bool isValid(string word) {
        string s;
        int n = word.length();
        if(n < 3){
            return false;
        }
        for(auto i : word){
            if(i>='A' && i <= 'Z'){
                s.push_back(i);
            }
            else if(i >='a' && i <='z'){
                s.push_back(toupper(i));
            }
            else if(i >='0' && i<='9'){
                s.push_back(i);
            }
            else{
                return false;
            }
        }
        set<char> st;
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        set<char> st2;
        for(auto i : s1){
            if(st.count(i) == 0){
                st2.insert(i);
            }
        }
        bool ans = false;
        int c1 = 0;
        int c2 = 0;
        for(auto i : s){
            if(st.count(i)){
                c1 = 1;
            }
            else if(st2.count(i)){
                c2 = 1;
            }
        }
        if(c1 && c2){
            ans = true;
        }
        
        return ans;
    }
};