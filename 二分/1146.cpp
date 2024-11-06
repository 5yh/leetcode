class SnapshotArray
{
public:
    unordered_map<int, vector<pair<int, int>>> cnt;
    int snapcnt = 0;
    SnapshotArray(int length)
    {
    }

    void set(int index, int val)
    {
        // pair<int, int> p = {snapcnt, val};
        cnt[index].emplace_back(snapcnt, val);
    }

    int snap()
    {
        return snapcnt++;
    }

    int get(int index, int snap_id)
    {
        // pair<int, int> p = {snap_id + 1, 0};
        auto &h = cnt[index];
        int aa = lower_bound(h.begin(), h.end(), make_pair(snap_id + 1, 0)) - h.begin() - 1;
        return aa >= 0 ? h[aa].second : 0;
    }
    // int get(int index, int snap_id)
    // {
    //     auto &h = cnt[index];
    //     // 找快照编号 <= snap_id 的最后一次修改记录
    //     // 等价于找快照编号 >= snap_id+1 的第一个修改记录，它的上一个就是答案
    //     int j = ranges::lower_bound(h, make_pair(snap_id + 1, 0)) - h.begin() - 1;
    //     return j >= 0 ? h[j].second : 0;
    // }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */