from typing import List
from unittest import TestCase


class Solution:
    def rob(self, nums: List[int]) -> int:
        rob0, rob1 = 0, 0

        for n in nums:
            t = max(rob0 + n, rob1)
            rob0 = rob1
            rob1 = t

        return rob1


class TestSolution(TestCase):
    def test_case1(self):
        self.assertEqual(4, Solution().rob([1, 2, 3, 1]))

    def test_case2(self):
        self.assertEqual(12, Solution().rob([2, 7, 9, 3, 1]))

    def test_case3(self):
        self.assertEqual(3, Solution().rob([1, 2, 2, 1]))

    def test_case4(self):
        self.assertEqual(3365, Solution().rob([183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211]))
