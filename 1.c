#include <stdio.h>

void bubbleSort(int array[], int size) 
{
  for (int j = 0; j < size - 1; ++j) 
  {
    for (int i = 0; i < size - j-1; ++i) 
    {
      if (array[i] > array[i + 1]) 
      {
        int t = array[i];
        array[i] = array[i + 1];
        array[i + 1] = t;
      }
    }
  }
}

void printarray(int array[], int size) 
{
  for (int i = 0; i < size; ++i) 
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

void inputarray(int array[], int size)
{
  for(int i=0; i<size; ++i)
    {
      scanf("%d", &array[i]);
    }
}

int main()
{  
    int length, l, e, min, pos_min, max, pos_max;
    printf("Length of an array: ");
    scanf("%d", &length);
    int a[length], b[length], c[length] ;
  
    printf("Input array a: ");
    inputarray(a, length);
    printf("Input array b: ");
    inputarray(b, length);

    /*The base task*/
        for (int i=0; i<length; ++i)
    {
        c[i]=b[i];
    }

    bubbleSort(b, length);
    pos_min = length;
    min=b[length];
    
    for (int i = 0; i < length; ++i)
    {
        if (b[i]>=0)
        {
            if (b[i]<=min)
            {
                min = b[i];
            }
        }
    }
    for (int i=0; i<length; ++i)
    {
        if (c[i]==min)
        {
            pos_min = i+1;
        }
    }
    printf("\nThe positive minimum of the array b: %d", min);
    printf("\nThe position of minimum: %d", pos_min);
    
    pos_max = 0;
    max=b[0];
    
    for (int i = 0; i < length; ++i)
    {
        if (b[i]<0)
        {
            if (b[i]>=max)
            {
                max = b[i];
                pos_max = i+1;
            }
        }
    }
    for (int i=0; i<length; ++i)
    {
        if (c[i]==max)
        {
            pos_max = i+1;
        }
    }
    printf("\nThe negative maximum of the array b: %d", max);
    printf("\nThe position of maximum: %d", pos_max);
    
    /*Sum of arrays*/  
    l=0;
    printf("\nThe sum of 2 arrays: ");
    for(int i=0; i<length; ++i)
    {
        l=a[i]+b[i];
        printf("%d  ", l);
    }

    /*The sum of even numbers*/
    e=0;
    printf("\nThe sum of even numbers in array b: ");
    for(int i=0; i<length; ++i)
    {
        if (b[i]%2==0)
        {
            e = e + b[i];
        }
    }
    printf("%d ", e);

    /*The sum of odd numbers*/
    e=0;
    printf("\nThe sum of odd numbers in array a: ");
    for(int i=0; i<length; ++i)
    {
        if (a[i]%2!=0)
        {
            e = e + a[i];
        }
    }
    printf("%d ", e);

    /*Number of prime numbers*/
	int counter=0, num=0; 
	for(int i=0; i<length; ++i)
    {
        if (a[i]>1)
        {
            for(int j=2; j<a[i]/2; ++j)
	        {
		        if(a[i]%j==0)
		        {
		    	    counter=1;
                    break;
		        }
            }
        }
	    if((counter==0) || (a[i]==2))
        {
            ++num;
        }                
    }
    printf("\nNumber of prime numbers in array a: %d", num);

	return 0;
}
