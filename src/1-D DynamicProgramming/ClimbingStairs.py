from unittest import TestCase


class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 3: return n
        dp = [0] * n
        dp[0] = 1
        dp[1] = 2

        for i in range(2, n):
            dp[i] = dp[i - 2] + dp[i - 1]
        return dp[n - 1]


class TestSolution(TestCase):
    def test_case1(self):
        self.assertEqual(2, Solution().climbStairs(2))

    def test_case2(self):
        self.assertEqual(3, Solution().climbStairs(3))

    def test_case3(self):
        self.assertEqual(5, Solution().climbStairs(4))


    def test_case3(self):
        self.assertEqual(8, Solution().climbStairs(5))
