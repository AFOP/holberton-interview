def makeChange(coins, total):
    if total <= 0:
        return 0

    # Initialize a list to store the minimum number of coins needed for each total value from 1 to 'total'.
    # Initialize all values to be a large number to begin with.
    dp = [float('inf')] * (total + 1)
    
    # There is 0 number of coins needed to make a total of 0.
    dp[0] = 0

    # Iterate through each coin value and update the dp array.
    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    # If dp[total] is still 'inf', it means it's not possible to make the total with the given coins.
    # Otherwise, return the minimum number of coins needed for the total.
    return dp[total] if dp[total] != float('inf') else -1
