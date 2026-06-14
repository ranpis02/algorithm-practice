#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int n = nums.size();

    int left = 0, right = n - 1;
    int i = 0;

    while (i <= right)
    {
      if (nums[i] == 0)
      {
        swap(nums[i], nums[left]);
        i++;
        left++;
      }
      else if (nums[i] == 1)
      {
        i++;
      }
      else if (nums[i] == 2)
      {
        swap(nums[i], nums[right]);
        right--;
      }
    }
  }
};

int main()
{
  Solution *sol = new Solution();
  vector<int> nums = {2, 0, 1};
  sol->sortColors(nums);

  return 0;
}