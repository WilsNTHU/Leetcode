class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len_1 = word1.size();
        int len_2 = word2.size();
        string result;
        
        if(len_1 == len_2){
            int i=0;
            for(int k=0; k<len_1; k++){
                result.push_back(word1[i]);
                result.push_back(word2[i]);
                i++;
            }
        }
        else if(len_1 < len_2){
            int i=0;
            for(int k=0; k<len_1; k++){
                result.push_back(word1[i]);
                result.push_back(word2[i]);
                i++;
            }
            result += word2.substr(i, len_2-i);
        }
        else{
            int i=0;
            for(int k=0; k<len_2; k++){
                result.push_back(word1[i]);
                result.push_back(word2[i]);
                i++;
            }
            result += word1.substr(i, len_1-i);
        }
        
        return result;
    }
};