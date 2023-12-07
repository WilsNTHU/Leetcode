class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        stringstream ss(s);
        string temp;
        while(ss >> temp){
            arr.push_back(temp);
        }
        
        string answer;
        for(auto it = arr.rbegin(); it != arr.rend(); it++){
            if(it != arr.rbegin()) answer += " ";
            answer += *it;
        }
        
        return answer;
    }
};