class RandomizedSet
{
public:
    unordered_set<int> a1;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (a1.find(val) != a1.end())
        {
            return false;
        }
        else
        {
            a1.insert(val);
        }
        return true;
    }

    bool remove(int val)
    {
        if (a1.find(val) != a1.end())
        {
            a1.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        auto it = a1.begin();
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */