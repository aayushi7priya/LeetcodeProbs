class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n <= 2) return true;  
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];
        
        
        int dx = x1 - x0;
        int dy = y1 - y0;
        
        for (int i = 2; i < n; i++) {
            int xi = coordinates[i][0];
            int yi = coordinates[i][1];
            
           //this is done just to avid the edge case when denominator becomes zero
            if ((yi - y0) * dx != dy * (xi - x0)) {
                return false;
            }
        }
        
        return true;
    }
};
