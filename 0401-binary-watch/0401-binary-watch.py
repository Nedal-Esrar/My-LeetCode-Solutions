class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        def bit_counter(n):
            return sum([1 for i in bin(n)[2:] if i == '1'])
        
        result = []
        
        for h in range(12):
            for m in range(60):
                if bit_counter(h) + bit_counter(m) == turnedOn:
                    result.append(f'{h}:{m:02}')
                    
        return result