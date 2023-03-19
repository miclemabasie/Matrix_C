#include <stdio.h>
#include <stdlib.h>
void create(int **arr, int size);

int main()
{
    int size = 3;
    // Dynamically create an array of pointers of size (size)
    int **arr = (int **)malloc(size * sizeof(int *));
    
    for (int r = 0; r < size; r++)
    {
        arr[r] = (int *)malloc(size * sizeof(int));
    }
    create(arr, size);

    for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    return 0;
}

void create(int **arr, int size)
    {
        int value;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                printf("Enter value at matrix[%d][%d]: ", i, j);
                // scanf("%i", &value);
                scanf("%i", &arr[i][j]);
                // arr[i][j] = value;

            }
        }
    }