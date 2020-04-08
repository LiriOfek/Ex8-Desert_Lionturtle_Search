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
