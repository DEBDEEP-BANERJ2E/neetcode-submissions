#include <cstring>
class CountSquares {
private:
    int ptsCount[1001][1001];
    vector<pair<int, int>> pts;
public:
    CountSquares() {
        memset(ptsCount, 0, sizeof(ptsCount));
    }
    
    void add(vector<int> point) {
        int x = point[0]; int y = point[1]; 
        ptsCount[x][y]++; pts.push_back({x, y});
    }
    int count(vector<int> point) {
        int qx = point[0]; int qy = point[1]; int res = 0;
    // Iterate through all previously added points to find valid diagonals
        for (const auto& p : pts) {
            int x = p.first;
            int y = p.second;
            // Check if (qx, qy) and (x, y) form a valid square diagonal
            if (abs(qx - x) == abs(qy - y) && qx != x && qy != y) {
                // Multiply the frequencies of the required missing corners
                res += ptsCount[x][qy] * ptsCount[qx][y];
            }
        }
        
        return res;
    }
};
