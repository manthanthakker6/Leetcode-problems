class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            //removing indices that are outside the window
            if(!dq.empty()&&dq.front()<=i-k){
                dq.pop_front();
            }
            //pop all elemenents which are smaller than incoming number
            while(!dq.empty()&&nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            //record max once window form
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};