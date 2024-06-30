class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        s = str(x)
        reversed_s = s[::-1] if x >= 0 else '-' + s[:0:-1]
        reversed_int = int(reversed_s)

        if reversed_int > INT_MAX or reversed_int < INT_MIN:
            return 0

        return reversed_int