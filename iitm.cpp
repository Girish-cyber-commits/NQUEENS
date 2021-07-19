//  https://leetcode.com/problems/n-queens/
// print all possible queens combination
vector<vector<string>> ans;
int n;

class Solution {


public:
    bool nowvalid(int col , int row , vector<string> matrix ) {

        matrix[row][col] = 'Q';
        for (int i = col - 1 ; i >= 0; --i) {
            if (matrix[row][i] == 'Q')return false;
        }

        bool b[25];
        memset(b, 0, 25);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 'Q') {
                    if (b[i + j])return false;
                    b[i + j] = 1;

                }

        memset(b, 0, 25);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 'Q') {
                    if (b[i + n - 1 - j])return false;
                    b[i + n - 1 - j] = 1;
                }

        return true;
    }



public:
    void solve(int col , vector<string>  & matrix ) {
        if (col == n) {
            ans.push_back(matrix);

        } // base case
        if (col < n)
            for (int row = 0; row < n; row++) {

                if (nowvalid(col, row , matrix  ) ) {
                    matrix[row][col] = 'Q';
                    solve(col + 1, matrix);
                    matrix[row][col] = '.';
                }

            }
        return;

    }


public:
    vector<vector<string>> solveNQueens(int a) {
        n = a;
        ans.clear();
        vector<string> matrix(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)matrix[i] += ".";
        solve(0 , matrix );
        return ans;
    }

};