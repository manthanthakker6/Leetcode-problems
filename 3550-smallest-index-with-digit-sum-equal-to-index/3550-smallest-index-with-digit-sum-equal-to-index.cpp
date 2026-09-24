class Solution {

public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int sum = 0;
            
            // Special case for nums[i] == 0
            if (num == 0) {
                sum = 0;
            }

            // Calculate sum of digits
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            
            // If digit sum matches the current index, return it immediately
            if (sum == i) {
                return i;
            }
        }
        
        // If no such index exists
        return -1;
    }

};