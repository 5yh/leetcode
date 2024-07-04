class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int cntt = 0;
        int minn = 0;
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'B')
            {
                cntt++;
            }
        }
        minn = k - cntt;
        for (int i = 1; i + k < blocks.size(); i++)
        {
            if (blocks[i - 1] == 'B')
            {
                cntt--;
            }
            if (blocks[i + k] == 'B')
            {
                cntt++;
            }
            if (k - cntt < minn)
            {
                minn = k - cntt;
            }
        }
        return minn;
    }
};