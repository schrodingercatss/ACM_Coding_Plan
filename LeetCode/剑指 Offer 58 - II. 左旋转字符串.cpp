/*
	先将前k个字符逆置，再将后n - k个字符逆置，再将整个字符串逆置，即可得到答案。
*/



class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
