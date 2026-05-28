#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class RandomizedSet
{
public:
  RandomizedSet()
  {
  }

  bool insert(int val)
  {
    if (mp.count(val))
      return false;

    nums.push_back(val);
    int idx = nums.size() - 1;
    mp[val] = idx;

    return true;
  }

  bool remove(int val)
  {
    if (!mp.count(val))
      return false;
    int targetIdx = mp[val];

    nums[targetIdx] = nums.back();
    mp[nums.back()] = targetIdx;

    nums.pop_back();
    mp.erase(val);

    return true;
  }

  int getRandom()
  {
    return nums[rand() % nums.size()];
  }

private:
  unordered_map<int, int> mp;
  vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{

  return 0;
}