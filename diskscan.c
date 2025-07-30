#include <stdio.h>
#include <stdlib.h>

void sort(int r, int request[r])
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = i + 1; j < r; j++)
        {
            if (request[i] > request[j])
            {
                int temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }
}

void scan(int r, int hs, int size, int direction, int request[r])
{
    sort(r, request);
    int seektime = 0;
    int current = hs;
    int index = 0;

 
    while (index < r && request[index] < hs)
    {
        index++;
    }

    printf("Seek sequence: %d", current); 

    if (direction == 1)
    {
        for (int i = index; i < r; i++)
        {
            seektime += abs(current - request[i]);
            current = request[i];
            printf(" -> %d", current);
        }
        if (current != size - 1)
        {
            seektime += abs(current - (size - 1));
            current = size - 1;
            printf(" -> %d", current);
        }
        for (int i = index - 1; i >= 0; i--)
        {
            seektime += abs(current - request[i]);
            current = request[i];
            printf(" -> %d", current);
        }
    }
    else 
    {
        for (int i = index - 1; i >= 0; i--)
        {
            seektime += abs(current - request[i]);
            current = request[i];
            printf(" -> %d", current);
        }
        if (current != 0)
        {
            seektime += abs(current - 0);
            current = 0;
            printf(" -> %d", current);
        }
        for (int i = index; i < r; i++)
        {
            seektime += abs(current - request[i]);
            current = request[i];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal seek time is: %d\n", seektime);
}

int main()
{
    int r, hs, size, direction;
    printf("Enter number of requests: ");
    scanf("%d", &r);

    int request[r];
    printf("Enter requests: ");
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter head start value: ");
    scanf("%d", &hs);

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter direction (1 for right, 0 for left): ");
    scanf("%d", &direction);

    scan(r, hs, size, direction, request);

    return 0;
}
