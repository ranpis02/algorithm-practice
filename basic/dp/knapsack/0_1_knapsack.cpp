#include <iostream>
#include <vector>

using namespace std;

/**
 * Question: 0-1 knapsack
 *
 *  +-----------+-----------+-----------+
 *  |           |  weight   |   value   |
 *  +-----------+-----------+-----------+
 *  |  object1  |     w1    |     v1    |
 *  |  object2  |     w2    |     v2    |
 *  |  object3  |     w3    |     v3    |
 *  +-----------+-----------+-----------+
 *
 * dp[i][j]: represent the maximum you can array from the first `i` items, assuming the knapsack has a current capacity limit of `j`.
 * - i: item index, represents the scope of items being considered.
 * - j: capacity index, represents the varying capacity of the knapsack.
 *
 */

/**
 * Goal 1: What is the maximum total value you can carry in the knapsack without exceeding its capacity?
 */
int knapsackStandard(const vector<int> &weights, const vector<int> &values, int capacity)
{
  int n = weights.size();

  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

  // Initalize the first line(explicitly declare)
  for (int j = 0; j <= capacity; j++)
  {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= n; i++)
  {
    int w = weights[i - 1];
    int v = values[i - 1];

    for (int j = 0; j <= capacity; j++)
    {
      if (j < w)
      {
        dp[i][j] = dp[i - 1][j];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
      }
    }

    return dp[n][capacity];
  }
}
/**
 * Goal 2: What is the maximum total value you can carry in the knapsack while filling it exactly to capacity?
 */
int knapsackExact(const vector<int> &weights, const vector<int> &values, int capacity)
{
  int n = weights.size();
  constexpr int INT_NEG = -0x3f3f3f3f;

  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, INT_NEG));

  dp[0][0] = 0;

  for (int i = 1; i <= n; i++)
  {
    int w = weights[i - 1];
    int v = values[i - 1];

    for (int j = 0; j <= capacity; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j >= w)
      {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
      }
    }
  }

  if (dp[n][capacity] < 0)
    return -1;

  return dp[n][capacity];
}

/**
 * Goal 3: Apply the rolling array to reduce space usage.
 */
int kanpsackStandardWithRollingArray(const vector<int> &weights, const vector<int> &values, int capacity)
{
  vector<int> dp(capacity + 1, 0);

  for (int i = 0; i < weights.size(); i++)
  {
    int w = weights[i], v = values[i];
    // Iterate backwards to ensure we use values from the previous round, avoiding data pollution from the current round.
    for (int j = capacity; j >= 0; j--)
    {
      if (j >= w)
        dp[j] = max(dp[j], dp[j - w] + v);
    }
  }

  return dp[capacity];
}

int main()
{

  return 0;
}