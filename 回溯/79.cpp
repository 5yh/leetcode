class Solution
{
    // 写爆了，重来
public:
    int x1[4] = {0, 1, 0, -1};
    int y1[4] = {1, 0, -1, 0};
    bool find = false;
    vector<vector<bool>> vis;
    void dfs(int xx, int yy, string word, vector<vector<char>> &board)
    {
        std::cout << xx << ' ' << yy << std::endl;
        std::cout << word << std::endl;
        std::cout << word.size() << std::endl;
        if (word.size() == 1 && board[xx][yy] == word[0])
        {
            find = true;
            return;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                // std::cout << "enter for\n";
                // std::cout << board.size() << ' ' << board[0].size() << std::endl;
                // std::cout << xx + x1[i] << ' ' << yy + y1[i] << std::endl;
                if (vis[xx + x1[i]][yy + y1[i]])
                    continue;
                if ((xx + x1[i] >= 0) && (xx + x1[i] < board.size()) && (yy + y1[i] >= 0) && (yy + y1[i] < board[0].size()))
                    if (word[0] == board[xx][yy])
                    {
                        vis[xx + x1[i]][yy + y1[i]] = true;
                        dfs(xx + x1[i], yy + y1[i], word.substr(1), board);
                        vis[xx + x1[i]][yy + y1[i]] = false;
                    }
            }
        }
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();
        vis.resize(rows, vector<bool>(cols, false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                vis[i][j] = true;
                dfs(i, j, word, board);
                vis[i][j] = false;
            }
        }

        return find;
    }
};