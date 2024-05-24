class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> winwin, loselose;
        for (int i = 0; i < matches.size(); i++)
        {
            winwin[matches[i][0]]++;
            loselose[matches[i][1]]--;
        }
        vector<int> answer0;
        vector<int> answer1;
        for (auto &[k, v] : winwin)
        {
            if (v > 0 && loselose[k] == 0)
            {
                answer0.push_back(k);
            }
        }
        for (auto &[k, v] : loselose)
        {
            // cout << k << ' ' << v << endl;
            if (v == -1)
            {
                answer1.push_back(k);
            }
        }
        sort(answer0.begin(), answer0.end());
        sort(answer1.begin(), answer1.end());
        vector<vector<int>> ans;
        ans.push_back(answer0);
        ans.push_back(answer1);
        return ans;
    }
};