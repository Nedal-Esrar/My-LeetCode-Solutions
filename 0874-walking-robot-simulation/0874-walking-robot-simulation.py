class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obs = set(map(tuple, obstacles))
        
        x, y = 0, 0
        
        dx, dy = 0, 1
        
        ans = 0

        for c in commands:
            if c == -1:
                dx, dy = dy, -dx
            elif c == -2:
                dx, dy = -dy, dx
            else:
                for _ in range(c):
                    nx, ny = x + dx, y + dy
                    
                    if (nx, ny) in obs: 
                        break
                    
                    x, y = nx, ny
                    
                    ans = max(ans, x ** 2 + y ** 2)
        
        return ans