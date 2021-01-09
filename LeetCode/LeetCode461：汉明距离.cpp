// 解法一：异或+lowbit
class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x ^ y;
        int cnt = 0;
        while(t) {
            cnt++;
            t -= t & (-t);
        }
        return cnt;
    }
};

// 解法二：异或+bitset
class Solution {
public:
    int hammingDistance(int x, int y) {
        return bitset<32> (x ^ y).count();
    }
};