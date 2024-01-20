/*!
    \file "main.cpp"

    Author: Matt Ervin <matt@impsoftware.org>
    Formatting: 4 spaces/tab (spaces only; no tabs), 120 columns.
    Doc-tool: Doxygen (http://www.doxygen.com/)

    https://leetcode.com/problems/two-sum/
*/

//!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/main.md
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"

/*
    Given an array of integers nums and an integer target, return indices of 
    the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you 
    may not use the same element twice.

    You can return the answer in any order.

    Constraints:

        2 <= nums.length <= 104
        -109 <= nums[i] <= 109
        -109 <= target <= 109
        Only one valid answer exists.
    
    Example 1:

        Input: nums = [2,7,11,15], target = 9
        Output: [0,1]
        Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    
    Example 2:

        Input: nums = [3,2,4], target = 6
        Output: [1,2]

    Example 3:

        Input: nums = [3,3], target = 6
        Output: [0,1]
*/

#define USE_BRUTE_FORCE
//#define USE_DIFF_TABLE

class Solution {
public:
#if defined(USE_BRUTE_FORCE)
    // Brute force: combination algorithm for choosing two from n.
    // Time: O(n^2/2) => O(n^2)
    // Space: O(1)
    vector<int> twoSum(vector<int> const& nums, int const target) {
        if (2 <= nums.size()) {
            // Explore every choose(nums, 2) combination
            // and see if the values sum to target.
            for (int oidx = 0; nums.size() - 1 > oidx; ++oidx) {
                for (auto iidx = oidx + 1; nums.size() > iidx; ++iidx) {
                    if (target == nums[oidx] + nums[iidx]) {
                        return vector<int>{oidx, iidx};
                    }
                }
            }
        }
        return vector<int>{};
    }
#endif // #if defined(USE_BRUTE_FORCE)

#if defined(USE_DIFF_TABLE)
    // Hash table of differences:
    // Time: O(2n) => O(n)
    // Space: O(n)
    vector<int> twoSum(vector<int> const& nums, int const target) {
        unordered_map<int, int> diff_table{};
        
        for (int idx = 0; nums.size() > idx; ++idx) {
            diff_table[target - nums[idx]] = idx;
        }
        
        for (int idx = 0; nums.size() > idx; ++idx) {
            auto const iter = diff_table.find(nums[idx]);
            auto const found = diff_table.end() != iter && iter->second != idx;
            if (found) {
                return vector<int>{idx, iter->second};
            }
        }
        
        return vector<int>{};
    }
#endif // #if defined(USE_DIFF_TABLE)
};

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

TEST_CASE("Case 1")
{
    cerr << "Case 1" << '\n';
    { // New scope.
        auto nums = vector<int>{2,7,11,15};
        auto const target = 9;
        auto const expected = vector<int>{0,1};
        auto result = Solution{}.twoSum(nums, target);
        if (2 <= result.size() && result[1] < result[0]) {
            swap(result[0], result[1]);
        }
        CHECK(expected == result);
        auto const start = std::chrono::steady_clock::now();
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 2")
{
    cerr << "Case 2" << '\n';
    { // New scope.
        auto nums = vector<int>{3,2,4};
        auto const target = 6;
        auto const expected = vector<int>{1,2};
        auto result = Solution{}.twoSum(nums, target);
        if (2 <= result.size() && result[1] < result[0]) {
            swap(result[0], result[1]);
        }
        CHECK(expected == result);
        auto const start = std::chrono::steady_clock::now();
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 3")
{
    cerr << "Case 3" << '\n';
    { // New scope.
        auto nums = vector<int>{3,3};
        auto const target = 6;
        auto const expected = vector<int>{0,1};
        auto result = Solution{}.twoSum(nums, target);
        if (2 <= result.size() && result[1] < result[0]) {
            swap(result[0], result[1]);
        }
        CHECK(expected == result);
        auto const start = std::chrono::steady_clock::now();
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

/*
    End of "main.cpp"
*/
