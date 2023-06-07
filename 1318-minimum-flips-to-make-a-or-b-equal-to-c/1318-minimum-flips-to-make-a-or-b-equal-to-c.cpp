class Solution {
public:
    int minFlips(int a, int b, int c) {
        int or_op = a | b;
        
        // This gives us the bits that are required to be flipped
        int diff = or_op ^ c;

        // Count of bits to flip. Returned at end of function
        int count = 0;

        while (diff) {
            //if it's 1 means flipping required
            if (diff & 1) {
            //it's 1 that means in or_op or c, if any bit is 1. i's needed to make it 0
                if (or_op & 1) {
                    // Incrementing count if rightmost bit of a is 1
                    if (a & 1) count++;
                    // Incrementing count if rightmost bit of b is 1
                    if (b & 1) count++;
                }
                // If the current bit in (a | b) is 0, it means
                // that both a and b had their rightmost bits as 0
                // so changing even 1 would result in (a | b) having
                // 1 as its rightmost bit
                else count++;
            }
            // Right shifting all variables since their bits
            // to flip have been counted
            diff >>= 1;
            or_op >>= 1;
            a >>= 1;
            b >>= 1;
        }
        return count;
    }
};