/*
我们可以使用一个set记录之前出现的元素，用一个idx变量记录去重的长度，如果当前元素没有出现，则
加入到数组中，并且让idx++。
*/

class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        set<int> st;
        int idx = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(!st.count(nums[i])) {
                nums[idx++] = nums[i];
            }
            st.insert(nums[i]);
        }
        return idx;
    }
};