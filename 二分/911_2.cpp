class TopVotedCandidate
{
public:
    vector<pair<int, int>> advance;
    unordered_map<int, int> cnt;
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        int n = persons.size();
        advance = vector<pair<int, int>>(n);
        int votes = -1;
        int top = -1;
        for (int i = 0; i < n; i++)
        {
            cnt[persons[i]]++;
            if (cnt[persons[i]] >= votes)
            {
                votes = cnt[persons[i]];
                top = persons[i];
            }
            advance[i] = make_pair(times[i], top);
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << "advance " << i << ":" << advance[i].first << ' ' << advance[i].second << endl;
        // }
    }

    int q(int t)
    {
        int l = -1;
        int r = advance.size();
        while (l + 1 < r)
        {
            int m = (r - l) / 2 + l;
            if (advance[m].first == t)
            {
                return advance[m].second;
            }
            if (advance[m].first > t)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        return advance[r - 1].second;
        // if (r == advance.size())
        // {
        //     return
        // }
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */