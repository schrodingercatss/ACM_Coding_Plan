/*
有两个思路，一是使用map记录下数字对应的下标，直接查表就行，
二是使用二分查找，下面是第一种思路的代码。
*/

class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> mmp, mmp1;
        for(int i = 0; i < numbers.size(); i++) {
            mmp[numbers[i]] = i;
            mmp1[numbers[i]] = true;
        }
        for(int i = 0; i < numbers.size(); i++) {
            int tmp = target - numbers[i];
            if(mmp1[tmp]) {
                int p = mmp[tmp];
                return {min(p, i), max(p, i)};
            }
        }
    }
};