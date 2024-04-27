public class Solution {
    public int MaxProfit(int[] prices)  {
        var buy1 = int.MaxValue;
        var buy2 = int.MaxValue;
        
        var sell1 = 0;
        var sell2 = 0;
        
        foreach (var price in prices) {
            buy1 = Math.Min(buy1, price);
            sell1 = Math.Max(sell1, price - buy1);
            buy2 = Math.Min(buy2, price - sell1);
            sell2 = Math.Max(sell2, price - buy2);
        }

        return sell2;
    }
}