#pragma warning(disable : 4996)
#include"terminal.h" 

char DATE_SECOND_NUM1[9] = { '1' , '2' , '3' , '4' ,'5' ,'6' , '7' ,'8' ,'9' };
char DATE_First_NUM1[4] = { '1' , '2' , '3' , '0' };
char DATE_Day_second_NUM1[10] = { '0','1' , '2' , '3' , '4' ,'5' ,'6' , '7' ,'8' ,'9'};  
float idiol = 0.0;  
float idiol_1 = 50000.0; 
 float var_trans_amount;
 float var_MAX_trans_amount; 
 uint8_t trans_date[11];
getTransactionDate(ST_terminalData_t* termData) { 

	uint8_t count = 0;
	uint8_t count_2 = 0;
	uint8_t count_3 = 0;
	
	scanf("%s", termData->transactionDate);
	for (int i = 0; i < strlen(termData->transactionDate); i++) {
		if (termData->transactionDate[i] != ' ')
			count++;
	}
	if (termData->transactionDate[2] != '/') {

		return WRONG_DATE;
	}
	if (termData->transactionDate[5] != '/') {

		return WRONG_DATE;
	}
	if (count == Max_LIMIT_DATETrans) { 
		strcpy(trans_date, termData->transactionDate);
		if (termData->transactionDate[3] == '0') {
			for (int i = 0; i < 9; i++) {
				if (termData->transactionDate[4] == DATE_SECOND_NUM1[i]) {
					count_2++;
					break;


				}

			}
			if (count_2 == 1) {
				if ((termData->transactionDate[0] == '0') || (termData->transactionDate[0] == '1') || (termData->transactionDate[0] == '2') || (termData->transactionDate[0] == '3')) {
					for (int i = 0; i < 10; i++) {
						if (termData->transactionDate[1] == DATE_Day_second_NUM1[i]) {
							count_3++;

						}

					}
					if (count_3++ == 1) { 
						 strcpy( trans_date, termData->transactionDate); 
						return OK1;
					}
					else {
						return WRONG_DATE;
					}



				}
				else {
					return WRONG_DATE;
				}
			}
			else {
				return WRONG_DATE;
			}


		}

	}
	if (count == Max_LIMIT_DATETrans) {
		if (termData->transactionDate[3] == '1') {
			if ((termData->transactionDate[4] == '1') || (termData->transactionDate[4] == '0') || (termData->transactionDate[4] == '2')) {
				if ((termData->transactionDate[0] == '0') || (termData->transactionDate[0] == '1') || (termData->transactionDate[0] == '2') || (termData->transactionDate[0] == '3')) {
					for (int i = 0; i < 10; i++) {
						if (termData->transactionDate[1] == DATE_Day_second_NUM1[i]) {
							count_3++;
							break; 
						}

					}
					if (count_3++ == 1) {
						return OK1;
					}
					else {
						return WRONG_DATE;
					}



				}
				else {
					return WRONG_DATE;
				}

			}
			else {
				return WRONG_DATE;
			}


		}
		else {
			return WRONG_DATE;
		}

	}
	else {
		return WRONG_DATE;
	}
	
} 
isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {
	if ((cardData->cardExpirationDate[3] == '1') || (cardData->cardExpirationDate[3] == '0')) {
	
		
		return EXPIRED_CARD;
	
	} 
	
	else if ((cardData->cardExpirationDate[3] == '2')&& (cardData->cardExpirationDate[4] == '1')) {
		return EXPIRED_CARD; 
		
	}
	else if ((cardData->cardExpirationDate[3] == '2') && (cardData->cardExpirationDate[4] == '0')) { 
		return EXPIRED_CARD;

	}
	else {
		return OK1; 
	}

}
getTransactionAmount(ST_terminalData_t* termData) {
	printf("Transaction Amount : "); 
	scanf_s("%f", &idiol); 
	termData->transAmount = idiol; 
	if (termData->transAmount <= 0) {
	
		return INVALID_AMOUNT;  
	}
	else { 
		var_trans_amount = termData->transAmount; 
		return OK1; 
	}
}
 setMaxAmount(ST_terminalData_t* termData) {
	 termData->maxTransAmount = idiol_1;
	 if (termData->maxTransAmount <= 0) {

		 return INVALID_MAX_AMOUNT;
	 }
	 else {
		 var_MAX_trans_amount = termData->maxTransAmount; 
		 return OK1;
	 }


} 
 isBelowMaxAmount(ST_terminalData_t* termData) { 
	 if (termData->transAmount > termData->maxTransAmount) {
		 return EXCEED_MAX_AMOUNT; 
	 
	 } 
	 else {
		 return OK1; 
	 
	 }
 
 }