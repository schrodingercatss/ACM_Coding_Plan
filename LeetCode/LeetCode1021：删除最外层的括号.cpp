class Solution {
public:
    string removeOuterParentheses(string S) {
        string str;
        int l = 1, r = 0;
        for(int i = 1; i < S.size(); ++i) {
            if(S[i] == '(') l++;
            if(S[i] == ')') r++;
            if(l != r) str.push_back(S[i]);
            else {
                l = 1, r = 0, ++i;
            }
        }
        return str;
    }
};