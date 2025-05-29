// LeetCode 560 : Subarray Sum Equals K

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
  unordered_map<int, int> hash;
  hash[0] = 1;
  int prefixSum = 0;
  int n = nums.size();
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    prefixSum += nums[i];
    if (hash[prefixSum - k] > 0)
    {
      count += hash[prefixSum - k];
    }
    hash[prefixSum]++;
  }
  return count;
}

int main()
{
  vector<int> nums = {1, 2, 3};
  int k = 3;
  cout << "Input Array: ";
  // Print the input array
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " ";
  }
  cout << endl;

  int result = subarraySum(nums, k);
  cout << "Number of subarrays with sum equal to " << k << ": " << result << endl; // Output: 2
  return 0;
}