class Solution
{
public:
    long long numberOfWeeks(vector<int> &milestones)
    {
        int n = milestones.size();
        int maxxi = 0;
        long long cntzong = 0;
        for (int i = 0; i < n; i++)
        {
            if (milestones[i] > milestones[maxxi])
            {
                maxxi = i;
            }
            cntzong += milestones[i];
        }
        if (milestones[maxxi] <= cntzong - milestones[maxxi] + 1)
        {
            return cntzong;
        }
        else
        {
            return (cntzong - milestones[maxxi]) * 2 + 1;
        }
    }
};