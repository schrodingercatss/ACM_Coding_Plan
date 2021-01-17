/*
	每次查找空格的位置，然后用replace函数替换就行了，C++没有java和python方便，需要边查询边替换
*/

class Solution {
public:
    string replaceSpace(string s) {
        int pos = -1;
        while((pos = s.find(" ")) != string::npos) {
            s.replace(pos, 1, "%20");
        }
        return s;
    }
};