#include <cs50.h>
#include <stdio.h>

//TODO
    // Remove "DEBUGGING"
    // Remove comment at end

//Command declarations
int checkLength(long test);
bool checkSum(long number, int length);
char checkCardType(long number, int length);
string decideOutcome(char type, bool valid);

int main(void)
{
    //Variables
    long cardNo;
    bool valid;
    int cardNoLength;
    char cardType;
    string outcome;

    //Request card Number
    cardNo = get_long("Please enter your card number: ");

    //Check length of card number
    cardNoLength = checkLength(cardNo);

    //Check Luhn's Algorithm
    valid = checkSum(cardNo, cardNoLength);

    //Check starting numbers
    cardType = checkCardType(cardNo, cardNoLength);

    //Print Outcome based on checkCardType and checkSum
    outcome = decideOutcome(cardType, &checkSum);
    printf("%s\n", outcome);
}

int checkLength(long test)
{
    int totalDigits = 0;

    while(test != 0)
    {
        test = test / 10;
        totalDigits++;
    }

    return totalDigits;
}

bool checkSum(long number, int length)
{
    //Running total (should be divisible by 10 to be valid card)
    int total = 0;
    int luhnCurrent;
    bool numberIsValid = false;

    //Perform Luhn function on each number
    for (int i = 0; i < (length / 2); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            //every first number (simple addition)
            if (j == 0)
            {
                luhnCurrent = number % 10;
            }
            else //every second number (double the digit then add the digits)
            {
                luhnCurrent = 2 * (number % 10);
                //Check the product is not double digit (if double digit, add the two numbers)
                if (luhnCurrent > 9)
                {
                    //The number in the ones column of luhnCurrent
                    int luhnCurrentOne = luhnCurrent % 10;
                    //The number in the tens column of luhnCurrent
                    int luhnCurrentTen = luhnCurrentOne % 10;

                    //Create new luhnCurrent (the sum of the previous double digit)
                    luhnCurrent = luhnCurrentOne + luhnCurrentTen;
                }
            }
            //Add the calculated number to the running total
            total = total + luhnCurrent;
        }
    }

    if ( (total % 10) == 0)
    {
        numberIsValid = true;
    }

    return numberIsValid;
}

char checkCardType(long number, int length)
{
    char retVal = 'i';
    int cutNumber;

    //VISA(13) check (char = v or m)
    if (length == 13)
    {
        //cut card number down to first digit
        cutNumber = 12;
        for (int i = 0; i < cutNumber; i++)
        {
            number = number / 10;
        }

        //Check numbers (VISA true if 4)
        if (number == 4)
        {
            retVal = 'v';
        }
    }
    //VISA(16) and MASTERCARD check
    else if (length == 16)
    {
        //First decide if card is MASTERCARD or VISA
        int numberSaver;

        cutNumber = 15;
        for (int i = 0; i < cutNumber; i++)
        {
            number = number / 10;
            
            //Save last two digits for MASTERCARD check
            if (i == (cutNumber - 2) )
            {
                numberSaver = number;
            }
        }

        //Check numbers (VISA true if 4)
        if (number == 4)
        {
            retVal = 'v';
        }
        else if (number == 5) //5 = MASTERCARD
        {
            if (numberSaver >=51 && numberSaver <= 55)
            {
                retVal = 'm';
            }
        }
    }
    //AMEX check (char = a)
    else if (length == 15)
    {
        //Cut card number down to first two digits
        cutNumber = 13;
        for (int i = 0; i < cutNumber; i++)
        {
            number = number / 10;
        }

        //Check numbers (AMEX true if 34 or 37)
        if (number == 34 || number == 37)
        {
            retVal = 'a';
        }
    }
    //Any other length (invalid card number; char = i)
        //Dont need to change anything, as retVal is 'i' by default

    return retVal;
}

string decideOutcome(char type, bool valid)
{
    string retVal = "INVALID";
    
    //First, check Luhn's Algorithm is true
    if (valid == true)
    {
        //Now decide outcome based on card type
        if (type == 'm')
        {
            retVal = "MASTERCARD";
        }
        else if (type == 'v')
        {
            retVal = "VISA";
        }
        else if (type == 'a')
        {
            retVal = "AMEX";
        }
        else
        {
            retVal = "INVALID";
        }
    }

    return retVal;
}
