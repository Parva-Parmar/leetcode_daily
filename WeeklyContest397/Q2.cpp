/*
https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/
*/


class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        long long summ = INT_MIN;
        long long maxx = 0;
        long long temp = 0;
        for(int i = 0 ; i < k ; i++){
            temp = 0;
            for(int j = i ; j < energy.size() ; j += k){
                // cout << i << ' ' << j << " i and j" << endl;
                temp += energy[j];
                // cout << temp << endl;
                if(energy[j] > temp){
                    temp = energy[j];
                }
            }
            summ = max(summ,temp);
        }
        return (int)summ;
    }
};