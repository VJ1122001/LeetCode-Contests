from collections import defaultdict
class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        s= set()
        mp= defaultdict(int)
        n= len(grid)
        for i in range(n):
            for j in range(n):
                s.add(grid[i][j])
                mp[grid[i][j]]+=1
        
        missing =-1
        twice= -1
        for i in range (1,(n*n)+1):
            if i not in s:
                missing = i
            if mp[i] == 2:
                twice = i
                
        return [twice, missing]
                
        