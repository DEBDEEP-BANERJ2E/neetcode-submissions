class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());
        int length=0;

        for(int i : mp){
            if(mp.find(i-1)==mp.end()){
                int num = i;
                int currStreak = 1;
                while(mp.find(num+1)!=mp.end()){
                    num+=1;
                    currStreak+=1;
                }
                length=max(currStreak, length);
            }
            
        }
        return length;
    }
};
