#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Function Prototypes

//Constants
bool DEBUGGING = true;

int main(int argc, string argv[])
{
    //Check command line arguments
    int keyValidity = checkKey(argc, argv[]);

    if (keyValidity == 1)
    {
    	printf("Error: Please enter only 1 command line argument.");
    }
    else if (keyValidity > 1)
    {
    	keyValidity = 1;
    	printf("Error: Please insert a valid key. Your key was not accepted.")
    }
    return keyValidity;

    //save key into translator

    //request and save plaintext

    //After accepting the key, build the translator

    //Apply the translator to the plaintext
    //enchiper();

    //output the ciphertext
}

int checkKey(int argC, string key[])
{
	//Will return a number depending on validity of the command line argument
	//'0' = accepted and valid, no issue
	//'1' = no argument received or more than one recieved.
	//'2' = key is too short or too long. must be 26 characters
	//'3' = Key contains non-alphabetic characters
	//'4' = A letter has been repeated. Only one of each character acceptable (case-insensitive, add total of all characters together, should always = the same)
	
	int retVal = 0;

	//Invalid number of arguments
	//This error is last because it should override any other error's
	if (argC != 1)
	{
		retVal = 1;
	}
	else
	{
		//key is invalid length
		if ((strlen(key[1]) < 26) || (strlen(key[1]) > 26))	//strlen() checks the length of a string (from string.h library)
		{
			retVal = 2;
		}

		//key contains non-alphabetic characters
		bool onlyLetters = testKeyChar(key[1]);
		if()
		{
			retVal = 3;
		}
		//a letter is repeated
		if()
		{
			retVal = 4;
		}
	}

	

	

	return retVal;
}

bool onlyLetters(int key)
{

}