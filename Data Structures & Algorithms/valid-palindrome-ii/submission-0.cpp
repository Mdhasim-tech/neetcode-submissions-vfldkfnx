class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        int cnt=0;
        bool first=true;
        while(i<j){
            if(s[i]!=s[j] ){
                if(cnt==0){
                    cnt++;
                    i++;
                    continue;
                }else{
                    first= false;
                }

            };
            i++;j--;
        }
        if(first)return true;
        int k=0,l=s.size()-1;
        int cnt2=0;
        bool second=true;
        while(k<l){
            if(s[k]!=s[l] ){
                if(cnt2==0){
                    cnt2++;
                    l--;
                    continue;
                }else{
                   second= false;
                }

            };
            k++;l--;
        }
        return first||second;
    }
};