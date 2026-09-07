/*class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};
        queue<pair<char,int>> q;//stores {char,index}
        
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            freq[ch-'a']++;
            //push character and index
            q.push({ch,i});
            //discard characters from front that have count greater than 1
            while(!q.empty()&&freq[q.front().first-'a']>1){
             q.pop();
            }

     }
     return q.empty()?-1:q.front().second;
    }
};*/

// Method 2 simpler solution
class Solution {
public:
    int firstUniqChar(string s) {
        // Step 1: Track frequencies of lowercase characters 'a' through 'z'
        int freq[26] = {0};
        for (int i=0;i<s.length();i++) {
            char ch=s[i];
            freq[ch - 'a']++;
        }
        
        // Step 2: Find the first index with a count of 1
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};