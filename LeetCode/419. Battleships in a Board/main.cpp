#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X') {
                        continue;
                    }
                    if (j > 0 && board[i][j - 1] == 'X') {
                        continue;
                    }
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<char>> board = {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}};
    Solution s;
    cout << s.countBattleships(board) << endl;
    return 0;
}
