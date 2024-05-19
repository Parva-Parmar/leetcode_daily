/*
https://leetcode.com/contest/weekly-contest-398/problems/special-array-ii/
*/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> chk;
        int n = nums.size();
        int ck1 = 0;
        int ck2 = 0;
        for(int i = 0 ; i < n-1 ; i++){
            ck1 = nums[i]&1;
            ck2 = nums[i+1]&1;
            if(ck1 == ck2){
                chk.push_back(i);
            }
        }
        bool qt = false;
        if(chk.size() == 0){
            cout << "here" << endl;
            qt = true;
        }
        vector<bool> anss;
        if(qt){
            for(auto itr : queries){
                anss.push_back(true);
            }
        }
        else{
            for(auto itr : queries){
                auto num1 = lower_bound(chk.begin(),chk.end(),itr[0]);
                auto num2 = lower_bound(chk.begin(),chk.end(),itr[1]);
                // cout << (num2 - num1) << endl;
                // // cout << (*num2) << endl;
                // --num1;
                // cout << (*num1) << endl;
                if(num1 == num2){
                    anss.push_back(true);
                }
                else{
                    anss.push_back(false);
                }
            }
        }
        return anss;
    }
};