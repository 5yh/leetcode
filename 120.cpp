// 写的是贪心，不是dp
// 做不出来
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int ceng = triangle.size(); // 4
        cout << ceng << endl;
        int rtMin = 999999999;
        for (int i = 0; i < ceng; i++) // 最下面一行最左边一个开始 0 1 2 3
        {
            int minn = triangle[ceng - 1][i];     // 3 1
            cout << "minn begin" << minn << endl; // 1
            int benceng = i;
            cout << benceng << endl;            // 1
            for (int j = ceng - 2; j >= 0; j--) // 当前层的上一层
            {                                   // ceng 2,1,0
                if (benceng == 0)
                {
                    minn += triangle[j][0];
                }
                else if (benceng == j + 1)
                {
                    minn += triangle[j][benceng - 1];
                    benceng--;
                }
                else
                {
                    if (triangle[j][benceng] > triangle[j][benceng - 1])
                    {
                        minn += triangle[j][benceng - 1];
                        benceng--;
                    }
                    else
                    {
                        minn += triangle[j][benceng];
                    }
                }
            }
            cout << "this turn minn" << minn << endl;
            if (rtMin > minn)
                rtMin = minn;
        }
        return rtMin;
    }
};