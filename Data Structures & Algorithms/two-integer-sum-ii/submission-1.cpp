class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto a=&numbers[0], b=&numbers[numbers.size()-1];
        int c=0, d=numbers.size();
        for(int i=0; i<numbers.size(); i++){
            if(*a + *b == target){
                return {c+1, d};
            }
            else if(*a + *b < target){
                a++;
                c++;
            } 
            else{
                b--;
                d--;
            }
        }
    }
};
