#pragma once
#include <vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        size_t index = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[index++] = nums[i];
            }
        }

        for (size_t i = index; i < nums.size(); ++i)
        {
            nums[i] = 0;
        }
    }
};

class Solution2
{
public:
    void moveZeroes(vector<int>& nums)
    {
        size_t index = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                std::swap(nums[index++], nums[i]);
            }
        }
    }
};

void test1()
{
    vector<int> v = { 1123,0,3,4,2,1,0,2,4,0,3,4,0,4,2,3 };
    Solution().moveZeroes(v);
    for (auto e : v)
    {
        cout << e << "";
    }
}