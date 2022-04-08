#include <cstddef>
#include <iostream>
#include <string.h>
#include <vector>
#include <array>

// using namespace std;

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> nums = nums1;
        nums.insert(nums.end(), nums2.begin(), nums2.end());
        std::sort(nums.begin(), nums.end());
        size_t l = nums.size();
        if (l % 2 == 0) {
            return (static_cast<double>(nums[l/2]) + static_cast<double>(nums[l/2 - 1])) / 2;
        } else {
            int ll = l/2;
            return static_cast<double>(nums[ll]);
        }
    }
};

int main() {
    Solution s;
    std::vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(3);
    v2.push_back(2);
    v2.push_back(4);
    std::cout << s.findMedianSortedArrays(v1, v2) << std::endl;
    return 0;
}


    /*     size_t l = nums1.size() + nums2.size(); */
    /*     double nums [l]; */
    /*     int i = 0; */
    /*     int j = 0; */
    /*     while (i + j < l) { */
    /*         if (nums1[i] < nums2[j]) { // indices may be out of bounds then this comparison fails */
    /*             nums[i + j] = nums1[i]; */
    /*             i++; */
    /*         } else { */
    /*             nums[i + j] = nums2[j]; */
    /*             j++; */
    /*         } */
    /*     } */
    /*     for (auto& k : nums) { */
    /*         std::cout << k << std::endl; */
    /*     } */
    /*     if (l % 2 == 0) { */
    /*         int k = l / 2; */
    /*         return (nums[k] + nums[k - 1]) / 2; */
    /*     } else { */
    /*         int k = l / 2 + 1; */
    /*         return nums[k]; */
    /*     } */
    /* } */
