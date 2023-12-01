class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1(word1[0]);
        string s2(word2[0]);
        vector<string>:: iterator it_1;
        vector<string>:: iterator it_2;
        for(it_1=word1.begin()+1; it_1 != word1.end(); it_1++){
            s1 += *it_1;
        }
        for(it_2=word2.begin()+1; it_2 != word2.end(); it_2++){
            s2 += *it_2;
        }
        if(s1.compare(s2) == 0) return true;
        else return false;
    
    }
};