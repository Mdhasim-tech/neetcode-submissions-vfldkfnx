class Solution {
    int leftmost;
public:
    int expand(int l,int r,string s,int& leftmost){
        int len=0;
        while(l>=0 && r<s.size()){
            if(s[l]==s[r]){
                len=r-l+1;
                leftmost=l;
                
                l--;r++;
            }else{
                break;
            }
        }
        return len;
    }
    string longestPalindrome(string s) {
        int startInd=0;
        int maxLen=0;
        for(int i=0;i<s.size();i++){
            int leftmost1=i,leftmost2=i;
            //for odd len palindrome
            int curLen1 = expand(i, i, s, leftmost1);
            if (curLen1 > maxLen) {
                maxLen = curLen1;
                startInd = leftmost1;
            }
            //for even len palindrome
            int curLen2 = expand(i, i + 1, s, leftmost2);
            if (curLen2 > maxLen) {
                maxLen = curLen2;
                startInd = leftmost2;
            }
        }
      
        return s.substr(startInd, maxLen);
    }
};