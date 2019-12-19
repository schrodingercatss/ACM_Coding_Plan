/*
	思路：切比雪夫距离，两点间的距离为max(abs(x1-x2), abs(y1-y2)).
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int dis = 0;
        for(int i = 0; i < points.size() - 1; ++i) {
            dis += max(abs(points[i][0] - points[i + 1][0]), abs(points[i][1] - points[i + 1][1]));
        }
        return dis;
    }
};