/*
https://leetcode.com/contest/weekly-contest-398/problems/sum-of-digit-differences-of-all-pairs/
*/

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int len = 0;
        int temp = nums[0];
        int n = nums.size();
        while(temp>0){
            len++;
            temp = temp/10;
        }
        vector<vector<int>> chk(len,vector<int>(10,0));
        for(auto itr : nums){
            temp = itr;
            for(int i = 0 ; i < len ; i++){
                int digit = temp%10;
                chk[i][digit]++;
                temp = temp/10;
            }
        }
        long long summ = 0;
        long long summ1 = 0;
        long long summ2 = 0;
        long long cnt = 0;
        // for(int i = 0 ; i < len ; i++){
        //     for(int j = 0 ; j < 10 ; j++){
        //         cout << chk[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        for(int i = 0 ; i < len ; i++){
            summ1 = 0;
            cnt = 0;
            // cout << i << " i " << endl;
            for(int j = 0 ; j < 10 ; j++){
                summ1 += chk[i][j]*j;
                cnt += chk[i][j];
            }
            // cout << summ1 << endl;
            for(int j = 9 ; j >= 0 ; j--){
                if(chk[i][j]){
                    // summ2 = (j*cnt - summ1)*chk[i][j];
                    // summ += summ2;
                    // summ1 -= chk[i][j]*j;
                    // cnt -= chk[i][j];
                    // cout << summ2 << endl;
                    // cout << summ << endl;
                    summ2 = chk[i][j]*(cnt - chk[i][j]);
                    // cout << summ2 << endl;
                    summ += summ2;
                    cnt -= chk[i][j];
                }
            }
        }
        return summ;
    }
};