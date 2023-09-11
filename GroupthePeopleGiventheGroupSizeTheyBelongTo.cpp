class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>> ind;
        for(int i = 0 ; i < groupSizes.size() ; i++){
            ind.push_back({groupSizes[i],i});
        }
        sort(ind.begin(),ind.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int cnt = 0;
        for(auto i : ind){
            cnt = i.first;
            temp.push_back(i.second);
            if(temp.size()==cnt){
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};
