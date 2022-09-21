#pragma warning(disable : 4996)
#include"card.h" 
uint8_t PAN_ARRAY[20];
 uint8_t cardHolder[25];
 uint8_t expiry_array[6];
char DATE_SECOND_NUM[9] = { '1' , '2' , '3' , '4' ,'5' ,'6' , '7' ,'8' ,'9' }; 
uint8_t  str_time[25];
getCardHolderName(ST_cardData_t* cardData) {
	uint8_t count = 0; 
	scanf("%[^\n]", cardData->cardHolderName);
	for (int i = 0; i < strlen(cardData->cardHolderName); i++) {
		if (cardData->cardHolderName[i] != ' ')
			count++;
	}  
	strcpy(cardHolder, cardData->cardHolderName); 
	if ((count > MAX_LIMIT_NAME) || (count < MIN_LIMIT_NAME)) {

		return  WRONG_NAME;
	}
	else { 
		return OK;
	} 
	
}
getCardExpiryDate(ST_cardData_t* cardData) {
	uint8_t count = 0;
	uint8_t count_2 = 0;
	
	scanf("%s", cardData->cardExpirationDate);
	for (int i = 0; i < strlen(cardData->cardExpirationDate); i++) {  //02/22

		if (cardData->cardExpirationDate[i] != ' ')
			count++;
	} 
	if (cardData->cardExpirationDate[2] != '/') {   
	
		return WRONG_EXP_DATE; 
	}
	if (count == Max_LIMIT_DATE) {
		if (cardData->cardExpirationDate[0] == '0') {
			for (int i = 0; i < 9; i++) {
				if (cardData->cardExpirationDate[1] == DATE_SECOND_NUM[i]) {
					count_2++;
					break;


				}

			}
			if (count_2 == 1) {
				strcpy(expiry_array, cardData->cardExpirationDate); 
				return OK;
			} 
			else {
				return WRONG_EXP_DATE;
			}


		}

	}
	 if (count == Max_LIMIT_DATE) {
		if (cardData->cardExpirationDate[0] == '1') {
			if ((cardData->cardExpirationDate[1] == '1') || (cardData->cardExpirationDate[1] == '0') || (cardData->cardExpirationDate[1] == '2')) {
				return OK;

			}
			else {
				return WRONG_EXP_DATE;
			}


		} 
		else {
			return WRONG_EXP_DATE;
		}

	} 
	 else {
		return WRONG_EXP_DATE;
	}
}
getCardPAN(ST_cardData_t* cardData) {
	uint8_t count = 0; 
	//scanf("%s", cardData->primaryAccountNumber);
	//fgets(cardData->primaryAccountNumber, 20, stdin);  
	gets(cardData->primaryAccountNumber); 
	for (int i = 0; i < strlen(cardData->primaryAccountNumber); i++) {
		if (cardData->primaryAccountNumber[i] != ' ')
			count++;
	}
	strcpy(PAN_ARRAY, cardData->primaryAccountNumber);
	if ((count > MAX_LIMIT_PAN) || (count < MIN_LIMIT_PAN)) {

		return  WRONG_PAN;
	}
	else { 
		
		return OK;
	} 
	
	 
	

} 
