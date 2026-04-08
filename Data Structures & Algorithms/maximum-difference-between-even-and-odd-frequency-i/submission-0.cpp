class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        int maxi=INT_MIN;
        for(auto it:mpp){
            int cnt=it.second;
            if(cnt%2==1){
                for(auto item:mpp){
                    if(item.second%2==0){
                        int diff=cnt-item.second;
                        maxi=max(maxi,diff);
                    }
                }
            }
        }
        return maxi;
    }
};