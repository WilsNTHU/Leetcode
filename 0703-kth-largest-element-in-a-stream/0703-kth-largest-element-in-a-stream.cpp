class KthLargest {
    public:
        KthLargest(int k, vector<int>& nums): k(k){
            if(k > nums.size()){
                for(auto &x: nums) pq.push(x);
            }
            else{
                for(int i=0; i<k; i++) pq.push(nums[i]);
                for(int i=k; i<nums.size(); i++){
                    if(nums[i] > pq.top()){
                        pq.pop();
                        pq.push(nums[i]);
                    }
                }
            }
        }

        int add(int val) {
            if(pq.size() < k) pq.push(val);
            else{
                if(val > pq.top()){
                    pq.pop();
                    pq.push(val);
                }
            }
            return pq.top();
        }
    private:
        priority_queue<int, vector<int>, greater<>> pq;
        int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */