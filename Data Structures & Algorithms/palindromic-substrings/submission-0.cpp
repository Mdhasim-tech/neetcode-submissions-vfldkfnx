class Solution {
public:
    int expand(int l,int r,string s){
        int cnt=0;
        while(l>=0 && r<s.size()){
            if(s[l]==s[r]){
                cnt++;
                l--;r++;
            }else{
                break;
            }
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt1=0,cnt2=0;
        for(int i=0;i<s.size();i++){
            cnt1+=expand(i,i,s);
            cnt2+=expand(i,i+1,s);

        }
        return cnt1+cnt2;
    }
};
