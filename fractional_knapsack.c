#include <stdio.h>

int n, i, j, m, t;
int p[100], w[100], id[100];
float r[100];
float maxprofit = 0;
float selected[100];
int calculated = 0;

void input();
void display();
void ratio();
void sort();
void profit();
void select();

int main()
{
    int ch;

    do
    {
        printf("\n\n--- MENU ---");
        printf("\n1. Enter package details");
        printf("\n2. Display package details");
        printf("\n3. Calculate value/weight ratio");
        printf("\n4. Sort packages by ratio");
        printf("\n5. Find maximum profit");
        printf("\n6. Display selected packages");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                input();
                break;

            case 2:
                display();
                break;

            case 3:
                ratio();
                break;

            case 4:
                sort();
                break;

            case 5:
                profit();
                break;

            case 6:
                select();
                break;

            case 7:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while(ch != 7);

    return 0;
}

void input()
{
    printf("\nEnter number of packages: ");
    scanf("%d", &n);

    if(n <= 0 || n > 100)
    {
        printf("Invalid number of packages!");
        n = 0;
        return;
    }

    printf("Enter profit of each package:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
        id[i] = i + 1;
    }

    printf("Enter weight of each package:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);

        if(w[i] <= 0)
        {
            printf("Weight must be positive!");
            n = 0;
            return;
        }
    }

    printf("Enter maximum capacity of vehicle: ");
    scanf("%d", &m);

    if(m < 0)
    {
        printf("Capacity cannot be negative!");
        n = 0;
        return;
    }

    calculated = 0;
    maxprofit = 0;

    for(i = 0; i < n; i++)
    {
        r[i] = 0;
        selected[i] = 0;
    }

    printf("Package details entered successfully.");
}

void display()
{
    if(n == 0)
    {
        printf("\nEnter package details first!");
        return;
    }

    printf("\nPackage\tProfit\tWeight\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", id[i], p[i], w[i]);
    }

    printf("Maximum capacity: %d\n", m);
}

void ratio()
{
    if(n == 0)
    {
        printf("\nEnter package details first!");
        return;
    }

    for(i = 0; i < n; i++)
    {
        r[i] = (float)p[i] / w[i];
    }

    printf("\nPackage\tRatio\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%.2f\n", id[i], r[i]);
    }

    calculated = 0;
}

void sort()
{
    float tempR;
    int tempP, tempW, tempID;

    if(n == 0)
    {
        printf("\nEnter package details first!");
        return;
    }

    for(i = 0; i < n; i++)
    {
        r[i] = (float)p[i] / w[i];
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(r[j] < r[j + 1])
            {
                tempR = r[j];
                r[j] = r[j + 1];
                r[j + 1] = tempR;

                tempP = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempP;

                tempW = w[j];
                w[j] = w[j + 1];
                w[j + 1] = tempW;

                tempID = id[j];
                id[j] = id[j + 1];
                id[j + 1] = tempID;
            }
        }
    }

    calculated = 0;

    printf("\nPackages sorted by decreasing ratio:\n");
    printf("Package\tProfit\tWeight\tRatio\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%.2f\n",
               id[i], p[i], w[i], r[i]);
    }
}

void profit()
{
    int capacity;

    if(n == 0)
    {
        printf("\nEnter package details first!");
        return;
    }

    sort();

    capacity = m;
    maxprofit = 0;

    for(i = 0; i < n; i++)
    {
        selected[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        if(capacity == 0)
            break;

        if(w[i] <= capacity)
        {
            selected[i] = 1.0;
            maxprofit += p[i];
            capacity -= w[i];
        }
        else
        {
            selected[i] = (float)capacity / w[i];
            maxprofit += p[i] * selected[i];
            capacity = 0;
        }
    }

    calculated = 1;

    printf("\nMaximum profit = %.2f\n", maxprofit);
    printf("Total weight used = %d\n", m - capacity);
}

void select()
{
    if(n == 0)
    {
        printf("\nEnter package details first!");
        return;
    }

    if(!calculated)
    {
        printf("\nPlease find maximum profit first using option 5!");
        return;
    }

    printf("\nSelected packages:\n");
    printf("Package\tProfit\tWeight\tRatio\tFraction\n");

    for(i = 0; i < n; i++)
    {
        if(selected[i] > 0)
        {
            printf("%d\t%d\t%d\t%.2f\t%.2f\n",
                   id[i], p[i], w[i], r[i], selected[i]);
        }
    }

    printf("\nTotal weight used: %d\n", m);
    printf("Maximum profit: %.2f\n", maxprofit);
}
