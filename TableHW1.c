#include <stdio.h>

int main()
{
    float alpha[26] = 
    {
        0.0812	,0.0149,	0.0271,	0.0432,	0.1202,	0.023,	0.0203,	0.0592,	0.0731,	0.001,	0.0069,	0.0398,	0.026
        ,0.0695,	0.0768,	0.0182,	0.0011,	0.0602,	0.0628,	0.091,	0.0288,	0.0111,	0.0209,	0.0017,	0.0211,	0.0007
    };
    
    float check[26];
    float temp = 0;
    
    for(int i = 0; i < 26; i++)
    {
        scanf("%f", &temp);
        check[i] = temp;
        temp = 0;
    }
    
    // CONSTANT STUFF UP UNTIL NOW //
    
    int maxShift = 0;
    float maxSum = 0;
    
    float currentSum = 0;
    
    for(int i = 0; i < 26 ; i++)                //shift amount
    {
        for(int j = 0; j < 26 ; j++)
        {
            currentSum += alpha[j]*check[i];
            i++; i = i % 26;
        }
        
        if(currentSum > maxSum)
        {
            maxSum = currentSum;
            maxShift = i;
        }
        
        currentSum = 0;
    }
    
    printf("The key for this position is : %c", maxShift + 'A');

    return 0;
}
