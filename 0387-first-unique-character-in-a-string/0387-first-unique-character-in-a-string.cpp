class Solution {
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
};