// LeetCode 525 : Contiguous Array

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMaxLength(vector<int> &nums)
{
  // we can use a trick by coverting question to max len subarray with sum=0 by replacing 0 to -1
  int n = nums.size();
  int len = 0;
  unordered_map<int, int> prefixIndex;
  // handle edge case for initial sum = 0 at index -1
  int prefixSum = 0;
  prefixIndex[prefixSum] = -1;

  for (int i = 0; i < n; i++)
  {
    nums[i] = nums[i] ? 1 : -1;
    prefixSum += nums[i];

    if (prefixIndex.find(prefixSum) != prefixIndex.end())
    {
      len = max(len, i - prefixIndex[prefixSum]);
    }
    else
    {
      prefixIndex[prefixSum] = i;
    }
  }

  return len;
}

int main()
{
  vector<int> nums = {0, 1, 1, 1, 1, 1, 0, 0, 0};
  cout << "Input Array: ";
  // Print the input array
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " ";
  }
  cout << endl;

  int maxLength = findMaxLength(nums);
  cout << "Maximum Length of Contiguous Subarray with Equal Number of 0s and 1s: " << maxLength << endl; // Output: 6
  return 0;
}