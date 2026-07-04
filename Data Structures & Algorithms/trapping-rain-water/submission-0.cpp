class Solution {
public:
    int trap(vector<int>& height) {
        int max_ar=0;
        int n=height.size();
        vector<int> max_prefix(n);
        vector<int> max_suffix(n);
        for(int i=0; i<n; i++){
            if(i==0) max_prefix[i]=height[0];
            else max_prefix[i]=max(max_prefix[i-1], height[i]);
        }
        for(int j=n-1; j>=0; j--){
            if(j==(n-1)) max_suffix[j]=height[n-1];
            else max_suffix[j]=max(max_suffix[j+1], height[j]);
        }
        for(int k=0; k<n; k++){
            max_ar+=min(max_prefix[k], max_suffix[k]) - height[k];
        }
        return max_ar;
    }
};
