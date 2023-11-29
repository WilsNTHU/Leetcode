class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len = magazine.size();
        int len_2 = ransomNote.size();
        map<char, int> m;
        
        for(int i=0; i<len; i++){
            if(m[magazine[i]]) m[magazine[i]]++;
            else m[magazine[i]] = 1;
        }
        
        for(int i=0; i<len_2; i++){
            if(!m[ransomNote[i]]) return false;
            else m[ransomNote[i]] --;
        }
        
        return true;
    }
};