class Solution {
public:
    string s;
    vector<vector<string>> result;
    vector<string> current;
    bool isPalindrome(int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) 
            return false;  
            i++;
            j--;
        }
        return true;
    }
    void rec(int start) {
        int n = s.length();
        // Base case:end of the string
        if (start == n) {
            result.push_back(current);
            return;
        }
    
        // Iterate over all possible substrings
        for (int i = start; i < n; i++) {
            if (isPalindrome( start, i)) {
                // If the current substring is a palindrome, add it to the current partition
                current.push_back(s.substr(start, i - start + 1));
            
                // Recursively partition the remaining substring
                rec(i + 1);
            
                // Remove the current substring from the current partition for backtracking
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string st) {
             s = st;
             rec( 0);
    
            return result;
        }
};