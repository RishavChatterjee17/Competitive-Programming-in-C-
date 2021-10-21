#include<iostream>
using namespace std;

static int MinimumCost(string input)
{
    int cost = 0;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'b')
        {
            if (i == 0)
            {
                cost += 1;
                if (input.length() >= 1)
                {
                    input = input.substr(1);
                }
            }
            else if (i == 1)
            {
                cost += 2;
                if (input.length() >= 2)
                {
                    input = input.substr(2);
                }
            }
            else
            {
                cost += 2;
                input = input.substr(0, i) + input.substr(i + 1);
            }
            i = -1;
        }
    }

    return cost;
}

static int MinimumCostOfRemoval(string input)
{
    int forwardCost = MinimumCost(input.substr(0, input.length() / 2));
    int backwardCost = MinimumCost(reverse(input.substr(input.length() / 2).begin(), input.end()));
    return forwardCost + backwardCost;
}

int main()
{
    string s = "aabbaabbaa";

    cout << MinimumCostOfRemoval(s);

    return 0;
}
