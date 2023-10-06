#include <stdio.h>

void bubbleSort(int a[], int size) 
{
  for (int j = 0; j < size - 1; ++j) 
  {
    for (int i = 0; i < size - j-1; ++i) 
    {
      if (a[i] > a[i + 1]) 
      {
        int t = a[i];
        a[i] = a[i + 1];
        a[i + 1] = t;
      }
    }
  }
}

int main()
{
    int row, column, el;
    int number_of_elements;

    printf("Input number of rows and columns: ");
    scanf("%d%d", &row, &column);
    number_of_elements = row*column;
    
    int matrix[row][column];
    int array[number_of_elements];

    printf("Input the matrix: ");
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<column; ++j)
        {
            scanf("%d", &el);
            matrix[i][j] = el;
        }
    }
    
    int k=0;
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<column; ++j)
        {
            array[k] = matrix[i][j];
            k++;
        }
    }

    bubbleSort(array, number_of_elements);
    
    k=0;
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<column; ++j)
        {
            matrix[i][j]=array[k];
            k++;
        }
    }
        
    int top, bottom, left, right, x;
    top = 0;
    bottom = row-1;
    left = 0;
    right = column-1;
    x=0;

    for (;;)
    {
        if (left>right)
        {
            break;
        }
        
        for (int i=left; i<=right; ++i)
        {
            matrix[top][i]=array[x];
            x=x+1;

        }
        top = top+1;

        if (top>bottom)
        {
            break;
        }
        
        for (int i=top; i<=bottom; ++i)
        {
            matrix[i][right]=array[x];
            x=x+1;
        }
        right = right-1;

        if (left>right)
        {
            break;
        }
        
        for (int i=right; i>=left; --i)
        {
            matrix[bottom][i]=array[x];
            x=x+1;
        }
        bottom = bottom-1;

        if (top>bottom)
        {
            break;
        }
        
        for (int i=bottom; i>=top; --i)
        {
            matrix[i][left]=array[x];
            x=x+1;
        }
        left = left+1;
    }
    printf("\nSpiral matrix\n");
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<column; ++j)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}