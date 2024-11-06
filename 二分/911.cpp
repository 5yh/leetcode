class TopVotedCandidate
{
public:
    unordered_map<int, vector<int>> aa;
    unordered_map<int> bb;
    int n = 0;
    int mmax = 0;
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        maxx = ranges::max(times);
        n = persons.size();
        for (int i = 0; i < n; i++)
        {
            aa[persons[i]].push_back(times[i]);
        }
    }
    // 超时了
    int q(int t)
    {
        int big = 0;
        int bigren = 0;
        int cntmax = 0;
        int cntmaxren = 0;

        for (int i = 0; i < n; i++)
        {
            // <的
            int lb = lower_bound(aa[i].begin(), aa[i].end(), t + 1) - aa[i].begin() - 1;

            if (lb >= 0)
            {
                if (lb == big)
                {

                    if (aa[i][lb] >= cntmax)
                    {
                        cntmax = aa[i][lb];
                        bigren = i;
                    }
                }
                else if (lb > big)
                {

                    big = lb;
                    bigren = i;
                    cntmax = aa[i][lb];
                }
            }
        }
        return bigren;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */