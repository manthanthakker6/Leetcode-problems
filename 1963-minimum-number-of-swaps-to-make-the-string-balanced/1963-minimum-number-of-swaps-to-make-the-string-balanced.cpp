class Solution {
public:
    int minSwaps(string s) {
        int unmatched_open = 0;
        
        for (char ch : s) {
            if (ch == '[') {
                unmatched_open++;
            } else {
              
                if (unmatched_open > 0) {
                    unmatched_open--;
                }
            }
        }
        
        
        return (unmatched_open + 1) / 2;
    }
}; 
