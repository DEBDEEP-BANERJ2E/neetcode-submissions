class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        int k=nums.size()-1;
        for(int i=0; i<nums.size()-2; i++){

            if(nums[i]==nums[i-1] && i>0) continue;
            k=nums.size()-1;

            for (int j=i+1; j<nums.size()-1;){
                if(k<=j) break;
                if(j>(i+1) && nums[j]==nums[j-1]){
                    j++; continue;
                } 
                if(nums[i] + nums[j] + nums[k] == 0 && j!=k){
                    v.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                }
                else if(nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else if(nums[i] + nums[j] + nums[k] > 0)
                    k--;
            }
        }
        return v;
    }
};
