class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        end = len(moves)
        
        for start, candidate_winner in ((0, "A"), (1, "B")):
            for i in range(start, end, 2):
                x1, y1 = moves[i]
                
                for j in range(i + 2, end, 2):
                    x2, y2 = moves[j]
                    
                    for k in range(j + 2, end, 2):
                        x3, y3 = moves[k]

                        if (x1 - x2) * (y1 - y3) == (x1 - x3) * (y1 - y2):
                            return candidate_winner
                            
        return "Draw" if end == 9 else "Pending"