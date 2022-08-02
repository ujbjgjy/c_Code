#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned int)time(NULL));
    printf("You have five chances\n");
    printf("Input1-100");
    
    int tmp = rand() % 100 + 1;
    int i = 5;

    while (i--)
    {
        int sum = 0;
        //printf("\ntmp=%d\n", tmp);
        printf("==>");
        scanf("%d", &sum);
        if (sum < tmp)
        {
     
            printf("number:%d\n", i);
            printf("%d < ? \n", sum);;
        }
        else if (sum > tmp)
        {
            
            printf("number:%d\n", i);
            printf("%d > ?\n", sum);;
        }
        else
        {
            printf("Challenge success!\n");
            return 0;
        }
    }
    printf("Challenge failure!\n");
    printf("This number is:%d\n", tmp);
    system("pause");
    return 0;
}