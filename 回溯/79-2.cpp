class Solution
{
public:
    int shuzux[4] = {0, 1, 0, -1};
    int shuzuy[4] = {-1, 0, 1, 0};
    bool check(vector<vector<char>> &board, vector<vector<bool>> &vis, int xx, int yy, int kk, string word)
    {
        // return true;
        if (board[xx][yy] != word[kk])
        {
            return false;
        }
        else if (kk == word.size() - 1)
        {
            return true;
        }
        vis[xx][yy] = true;
        bool result = false;
        for (int i = 0; i < 4; i++)
        {
            int newx = xx + shuzux[i];
            int newy = yy + shuzuy[i];
            if (newx >= 0 && newx < board.size() && newy >= 0 && newy < board[0].size())
            {
                if (!vis[newx][newy])
                {
                    if (check(board, vis, newx, newy, kk + 1, word))
                    {
                        result = true;
                        break;
                    };
                }
            }
        }
        vis[xx][yy] = false;
        return result;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> vis;
        vis.resize(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (check(board, vis, i, j, 0, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};