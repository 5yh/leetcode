class RandomizedSet
{
public:
    vector<int> nums;
    unordered_map<int, int> indices;
    RandomizedSet()
    {
        srand((unsigned)time(NULL));
    }

    bool insert(int val)
    {
        if (indices.count(val))
        {
            return false;
        }
        int index = nums.size();
        nums.emplace_back(val);
        indices[val] = index;
        return true;
    }

    bool remove(int val)
    {
        if (!indices.count(val))
        {
            return false;
        }
        int last = nums.back();
        int index = indices[val];
        nums[index] = last;
        indices[last] = index;
        nums.pop_back();
        indices.erase(val);
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */