/*
https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/
*/

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ocr;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == x){
                ocr.push_back(i);
            }
        }
        vector<int> ans;
        
        for(auto i : queries){
            if(i > ocr.size()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(ocr[i-1]);
            }
        }
        
        return ans;
    }
};