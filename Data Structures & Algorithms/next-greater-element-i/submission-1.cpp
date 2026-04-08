class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mpp;
        for(int j=nums2.size()-1;j>=0;j--){

                    while(!st.empty() && nums2[j]>st.top()){
                        st.pop();
                    }
                
                if(st.empty()){
                    mpp[nums2[j]]=-1;
                }else{
                    mpp[nums2[j]]=st.top();
                }
                
            
            st.push(nums2[j]);
        }
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=mpp[nums1[i]];
        }
        return ans;
    }
};