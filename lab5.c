#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** memory_allocation (int a, int b)
{
    int **array = malloc(sizeof(int *)*a);

    for(int i=0; i<b ; ++i)
    {
        array[i] = malloc(sizeof(int)*b);
    }
    return array;
}

int** elements_keyboard(int** array, int a, int b)
{
    for(int i=0; i<a; ++i)
    {
        for(int j=0; j<b; ++j)
        {
            scanf("%d", &array[i][j]);
        }
    }
    return array;
}

int** autocomplete(int **array, int a, int b)
{
    for (int i=0; i<a; ++i)
    {
        for (int j=0; j<b; ++j)
        {
            array[i][j] = rand();
        }
    }
    return array;
}

void selection_sort(int array[], int length) {
    for (int i = 0; i < length - 1; ++i) {
        int max = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] > array[max]) {
                max = j;
            }
        }
        if (max != i) {
            int temp = array[i];
            array[i] = array[max];
            array[max] = temp;
        }
    }
}

int** sort_odd_columns(int** array, int a, int b) {
    for (int j = 1; j < b; j += 2) 
    { 
        int c[a];

        for (int i = 0; i < a; ++i) 
        {
            c[i] = *(*(array + i) + j);
        }
        selection_sort(c, a);

        for (int i = 0; i < a; ++i) 
        {
            *(*(array + i) + j) = c[i];
        }
    }
    return array;
}


void print(int **array, int a, int b)
{
    for (int i=0; i<a; ++i)
    {
        for (int j=0; j<b; ++j)
        {
            printf("%d\t", array[i][j]);
        }
    printf("\n");
    }
}
void transpose(int** array, int a, int b) 
{
    int c;
    for (int i = 0; i < a; i++) 
    {
        for (int j = i + 1; j < b; j++) 
        {
            c = *(*(array + i) + j);
            *(*(array + i) + j) = *(*(array + j) + i);
            *(*(array + j) + i) = c;
        }
    }
}

void sum(int **array, int a, int b)
{
    int *sum_row = malloc(sizeof(int) * a);
    int *sum_col = malloc(sizeof(int) * b);

    for (int i=0; i<a; ++i)
    {
        sum_row[i]=0;
    }

    for (int j=0; j<b; ++j)
    {
        sum_col[j]=0;
    }

    for(int i=0; i<a; ++i)
    {
        for(int j=0; j<b; ++j)
        {
            sum_row[i] += array[i][j];
            sum_col[j] += array[i][j];
        }
    }
    printf("Sum of each row:\n");
    for (int i = 0; i < a; i++) 
    {
        printf("%d ", sum_row[i]);
    }

    printf("\nSum of each column:\n");
    for (int j = 0; j < b; j++) 
    {
        printf("%d ", sum_col[j]);
    }
    free(sum_row);
    free(sum_col);
}

void free_memory(int **array, int a)
{
    for (int i=0; i<a; ++i)
    {
        free(array[i]);
    }
    free(array);
}

void reverse(int *array, int size)
{
    int *first_value = array;
    int *last_value = array + (size - 1);

    while (first_value < last_value)
    {
        int t = *first_value;
        *first_value = *last_value;
        *last_value = t;
        first_value = first_value + 1;
        last_value = last_value - 1;
    }
    printf("\nThe reversed array:\t");
        for (int i=0; i<size; ++i)
        {
            printf("%d ", array[i]);
        }
}

void negative_numbers_sum (int *array, int size)
{
    int s = 0;
    for (int i = 0; i<size; ++i)
    {
        if (0 > *(array+i))
        {
            s = s + *(array+i);
        }
    }
    printf("\nThe sum: %d", s);
}

int main()
{
    int n, m, k, number;
    int **array_new=NULL;
    number = 1;    
    srand(time(0));

    while(number!=0)
    {
        printf("\nThe menu:\n"
           "1. Allocate the memory\n"
           "2. Input the elements from keyboard\n"
           "3. Autocomplete with random values\n"
           "4. Selection Sort of odd columns in descending order\n"
           "5. Print the 2D array\n"
           "6. Free the memory\n"
           "7. (Easy task) Transpose the matrix\n"
           "8. (Medium task) Sums of each row and column\n"
           "0. Exit\n");
        printf("\nThe number from the menu: ");
        scanf("%d", &number);

        if (number == 1)
        {
            if (array_new != NULL)
            {
                printf("Memory allocated previously. Deallocate first.\n");
            }
            else
            {
                printf("Size of 2D array, m: ");
                scanf("%d", &m);
                printf("Size of 2D array, n: ");
                scanf("%d", &n);
                array_new = memory_allocation(m, n);
                printf("Memory is allocated succesfully!\n");
            }
        }
        else if (number == 2)
        {
            if (array_new == NULL)
            {
                printf("There is no memory allocated for the 2D array. Allocate first.\n");
            }
            else
            {
                printf("Input from keyboard the elements of the 2D array: ");
                elements_keyboard(array_new, m, n);
                printf("Elements are saved in the 2D array.\n");
            }
        }
        else if (number == 3)
        {
             if (array_new==NULL)
            {
                printf("There is no memory allocated for the 2D array. Allocate first.\n");
            }
            else
            {
                array_new = autocomplete(array_new, m, n);
                printf("Random elements for the 2D array are created succesfully!\n");
            }
        }
        else if (number == 4)
        {
            if (array_new==NULL)
            {
                printf("There is no memory allocated for the 2D array. Allocate first.\n");
            }
            else
            {
                sort_odd_columns(array_new, m, n);
                printf("The odd columns are sorted in descending order.\n");
            }
        }
        else if (number == 5)
        {
            if (array_new==NULL)
            {
                printf("There is no memory allocated for the 2D array. Allocate first.\n");
            }
            else
            {
                printf("The 2D array: \n");
                print(array_new, m, n);
            }
        }
        else if (number == 6)
        {
            if (array_new==NULL)
            {
                printf("There is no memory allocated for the 2D array. Allocate first.\n");
            }
            else
            {
                free_memory(array_new, m);
                array_new = NULL;
                printf("Memory deallocated succesfully! \n");
            }
        }
        else if (number == 7)
        {
            if (array_new==NULL)
            {
                printf("There is no memory allocated for the 2D array. Allocate first.\n");
            }
            else if (m != n)
            {
                printf("Values of m and n should be the same. Please, change the parameter in order to apply this function!\n");
            }
            else
            {
                printf("The transposed 2D array: \n");
                transpose(array_new, m, n);
                print(array_new, m, n);
            }
        }
        else if (number == 8)
        {
            if (array_new==NULL)
            {
                printf("There is no memory allocated for the 2D array. Allocate first.\n");
            }
            else
            {
                printf("The sums of rows and columns: \n");
                sum(array_new, m, n);
                printf("\n");
            }
        }
        else if (number == 0)
        {
            if (array_new == NULL)
            {
                break;
            }
        }
    }

    printf("\nSize of 1D array, k: ");
    scanf("%d", &k);
    int *a = malloc(k * sizeof(int));
    printf("Input the 1D array: ");
    for (int i=0; i<k; ++i)
    {
        scanf("%d", &a[i]);
    }
    negative_numbers_sum(a, k);
    reverse(a, k);
    free(a);
    return 0;
}
