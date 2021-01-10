/*
思路：
利用异或运算的特性，两次异或后仍为原数， a ^ x ^ x = a 
将数组遍历一遍即可
*/

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        int ans = 0;
        for(auto x: A) {
            ans ^= x;
        }
        return ans;
    }
};