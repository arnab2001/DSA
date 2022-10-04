class Solution:
    def MissingNumber(self,array,n):
        self.l = array
        self.l.sort()
        val , res = 1 , 0
        for i in self.l:
            if i != val:
                res = val
                break
            val += 1
        if res == 0: return i+1
        else: return res