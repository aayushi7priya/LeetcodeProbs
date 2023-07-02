class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        double result = log(n) / log(3);
        return abs(result - round(result)) < 1e-10;  //don't directly compare both to be equal
    }
};
