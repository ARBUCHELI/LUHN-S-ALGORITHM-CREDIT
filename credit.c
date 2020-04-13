#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long number;
   
    number = get_long("Number:"); //Prompting from credit card number
        
    
    if (number < 4000000000000) //Condition to invalidate number
    {
        printf("INVALID\n");
    }
    else
    {
        int pdsuma = 0; //Initialization of variables
        int pdsuma1 = 0; //Initialization of variables
        int pdsuma2 = 0; //Initialization of variables
        long numberc = number; //duplication of credit card number for mathematical operations
        long numberc1 = number; //duplication of credit card number for mathematical operations
        int dsuma = 0; //Initialization of variables
        
        int suma = 0; //Initialization of variables
        
        int numberofdigits = 0; //Initialization of variables
        while (number > 10) //Loop for extract and calculate number of digits
        {
            number = number / 10;
            int pdigit = number % 10;
            int pddigit = pdigit * 2;
            numberofdigits++;
            number = number / 10;
        
            if (pddigit < 10)
            {
                pdsuma1 = pdsuma1 + pddigit;
            }
            if (pddigit >= 10)
            {
                pdsuma2 = pdsuma2 + pddigit % 10 + (pddigit / 10);
            }
            
            pdsuma = pdsuma1 + pdsuma2;       
        }
        while (numberc > 0) //Loop for calculate and extract number of digits
        {
            int digit = numberc % 10;
            numberc = numberc / 10;
            numberc = numberc / 10;
            numberofdigits++;
            dsuma = dsuma + digit;   
        }
        suma = dsuma + pdsuma;
        if (suma % 10 != 0) //Condition to invalidate credit card
        {
            printf("INVALID\n");
        }
        else if (suma % 10 == 0) //Condition to validate credit card
        {
            if (numberofdigits == 15) //Condition for American Express
            {
                int american = (int)(numberc1 / pow(10, 13));
                if (american == 34 || american == 37)
                {
                    printf("AMEX\n");
                }
                else if (american != 34 || american != 37)
                {
                    printf("INVALID\n");
                }
            }
            
            if (numberofdigits == 16 && round(numberc1 / pow(10, 15)) != 4) //Condition for mastercard
            {
                int master = (int) round(numberc1 / pow(10, 14));
                if (master == 51 || master == 52 || master == 53 || master == 54 || master == 55 || master == 56)
                {
                    printf("MASTERCARD\n");
                }
                else if (master != 56)
                {
                    printf("INVALID\n");
                }
            }
            else if (numberofdigits == 16) //Condition for visa
            {
                int visa = (int) round(numberc1 / pow(10, 15));
                if (visa == 4)
                {    
                    printf("VISA\n"); 
                }
            }
            else if (numberofdigits == 13) 
            {
                int visa1 = (int) round(numberc1 / pow(10, 12));
                if (visa1 == 4)
                {
                    printf("VISA");
                }
            }
        }  
    }
}
