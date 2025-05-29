#include <iostream>
#include <vector>
#include <numeric> // For accumulate function
using namespace std;
int pivotIndex(vector<int> &nums)
{
  int totalSum = accumulate(nums.begin(), nums.end(), 0);
  // totalSum is leftSum[i] + rightSum[i](i.e.leftSum[i]) + nums[i];
  int leftsum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if ((2 * leftsum) + nums[i] == totalSum)
    {
      return i;
    }
    leftsum += nums[i];
  }
  return -1;
}

int main()
{
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  cout << "Input Array: ";
  // Print the input array
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " ";
  }
  int pivot = pivotIndex(nums);
  cout << "Pivot Index: " << pivot << endl; // Output: 3
  return 0;
}

