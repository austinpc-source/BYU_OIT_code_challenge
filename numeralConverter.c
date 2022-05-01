#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *numberConversion(char* number, int *numberArray, char *romanArray) {
	int numDigits = strlen(number);
	int arrayIndex = 0;   //Indicates the index of the current value being added to reach the desired number.
	int actualVal = atoi(number);
	int currVal = 0;
	char* numeral = calloc(10, sizeof(char));
	int numeralIndex = 0;
	
	//Setting the index to the highest value that will be used.
	switch (numDigits) {
	case 1:
		arrayIndex = 1;
		break;
	case 2:
		arrayIndex = 3;
		break;
	case 3:
		arrayIndex = 5;
		break;
	default:
		arrayIndex = 6;
		break;
	}

	// This loop adds the proper characters until the total value of the characters is equal to the desired value.
	size_t i = 0;
	int romVal = 0;
	while (currVal < actualVal) {
		char digit = number[i];
		int goalVal = atoi(&digit);
		if (goalVal == 0) {
			i++;
			continue;
		}

		//Focusing on a single digit at a time in the correct location
		for (size_t d = 0; d < numDigits - 1 - i; d++) {
			goalVal *= 10;
		}

		//Iterating through the numeral array to get to the desired value
		while (numberArray[arrayIndex] > goalVal) {
			arrayIndex--;
		}

		//Deciding whether to add a numeral or subtract
		if (digit == '9' || digit == '4') {
			int subtractIndex = arrayIndex;
			arrayIndex++;
			while (subtractIndex >= 0) {
				if ((numberArray[arrayIndex] - numberArray[subtractIndex]) == goalVal) {
					numeral[numeralIndex++] = romanArray[subtractIndex];
					romVal -= numberArray[subtractIndex];
					numeral[numeralIndex++] = romanArray[arrayIndex];
					romVal += numberArray[arrayIndex];
					break;
				}
				else --subtractIndex;
			}
		}
		else {
			romVal += numberArray[arrayIndex];
			numeral[numeralIndex++] = romanArray[arrayIndex];
			if ((romVal + numberArray[arrayIndex]) > goalVal && romVal != goalVal) {
				arrayIndex--;
			}
		}

		if (romVal == goalVal) {
			currVal += romVal;
			romVal = 0;
			i++;
			arrayIndex--;
		}
		
	}
	return numeral;
}

int romanConversion(char* numeral, int* numberArray, char* romanArray) {
	int numNumerals = strlen(numeral);
	int numValue = 0;
	for (size_t i = 0; i < numNumerals; i++) {
		char curChar = numeral[i];
		int numeralIndex = strchr(romanArray, curChar) - romanArray;
		int nextIndex = 0;
		if (i < (numNumerals - 1)) {
			nextIndex = strchr(romanArray, numeral[i + 1]) - romanArray;
		}

		if (nextIndex > numeralIndex) {
			numValue += numberArray[nextIndex];
			numValue -= numberArray[numeralIndex];
			i++;
		}
		else {
			numValue += numberArray[numeralIndex];
		}
	}
	return numValue;
}

void main(int argc, char** argv) {
	int numberToNumeral = 0;
	char value[20];
	int numbers[7] = { 1,5,10,50,100,500,1000 };
	char numerals[8] = { 'I','V','X','L','C','D','M','\0'};


	printf("Welcome to the Roman Numeral Converter.\n");
	while (1) {
		printf("If you wish to convert a number, enter the number 1.\n");
		printf("If you wish to convert a roman numeral, enter the number 0.\n");
		printf("To quit the program, enter the number 2.\n\n");
		printf("Enter number: ");
		scanf("%d", &numberToNumeral);

		if (numberToNumeral) {
			if (numberToNumeral == 2) {
				break;
			}
			printf("Please enter the number to be converted: ");
		}
		else {
			printf("Please enter the numeral to be converted : ");
		}

		scanf("%19s", value);

		if (numberToNumeral) {
			char* numeral = numberConversion(value, numbers, numerals);
			printf("%s is equal to %s in roman numerals.\n\n\n", value, numeral);
			free(numeral);
		}
		else {
			int number = romanConversion(value, numbers, numerals);
			printf("%s is equal to the number %d.\n\n\n", value, number);
		}
	}
}