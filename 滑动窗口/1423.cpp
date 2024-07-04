class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        // 边上找最大等于中间找最小
        int all = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int len = cardPoints.size() - k;
        // cout<<len<<endl;
        int sum = 0;
        int minn = INT_MAX;
        for (int i = 0; i < len - 1; i++)
        {
            sum += cardPoints[i];
        }

        // cout<<sum;
        for (int i = len - 1; i < cardPoints.size(); i++)
        {
            sum += cardPoints[i];
            if (sum < minn)
            {
                minn = sum;
            }
            sum -= cardPoints[i - len + 1];
        }
        if (minn == INT_MAX)
        {
            return all;
        }
        return all - minn;
    }
};