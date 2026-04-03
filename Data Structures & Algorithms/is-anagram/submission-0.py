class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        x = set(s)
        if len(s) != len(t): return False
        for i in x:
            if s.count(i) != t.count(i):
                return False

        return True