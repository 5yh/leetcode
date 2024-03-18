class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // 先找到中心点
        for (int i = 0; i < matrix.size() / 2; i++)
        {
            for (int j = 0; j < (matrix.size() + 1) / 2; j++)
            {

                int tmp = matrix[i][j];
                matrix[i][j] = matrix[matrix.size() - 1 - j][i];
                matrix[matrix.size() - 1 - j][i] = matrix[matrix.size() - 1 - i][matrix.size() - 1 - j];
                matrix[matrix.size() - 1 - i][matrix.size() - 1 - j] = matrix[j][matrix.size() - 1 - i];
                matrix[j][matrix.size() - 1 - i] = tmp;
            }
        }
    }
};