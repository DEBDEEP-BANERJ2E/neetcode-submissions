class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), i;
        int cols = (rows > 0) ? matrix[0].size() : 0;
        if(target < matrix[0][0] || target > matrix[rows-1][cols-1]) return false;
        for(i=0; i<rows;){
            if(target > matrix[i][cols-1]) i++;
            else break;
        }
        int mid, left=0, right=cols-1;
        while(left <= right){
            mid=(left+right)/2;
            if(matrix[i][mid] == target) return true;
            else if(matrix[i][mid] < target) left = mid+1;
            else right=mid-1;
        }
        return false;
    }
};
