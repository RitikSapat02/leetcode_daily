class Solution {
public:
    bool detectCapitalUse(string s) {
        int countCapital = 0;
        int countLower = 0;
        
        for(int i=0;i<s.length();++i){
            if(isupper(s[i])){
                countCapital++;
            }else{
                countLower++;
            }
        }
        
        if(countCapital == s.length()  (countCapital == 1 && isupper(s[0]))  countLower == s.length()){
            return true;
        }else{
            return false;
        }
      
    }
};