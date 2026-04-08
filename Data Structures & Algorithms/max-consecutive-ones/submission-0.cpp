class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int cnt=0;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==1){
                cnt++;
                j++;
            }else{
                maxi=max(maxi,cnt);
                cnt=0;
                j++;
                i=j;
            }
        }
        return cnt==0?maxi:max(maxi,cnt);
    }
};