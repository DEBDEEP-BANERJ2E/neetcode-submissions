class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        char ch='\u0000';
        int num=0, index=0;

        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                ch= board[r][c];
                if(ch!='.'){
                    //Converting digits "1-9" to "0-8" to be
                    //used as indices for rows[][] and cols[][]
                    num=ch-'1';
                    index = (r / 3) * 3 + (c / 3);
                    if(rows[r][num] || cols[c][num] || boxes[index][num]) {
                        return false;
                    }
                    rows[r][num] = true;
                    cols[c][num] = true;
                    boxes[index][num] = true;
                }
            }
        }
        return true;
    }
};
