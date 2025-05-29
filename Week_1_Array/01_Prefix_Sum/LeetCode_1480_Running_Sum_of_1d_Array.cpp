#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
  int sum = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    sum += nums[i];
    nums[i] = sum;
  }

  return nums;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4};
  cout << "Input Array: ";
  // Print the input array
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " ";
  }
  cout << endl;
  int sum = 0;
  nums = runningSum(nums);
  cout << "Running Sum: ";
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " ";
  }
  return 0;
}
