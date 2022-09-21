#pragma once
#ifndef TERMINAL_H_
#define TERMINAL_H_  
#include"std_types.h" 
#include"card.h"
#include<string.h> 
#include<time.h> 
#include<stdio.h>
#define Max_LIMIT_DATETrans 10  
extern float var_trans_amount; 
extern float var_MAX_trans_amount; 
extern uint8_t trans_date[11];
typedef struct ST_terminalData_t
{
	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
	OK1, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData);
EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData);
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData);




#endif