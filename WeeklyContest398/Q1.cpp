/*
https://leetcode.com/contest/weekly-contest-398/problems/special-array-i/
*/

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        int ck1 = 0;
        int ck2 = 0;
        bool ans = true;
        for(int i = 0 ; i < n-1 ; i++){
            ck1 = nums[i]&1;
            ck2 = nums[i+1]&1;
            if(ck1 == ck2){
                ans = false;
                break;
            }
        }
        return ans;
    }
};