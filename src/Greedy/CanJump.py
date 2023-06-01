from typing import List
from unittest import TestCase


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        goal = len(nums) - 1

        for i, n in enumerate(reversed(nums[:-1])):
            l = len(nums) - 2 - i
            if l + n >= goal: goal = l

        return goal == 0


class TestSolution(TestCase):
    def test_case1(self):
        self.assertEqual(True, Solution().canJump([2, 3, 1, 1, 4]))

    def test_case2(self):
        self.assertEqual(False, Solution().canJump([3, 2, 1, 0, 4]))

    def test_case3(self):
        self.assertEqual(True, Solution().canJump([2, 0, 0]))

    def test_case4(self):
        self.assertEqual(True, Solution().canJump([2,5,0,0]))
