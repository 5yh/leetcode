class RangeFreqQuery
{
public:
    // 存下标
    unordered_map<int, vector<int>> pos;
    // pos[i]是一个vectorint
    RangeFreqQuery(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            pos[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value)
    {
        // 不推荐写 a = pos[value]，如果 value 不在 pos 中会插入 value
        // int aa = lower_bound(pos[value].begin(), pos[value].end(), left) - pos[value].begin();
        // int bb = upper_bound(pos[value].begin(), pos[value].end(), right) - pos[value].begin();
        // // cout << aa << ' ' << bb << endl;
        // return bb - aa;
        auto it = pos.find(value);
        if (it == pos.end())
        {
            // 不存在
            return 0;
        }
        auto &a = it->second;
        return ranges::upper_bound(a, right) - ranges::lower_bound(a, left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */