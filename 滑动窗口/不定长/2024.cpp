class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        inr n = answerKey.size();
        int cntt = 0, cntf = 0;
        int ans = 0;
        int l = 0;
        // t变f，统计t出现的次数
        for (int r = 0; r < n; r++)
        {
            if (answerKey[r] == 'T')
            {
                cntt++;
                while (cntt > k)
                {
                    if (answerKey[l] == 'T')
                    {
                        cntt--;
                    }
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
        }
        // f变t，统计f
        l = 0;
        for (int r = 0; r < n; r++)
        {
            if (answerKey[r] == 'F')
            {
                cntf++;
                while (cntf > k)
                {
                    if (answerKey[l] == 'F')
                    {
                        cntf--;
                    }
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};