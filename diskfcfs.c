#include <stdio.h>
#include <stdlib.h>

void fcfs(int r, int st, int request[r])
{
    int seektime = 0;
    int parseek = 0;
    int current = st;

    printf("Seek sequence: %d", current); 

    for (int i = 0; i < r; i++)
    {
        parseek = abs(current - request[i]);
        seektime += parseek;
        current = request[i];
        printf(" -> %d", current); 
    }

    printf("\nTotal seek time is: %d\n", seektime);
}

int main()
{
    int r, st;

    printf("Enter number of requests: ");
    scanf("%d", &r);

    int request[r];

    printf("Enter requests: ");
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter starting head position: ");
    scanf("%d", &st);

    fcfs(r, st, request);

    return 0;
}
