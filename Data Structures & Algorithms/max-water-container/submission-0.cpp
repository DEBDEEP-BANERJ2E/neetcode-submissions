class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j=heights.size()-1;
        int max_h=(j-i)*(min(heights[i], heights[j]));
        int new_max=0;
        for(i=0; i<heights.size()-1;){
            if(i>=j) break;
            new_max=(j-i)*(min(heights[i], heights[j]));
            if(new_max > max_h)
                max_h = new_max;
            if(heights[i]>= heights[j]) j--;
            else i++;
        }
        return max_h;
    }
};
