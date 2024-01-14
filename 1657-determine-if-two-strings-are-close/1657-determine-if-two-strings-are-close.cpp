class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if(len1 != len2) return false;
        
        vector<int> v1(26, 0), v2(26, 0);
        
        for(int i=0; i<len1; i++){
            v1[word1[i] - 'a']++;
            v2[word2[i] - 'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(!v1[i] && v2[i]) return false;
            if(v1[i] && !v2[i]) return false;
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return (v1 == v2);
    }
};