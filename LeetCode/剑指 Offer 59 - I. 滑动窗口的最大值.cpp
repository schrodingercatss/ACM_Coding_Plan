/*
	单调队列经典题目，维护一个双端队列，保持其队头永远是最大值的索引即可。
*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++) {
            while(dq.size() && nums[dq.back()] < nums[i]) dq.pop_back(); // 让新的最(次)大值能尽量靠近队头
            if(dq.size() && dq.front() < i - k + 1) dq.pop_front(); // 清除掉队头过期的索引
            dq.push_back(i);
            if(i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};