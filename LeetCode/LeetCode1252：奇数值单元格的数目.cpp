/*
	思路，统计行和列上为奇数的情况，观察值，只有当行列为一奇一偶对应位置上的值才是奇数。
	最后运用排列组合，res = 行奇*列偶 + 行偶 * 列奇
	其中行偶 = n - 行奇， 列偶 = m - 列奇
*/

class Solution {
public:
    int row[105], col[105];
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        for(int i = 0; i < indices.size(); ++i) {
            ++row[indices[i][0]], ++col[indices[i][1]];
        }
        int odd_row = 0, odd_col = 0;
        for(int i = 0; i < n; ++i)
            if(row[i] & 1) ++odd_row;
        for(int i = 0; i < m; ++i)
            if(col[i] & 1) ++odd_col;
        return odd_row * (m - odd_col) + odd_col * (n - odd_row);
    }
};