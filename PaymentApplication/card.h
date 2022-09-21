#pragma once 
#ifndef CARD_H_
#define CARD_H_ 
#include"std_types.h" 
#include<stdio.h>
#include<string.h>   
#define MAX_LIMIT_NAME 24 
#define MIN_LIMIT_NAME 20 
#define Max_LIMIT_DATE 5
#define MAX_LIMIT_PAN 19
#define MIN_LIMIT_PAN 16 
extern uint8_t PAN_ARRAY[20];  
extern uint8_t cardHolder[25]; 
extern uint8_t expiry_array[6];
typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t; 
typedef enum EN_cardError_t
{
	OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t; 

/********************************FUNCTIONS *************************************/ 
EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData); 

#endif