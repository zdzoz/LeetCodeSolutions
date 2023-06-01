from typing import List
from unittest import TestCase
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        pass




class TestSolution(TestCase):
    sol = Solution()
    def test_case1(self):
        r = self.sol.canFinish(2, [[1, 0]])
        self.assertEqual(r, True)

    def test_case2(self):
        r = self.sol.canFinish(2, [[1,0],[0,1]])
        self.assertEqual(r, True)
