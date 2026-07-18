class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> res(n);
        prefix[0]=1;
        suffix[n-1]=1;

        for(int i=0; i<n; i++){
            if(i>0) prefix[i]=prefix[i-1]*nums[i-1];
            if(i!=n-1) suffix[n-i-2]=suffix[n-i-1]*nums[n-i-1];
        }

        for(int i=0; i<n; i++){
            res[i]=prefix[i]*suffix[i];
        }
        return res;
    }
};
