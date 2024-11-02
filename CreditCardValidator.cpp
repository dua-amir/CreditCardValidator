// Credit-card-validator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>


using namespace std;
bool isNumberString(const string ccNumber);

int main()
{

	// User credit card number input.
	string ccNumber;

	cout << "This program uses the Luhn Algorithm to validate a CC number." << endl;
	cout << "Enter 'exit' to quit.\n";




	do
	{
		cout << "Please enter a credit card number to validate: ";
		cin >> ccNumber;





		// Input Validation
		while (!isNumberString(ccNumber) && ccNumber != "exit")
		{
			cout << "Invalid input. Please enter a valid CC number: ";
			cin >> ccNumber;
		}





		// if ccNumber is "Exit" don't continue 
		if (ccNumber != "exit")
		{
			// Get length of the credit card numbers
			int numDigits = ccNumber.length();
			// Running total of Digits added 
			int sumDigits = 0;

			// Implements Luhn's Algorithm
			for (int index = numDigits - 2; index >= 0; index -= 2)
			{
				// Every Second digit from the rightmost value is doubled
				int doubleSecondDigit = (ccNumber[index] - '0') * 2;


				// Handling is done if the returned value is a 2 digit number
				// Sum the results of the evenly placed digits in value 'sumDigits'
				if (doubleSecondDigit > 9)
					sumDigits += ((doubleSecondDigit % 10) + (doubleSecondDigit / 10)); // The digits of the number are added together then added to running total
				else
					sumDigits += doubleSecondDigit;
			}



			// Add the odd-placed digits from the right to value 'sumDigits' 
			for (int index = numDigits - 1; index >= 0; index -= 2)
			{
				sumDigits += (ccNumber[index] - '0');
			}

			// If the sum of all digits modulo 10 are 0 then CC number is valid. 
			if (sumDigits % 10 == 0)
			{
				cout << "This is a valid card.\n";
			}
			else
			{
				cout << "This is not a valid card.\n";
			}
		}

	} while (ccNumber != "exit");

	cout << "Exiting.\n"; 


	return 0;
}

bool isNumberString(const string ccNumber)
{
	int length = ccNumber.length();
	for (int index = 0; index < length; index++)
	{
		if (ccNumber[index] < '0' || ccNumber[index] > '9')
		{
			return false;
		}
	}
	return true;

}
