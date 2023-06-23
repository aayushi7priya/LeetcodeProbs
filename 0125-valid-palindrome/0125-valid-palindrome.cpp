class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> s_1;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isalnum(ch)) {
                if (isalpha(ch))
                    s_1.push_back(tolower(ch));
                else
                    s_1.push_back(ch);
            }
        }

        vector<char> s_2 = s_1;
        reverse(s_1.begin(), s_1.end());

        return s_2 == s_1;
    }
};
