#include <stdio.h>
typedef struct ITEM
{
    int weight;
    int profit;
    float ratio;

} ITEM;

int main()
{
    ITEM item[100], temp;
    int n, capacity;
    printf("Enter the Number of Items = ");
    scanf("%d", &n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter Weight of %d Item = ", i + 1);
        scanf("%d", &item[i].weight);
        printf("Enter Profit of %d Item = ", i + 1);
        scanf("%d", &item[i].profit);
        item[i].ratio = (float)item[i].profit / item[i].weight;
        printf("\n");
    }
    printf("Enter Capacity Of Bag = ");
    scanf("%d", &capacity);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (item[i].ratio < item[j].ratio)
            {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
    float maxprofit = 0;
    for (int i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            maxprofit += item[i].profit;
            capacity -= item[i].weight;
        }
        else
        {
            maxprofit += item[i].ratio * capacity;
            break;
        }
    }
    printf("\nMaximum Profit = %.2f", maxprofit);
    return 0;
}