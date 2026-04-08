class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<pair<int,int>>vec;
        for(auto it:mpp){
            vec.push_back(it);
        }
        sort(vec.begin(),vec.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        });
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
