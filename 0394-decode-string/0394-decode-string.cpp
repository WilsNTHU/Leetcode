class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return helper(s, pos);
    }
    
    string helper(string &s, int &pos){
        int num = 0;
        string result = "";
        for(; pos<s.size(); pos++){
            if(s[pos]>='0' && s[pos]<='9') num = num*10 + (s[pos]-'0');
            else if(s[pos] == '['){
                string temp = helper(s, ++pos);
                for(; num>0; num--) result += temp;
            }
            else if(s[pos] == ']') return result;
            else result += s[pos];
        }
        
        
        return result;
    }
};