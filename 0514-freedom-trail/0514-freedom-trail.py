class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        memo = {}

        positions = defaultdict(list)

        for i, c in enumerate(ring):
            positions[c].append(i)
        
        return self.solve(0, 0, positions, key, ring, memo)
    
    def solve(self, idx, pos, positions, key, ring, memo):
        if idx == len(key):
            return 0
        
        if (idx, pos) in memo:
            return memo[(idx, pos)]
        
        min_steps = float('inf')

        for i in positions[key[idx]]:
            if i >= pos:
                steps = min(i - pos, pos + len(ring) - i)
            else:
                steps = min(pos - i, i + len(ring) - pos)
            
            min_steps = min(min_steps, steps + self.solve(idx + 1, i, positions, key, ring, memo))
        
        memo[(idx, pos)] = min_steps + 1
        
        return min_steps + 1
        