class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        unordered_map<char, int> distance;
        int cur_dis = 0;
        int cntzong = 0;
        for (int i = 0; i < garbage.size(); i++)
        {
            if (i > 0)
            {
                cur_dis += travel[i - 1];
            }
            cntzong += garbage[i].length();
            for (int j = 0; j < garbage[i].length(); j++)
            {
                distance[garbage[i][j]] = cur_dis;
            }
            // for (auto c : garbage[i])
            // {
            //     distance[c]=cur_dis;
            // }
        }
        for (auto &[k, v] : distance)
        {
            cntzong += v;
        }
        return cntzong;
    }
};