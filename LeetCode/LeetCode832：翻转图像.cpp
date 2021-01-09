class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m / 2; ++j) {
                A[i][j] ^= 1, A[i][m - j - 1] ^= 1;
                swap(A[i][j], A[i][m - j - 1]);
            }
            if(n & 1) A[i][m / 2 ] ^= 1;
        }
        return A;
    }
};