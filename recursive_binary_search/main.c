/********************************************************\
File Name: main.c
Author: Liri (8/4/2020)
Purpose: This file find the index of requested number in given array
		 by recursive binary search
\********************************************************/

#include <stdio.h>

#define SIZE (10)
#define INITIAL_INDEX (0)
#define ELEMENT_NOT_IN_ARRAY (-1)
#define MIDDLE (2)
#define ONE (1)
#define ENTER_REQUESTED_NUMBER ("Enter the number you want to find its index in the array: ")
#define GET_INTEGER ("%d")
#define STRING_INDEX_OF_REQUESTED_NUMBER ("The index of number %d in the array is: %d\n")
#define STRING_INDEX_NOT_IN_ARRAY ("The number %d is not in the array\n")

int binary_search_of_index(int numbers_array[SIZE],
	int start_index,
	int end_index,
	int requested_number) {
	/********************************************************\
	* Function name - binary_search_of_index
	*
	* Function Purpose - return the index of requested_number
	*					 by recursive binary search
	*					 or ELEMENT_NOT_IN_ARRAY if the number not in array
	*
	* Parameters - IN int numbers_array[SIZE] - the given array of numbers
	*			   IN int start_index - start index of search in numbers_array
	*			   IN int end_index - end index of search in numbers_array
	*			   IN int requested_number - the requested number
	*			   OUT int the index of the element in numbers_array,
	*					if not found return ELEMENT_NOT_IN_ARRAY
	*
	* Return Value - if the requested number in the given array - return
	*					the index of the number
	*				otherwise - return ELEMENT_NOT_IN_ARRAY
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this recursive function return the index of the requested
	*				element in the given array by binary search
	*
	* Author - Liri
	\********************************************************/
	int middle_index = INITIAL_INDEX;
	if (end_index >= start_index) {
		middle_index = start_index + (end_index - start_index) / MIDDLE;
		/*if the element present in the middle -> return the middle index*/
		if (requested_number == numbers_array[middle_index]) {
			return middle_index;
		}
		/*if element ia smaller than middle, than it will
		be in the left subarray*/
		if (requested_number < numbers_array[middle_index]) {
			return binary_search_of_index(numbers_array,
				start_index,
				middle_index - ONE,
				requested_number);
		}
		/*else the element is in the right array*/
		else {
			return binary_search_of_index(numbers_array,
				middle_index + ONE,
				end_index,
				requested_number);
		}
	}
	/*the element is not in the array*/
	else {
		return ELEMENT_NOT_IN_ARRAY;
	}
}

void main() {
	/********************************************************\
	* Function name - main
	*
	* Function Purpose - get number from the user and
	*					 run the function that check the
	*					 index of the number in a given array
	*
	* Parameters - no Input/Output parameters
	*
	* Return Value - there isn't return value
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - get number from the user and
	*			  run the function that check the
	*			  index of the number in a given array
	*
	* Author - Liri
	\********************************************************/
	int numbers_array[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int index_of_requested_number = INITIAL_INDEX;
	int requested_number = INITIAL_INDEX;

	printf(ENTER_REQUESTED_NUMBER);
	scanf_s(GET_INTEGER, &requested_number);

	index_of_requested_number = binary_search_of_index(numbers_array,
		INITIAL_INDEX,
		SIZE - 1,
		requested_number);

	if (ELEMENT_NOT_IN_ARRAY != index_of_requested_number) {
		printf(STRING_INDEX_OF_REQUESTED_NUMBER,
			requested_number,
			index_of_requested_number);
	}
	else {
		printf(STRING_INDEX_NOT_IN_ARRAY,
			requested_number);
	}
}
