/*
使用二分查找第一个大于等于该值的位置即可，下面使用了c++的lower_bound函数。

*/

class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &A, int target) {
        return lower_bound(A.begin(), A.end(), target) - A.begin();
    }
};