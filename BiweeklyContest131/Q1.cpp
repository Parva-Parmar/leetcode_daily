/*
https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/
*/

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> cnt(51);
        for(auto i : nums){
            cnt[i]++;
        }
        
        int ans = 0;
        for(int i = 0 ; i < 51 ; i++){
            if(cnt[i] == 2){
                ans = ans^i;
            }
        }
        return ans;
    }
};