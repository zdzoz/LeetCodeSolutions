from typing import List
from unittest import TestCase
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        numCoins = 0
        for c in reversed(sorted(coins)):
            while amount > 0:
                if amount - c < 0:
                    break
                amount -= c
                numCoins += 1

        return numCoins if amount == 0 else -1


class TestSolution(TestCase):
    def test_case1(self):
        self.assertEqual(3, Solution().coinChange([1,2,5], 11))

    def test_case2(self):
        self.assertEqual(-1, Solution().coinChange([2], 3))

    def test_case3(self):
        self.assertEqual(0, Solution().coinChange([1], 0))

    def test_case4(self):
        self.assertEqual(4, Solution().coinChange([2,5,10,1], 27))

    def test_case5(self):
        self.assertEqual(5, Solution().coinChange([2, 5], 13))

    def test_case6(self):
        self.assertEqual(20, Solution().coinChange([186,419,83,408], 6249))
