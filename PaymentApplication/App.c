#pragma warning(disable : 4996)
#include "App.h" 
#include<time.h> 
#include <stdlib.h>
void AppStart() {  
	uint32_t order = 0;
	FILE* fopen(const char* path, const char* mode);
	FILE* file;
	file = fopen("Declined.txt", "w");
	fprintf(file, " %s \n ", "Transation info");
	fprintf(file, " %s \n", "Transaction Date : ");  
	fprintf(file, "%s", " transaction status  : ");
	fprintf(file, "%s\n", "DECLINED");
	fprintf(file, "%s", "Transation saved thanks for banking with us \n");
	

	ST_accountsDB_t accounts[2] = {
							{100, "AABABCJADFGH1234A"},
							{10000, "QQQBABCJADFGH1234Z"}
	};
	//char* pts; /* pointer to time string*/
	time_t now; /* current time */
	char* ctime();
	(void)time(&now);
	printf("%s", ctime(&now)); 
	ST_cardData_t cardData;
	ST_terminalData_t termData;
	ST_transaction_t transData; 
	 printf("Name Holder : ");
 	 getCardHolderName(&cardData); 
	 //printf("%d\n", getCardHolderName(&cardData)); 
	 if (getCardHolderName(&cardData)==WRONG_NAME) {
		 printf("Wrong Name format \n"); 
		 exit(EXIT_SUCCESS);
	 }
	 printf("Expiration Date : ");
	 getCardExpiryDate(&cardData); 
	 //printf("%d\n" ,getCardExpiryDate(&cardData)); 
	 if (getCardExpiryDate(&cardData)==WRONG_EXP_DATE) {
		 printf("Wrong Date format \n");
		 exit(EXIT_SUCCESS);
	 
	 }
     printf("Card PAN : ");
 	 getCardPAN(&cardData); 
	 printf("%d\n", getCardPAN(&cardData));  
	 if (getCardPAN(&cardData) == WRONG_PAN) {
		 printf("Wrong  PAN  format \n");
		 exit(EXIT_SUCCESS);

	 } 
	 printf("Transaction Date : ");
	 getTransactionDate(&termData); 
	 if (getTransactionDate(&termData) == WRONG_DATE) {
		 printf("Wrong  Trans Date  format \n");
		 exit(EXIT_SUCCESS);
	 
	 }
	 if (isCardExpired(&cardData, &termData) == EXPIRED_CARD) {
		 printf("OUT of Date  \n");
		 exit(EXIT_SUCCESS);
	 
	 
	 }  
	 else {
		 getTransactionAmount(& termData);  
		 if (getTransactionAmount(&termData) == INVALID_AMOUNT) {
			 uint32_t order = 0;
			 printf("INVALID AMOUNT  \n");
			 exit(EXIT_SUCCESS);
		 
		 }
		 setMaxAmount(&termData);  
		 if (setMaxAmount(&termData) == INVALID_MAX_AMOUNT) {
			 printf("INVALID MAX AMOUNT  \n");
			 exit(EXIT_SUCCESS);
		 
		 }
		 if (isBelowMaxAmount(&termData) == EXCEED_MAX_AMOUNT) {
		 
			 printf("EXCEED MAX  \n");
			 exit(EXIT_SUCCESS);
		 
		 } 
		 else {
			 printf("CONTINUE \n");  
			 if (recieveTransactionData(&transData)==APPROVED) {
				 printf("CONTINUE \n"); 
				 if(isAmountAvailable(&termData) == LOW_BALANCE) {  
					 
					 
					 printf("No Available Money \n ");
					 
					
				 
				 } 
				 else if (isValidAccount(&cardData) == DECLINED_STOLEN_CARD) {
					 printf("STOLEN CARD \n"); 
					 exit(EXIT_SUCCESS);
				 } 
				 else {
					 saveTransaction(&transData);  

				 
				 }

			 
			 } 
			 else if(recieveTransactionData(&transData) == DECLINED_INSUFFECIENT_FUND) {
				 uint32_t order = 0;
				 FILE* fopen(const char* path, const char* mode);
				 FILE* file;
				 file = fopen("Declined.txt", "w");
				 fprintf(file, " %s \n ", "Transation info");
				 fprintf(file, " %s \n", "Transaction Date : ");
				 //char* pts; /* pointer to time string*/
				 time_t now; /* current time*/
				 char* ctime();
				 (void)time(&now);
				 fprintf(file, "%s\N", ctime(&now));
				 fprintf(file, "%s", " transaction status  : ");
				 fprintf(file, "%s\n", "DECLINED");
				 fprintf(file, "%s\n", "Transation saved thanks for banking with us \n");
				 fprintf(file, "%s", "Order of transaction  : ");
				 fprintf(file, "%lu\n", order+1);
				 fclose(file);
				 printf("No Available Amount of Money \n");
				 exit(EXIT_SUCCESS);
			 } 
			 else if (recieveTransactionData(&transData) == DECLINED_STOLEN_CARD) {
				 printf("Stolen Card \n");
				 printf("%s\n", transData.cardHolderData.primaryAccountNumber);
				 printf("%s \n", cardData.primaryAccountNumber);
				 printf("%s \n", accounts[0].primaryAccountNumber);
				 exit(EXIT_SUCCESS);
			 }
			 else {
				 printf("Interior server error \n");
				 
				 exit(EXIT_SUCCESS);
			 }
		 
		 }
	 
	 }

		
		 
	
	
}