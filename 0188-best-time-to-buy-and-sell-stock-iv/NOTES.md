Recurrence relation:
1. Holding: dp[i][k][1] = max(SellStock, DoNothing)
2. NotHolding: dp[i][k][0] = max(BuyStock, DoNothing)
​
SellStock = prices[i] + dp[i+1][k-1][0]
BuyStock = -prices[i] + dp[i+1][k-1][1]
DoNohting: dp[i][k][holding] = dp[i+1][k+1][holding]