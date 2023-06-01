from typing import List
from unittest import TestCase

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        if len(cost) == 1: return cost[0]
        dp = [0] * len(cost)
        dp[0] = cost[0]
        dp[1] = cost[1]

        for i, _ in enumerate(cost[2:]):
            idx = i + 2
            c = cost[idx]
            dp[idx] = min(dp[idx - 1] + c, dp[idx - 2] + c)
        return min(dp[-2], dp[-1])

class TestSolution(TestCase):
    def test_case1(self):
        self.assertEqual(15, Solution().minCostClimbingStairs([10,15,20]))

    def test_case2(self):
        self.assertEqual(6, Solution().minCostClimbingStairs([1,100,1,1,1,100,1,1,100,1]))
