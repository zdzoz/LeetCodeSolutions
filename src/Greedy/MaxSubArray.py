from typing import List
from unittest import TestCase


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        res = nums[0]
        total = 0
        for n in nums:
            total += n
            res = max(res, total)
            if total < 0:
                total = 0

        return res


class TestSolution(TestCase):
    def test_case1(self):
        self.assertEqual(6, Solution().maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))

    def test_case2(self):
        self.assertEqual(1, Solution().maxSubArray([1]))

    def test_case3(self):
        self.assertEqual(23, Solution().maxSubArray([5, 4, -1, 7, 8]))

    def test_case4(self):
        self.assertEqual(-1, Solution().maxSubArray([-2, -1]))

    def test_case5(self):
        self.assertEqual(4, Solution().maxSubArray([-1, 1, 2, 1]))

    def test_case6(self):
        self.assertEqual(-1, Solution().maxSubArray([-2, -1, -2]))
