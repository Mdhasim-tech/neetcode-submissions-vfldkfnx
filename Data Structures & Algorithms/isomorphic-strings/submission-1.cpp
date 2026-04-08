class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char,char>mpp;
        unordered_set<char>used;
        for(int i=0;i<s.size();i++){
            if(mpp.count(s[i])){
                if(mpp[s[i]]!=t[i])return false;
            }else{
                if(used.count(t[i]))return false;
                mpp[s[i]]=t[i];
                used.insert(t[i]);
            }
        }
        return true;
    }
};