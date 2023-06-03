class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        
        string key = s1 + "#" + s2;
        if (memo.count(key))
            return memo[key];

        // Base case: Check if the strings are equal
        if (s1 == s2)
            return true;

        // Check if the strings have the same characters
        vector<int> count(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                memo[key] = false;
                return false;
            }
        }

        // Check all possible split positions and recursively check if the substrings are scrambled
        for (int i = 1; i < s1.length(); i++) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
                (isScramble(s1.substr(0, i), s2.substr(s2.length() - i)) && isScramble(s1.substr(i), s2.substr(0, s2.length() - i)))) {
                memo[key] = true;
                return true;
            }
        }

        memo[key] = false;
        return false;
    }
};
