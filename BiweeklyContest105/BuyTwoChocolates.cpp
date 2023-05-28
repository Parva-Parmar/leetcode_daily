/*
https://leetcode.com/contest/biweekly-contest-105/problems/buy-two-chocolates/
*/
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int summ = 0;
        if(prices[0]+prices[1]<=money){
            summ = money - (prices[0]+prices[1]);
        }
        else{
            summ = money;
        }
        return summ;
    }
};
