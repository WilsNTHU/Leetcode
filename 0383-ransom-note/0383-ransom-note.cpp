class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len_1 = ransomNote.size();
        int len_2 = magazine.size();
        
        int arr[26];
        memset(arr, 0, sizeof(arr));
        
        if(len_1 > len_2) return false;
        else{
            for(int i=0; i<len_2; i++) arr[magazine[i]-'a']++;
            for(int i=0; i<len_1; i++){
                if(!arr[ransomNote[i]-'a']) return false;
                else arr[ransomNote[i]-'a']--;
            }
            
            return true;
        }
    }
};