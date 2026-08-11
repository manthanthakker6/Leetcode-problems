class Solution {
    private:
    vector<int>findGreaterElement(vector<int>arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while((s.top()!=-1)&&s.top()<=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(curr);
        }
        return ans;

    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nextGreaterArr=findGreaterElement(nums2,nums2.size());
        unordered_map<int,int>m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]]=nextGreaterArr[i];

        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int val=nums1[i];
            ans.push_back(m[val]);

        }

   return ans;
    }
};