class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m(nums.begin(), nums.end());
        int longest=0;
        for(int i : nums){
            if(m.find(i-1)==m.end()){
                int num = i;
                int count = 0;
                while(m.find(num)!=m.end()){
                    num++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }   
};
