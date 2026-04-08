class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        ans[n-1]=-1;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(arr[i]);
            }else{
                if(arr[i]<st.top()){
                    ans[i]=st.top();
                }else{
                    ans[i]=st.top();
                    st.pop();
                    st.push(arr[i]);
                    
                }
            }
        }
        return ans;
    }
};