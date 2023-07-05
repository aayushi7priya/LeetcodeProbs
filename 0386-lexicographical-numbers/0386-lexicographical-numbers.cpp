class Solution {
public:
    int dest;
    vector<int> result;
    void rec(int current) {
        if (current > dest) {
            return;
        }

        result.push_back(current);
        for (int i = 0; i <= 9; i++) {
            if (current * 10 + i <= dest) {
                rec(current * 10 + i);
            }
        }
    }

    
    vector<int> lexicalOrder(int n) {
        dest = n;
        for (int i = 1; i <= 9; i++) {
            rec(i);
        }
        return result;
    }
};