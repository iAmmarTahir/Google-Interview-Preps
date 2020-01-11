#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

int maxSum(vector<int> arr)
{
    int size = arr.size();
    int levels = floor(log2(size));
    int sum = 0;
    int index = 0;
    unordered_map<int, int> levelSum;
    for (int i = 0; i < levels; i++)
    {
        for (int j = 0; j < pow(2, i); j++)
        {
            sum += arr[index++];
        }
        levelSum[i] = sum;
        sum = 0;
    }
    while (index < size)
    {
        sum += arr[index++];
    }
    levelSum[levels] = sum;
    int max = 0;
    int maxLevel = 0;
    for (int k = 0; k <= levels; k++)
    {
        if (max < levelSum[k])
        {
            max = levelSum[k];
            maxLevel = k;
        }
    }
    return maxLevel + 1;
}

int main()
{
    vector<int> arr = {1, 3};
    cout << maxSum(arr);
    return 0;
}