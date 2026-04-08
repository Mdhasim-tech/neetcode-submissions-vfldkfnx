class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n1=word.size();
        int n2=abbr.size();
        int i=0;
        int j=0;
        while(i<n1){
            if(word[i]!=abbr[j] && !isdigit(abbr[j]))return false;
            if(abbr[j]=='0')return false; //handles empty substring 
            if(isdigit(abbr[j])){
                        int num = 0;
                while (j < n2 && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i += num;  
            }
            else{
                i++;j++;
            }
    
        }
        return (i==word.size() && j==abbr.size());
    }
};