/*
在C++中，因为没有split和trim这种好用的字符串处理函数，遇到这种问题我们可以使用stringsteam
*/

class Solution {
public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s) {
        stringstream ss;
        string ans = "", tmp;
        ss << s;
        while(ss >> tmp) {
            ans = " " + tmp + ans;
        }
        if(ans.size()) 
            ans.erase(ans.begin());
        return ans;
    }
};