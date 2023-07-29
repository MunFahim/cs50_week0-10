#include <cs50.h>
#include <stdio.h>

bool checkAlgo();
void getCard(long num);

int main(void)
{
    long rNum;
    rNum = get_long_long("Enter card number: ");
    if(rNum > 999999999999)
    {
        bool check = checkAlgo(rNum);
        if (check)
        {
            getCard(rNum);
        }
        else printf("INVALID\n");
    }
    else printf("INVALID\n");

}

bool checkAlgo(long num)
{
    int counter = 1;
    int underline = 0;
    while(num != 0)
    {
        long last = num%10;
        //printf("%li \n", last);

        if (counter%2==0)
        {
            if(last*2 < 10)
            {
                underline += last*2;
            }else
            {
                int x = last*2;
                while(x != 0)
                {
                    int xMod = x%10;
                    underline += xMod;
                    x = x * .10;
                }
            }
        }else
        {
            underline += last;
        }
        num = num * .10;
        counter++;
    }
    if (underline%10 == 0)
    {
        return true;
    }
    else return false;
}


void getCard(long num){

    long a = 99999999999999;
    long mOrV = 999999999999999;
    long v = 999999999999;

    int digits;
    if(num > 999999999999999)
    {
        digits = (int)(num*0.00000000000001);
    }else if (num > 99999999999999)
    {
        digits = (int)(num*0.0000000000001);
    }else
    {
        digits = (int)(num*0.00000000001);
    }

    if ((digits == 34 || digits == 37) && num > a)
    {
        printf("AMEX\n");
    }else if ((digits > 50 && digits < 56) && num > mOrV)
    {
        printf("MASTERCARD\n");
    }else if ((digits >= 40 && digits < 50) && (num > v || num > mOrV))
    {
        printf("VISA\n");
    }else
    {
        printf("INVALID\n");
    }
}


