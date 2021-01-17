/*
	因为二维数组每一行是有序的，我们每次遍历一行，然后对每一行进行二分查找即可。
*/


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for(auto &x: matrix) {
            if(binary_search(x.begin(), x.end(), target))
                return true;
        }
        return false;
    }
};