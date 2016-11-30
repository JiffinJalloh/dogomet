#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define BUFFERSIZE 100

char* find_chars(const char * String_1, const char * String_2, const char * Order) {

	int String_1_Length = strlen(String_1);
	int String_2_Length = strlen(String_2);
	int String_1_Length_Counter = 0;
	int String_2_Length_Counter = 0;
	int ReturnedString_1_Length_Counter = 0;
	
    /*declaring a static character to be able to return a string from the function*/
	static char  ReturnedString[BUFFERSIZE];
	
    /*To return a string of order N*N. this was tested with the below strings:
	  string1 = Mohammed; string2 = ahmmed
	  output = mmhammmmed */
	  
	if ((strcmp(Order, "N*N")) == 0) {

		for (String_1_Length_Counter = 0; String_1_Length_Counter < String_1_Length; String_1_Length_Counter++) {
			for (String_2_Length_Counter = 0; String_2_Length_Counter < String_2_Length; String_2_Length_Counter++) {
				if (tolower(String_1[String_1_Length_Counter]) == tolower(String_2[String_2_Length_Counter])) {

					ReturnedString[ReturnedString_1_Length_Counter] = String_1[String_1_Length_Counter];
					ReturnedString_1_Length_Counter++;
				}
			}
		}
	}
	
	/*To return a string of order N. this was tested with the below strings:
	  string1 = Mohammed; string2 = ahmmed
	  output = mhammed */
	  
	else if ((strcmp(Order, "N")) == 0) {
		for (String_1_Length_Counter = 0; String_1_Length_Counter < String_1_Length; String_1_Length_Counter++) {
			for (String_2_Length_Counter = 0; String_2_Length_Counter < String_2_Length; String_2_Length_Counter++) {
				if (tolower(String_1[String_1_Length_Counter]) == tolower(String_2[String_2_Length_Counter])) {

					ReturnedString[ReturnedString_1_Length_Counter] = String_1[String_1_Length_Counter];
					String_2_Length_Counter = String_2_Length;
					ReturnedString_1_Length_Counter++;
				}
			}
		}
	}
	else {
		printf("Unkown Order");
	}
    
	ReturnedString[ReturnedString_1_Length_Counter] = NULL;

	return ReturnedString;
}

int main(void) {

	char  Entered_String_1[BUFFERSIZE];
	char  Entered_String_2[BUFFERSIZE];
	char  Entered_Order[BUFFERSIZE];
	char  *Result;
	char RerunOption[3];

	do {

		printf("Please Enter String 1 ");
		scanf("%s", &Entered_String_1);

		printf("Please Enter String 2 ");
		scanf("%s", &Entered_String_2);
		printf("Please enter Order (N*N or N) ");
		scanf("%s", &Entered_Order);


		Result = find_chars(&Entered_String_1, &Entered_String_2, &Entered_Order);

		printf("%s", Result);

		printf("\nType yes to rerun? or Any other character to exit: ");
		scanf("%s", RerunOption);

		printf("\n\n\n");
	} while (strcmp(RerunOption, "yes") == 0);

	return 0;
}