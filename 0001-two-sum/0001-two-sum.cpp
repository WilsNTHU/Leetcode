#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int x;
    unordered_multimap<int, int> map;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            map.emplace(nums[i], i);
        }
        for(int i=0; i<nums.size(); i++){
            x = target - nums[i];
            if(x == nums[i]){
                auto ip = map.equal_range(x);
                for(auto it = ip.first; it != ip.second; it++){
                    if(it->second != i) return vector<int>({i, it->second});
                    else continue;
                }
            }
            else{
                auto it = map.find(x);
                if(it != map.end()){
                    return vector<int>({i, it->second});
                }
            }
        }

        return vector<int>();
    }
};