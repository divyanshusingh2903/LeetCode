#include <vector>
using namespace std;

/*
The function merges the elements of nums1 and nums2 into a single sorted vector. It does this by
iterating through nums2 from right to left and comparing each element with the elements in nums1
from right to left. The larger element is placed at the end of nums1.

The function modifies nums1 in-place by overwriting its elements with the merged sorted sequence.
The final size of nums1 will be the sum of the original sizes of nums1 and nums2.
*/
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }
};