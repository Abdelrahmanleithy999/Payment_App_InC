#pragma warning(disable : 4996)
#include"server.h" 
#include<stdio.h>  
#include<string.h>  
#include <conio.h> 
uint8_t PAN_ARRAY[20]; 
uint8_t cardHolder[25];
uint8_t expiry_array[6];   
uint8_t trans_date[11]; 
 float var_trans_amount;
float var_MAX_trans_amount;  

float val_3 = 0.0; 
ST_accountsDB_t accounts[2] = {
                            {100, "AABABCJADFGH1234A"},
                            {10000, "QQQBABCJADFGH1234Z"}
};  

ST_transaction_t Trans_accounts[1] = {
                            {NULL , 0 , 0 ,NULL , APPROVED , 0}
};  
ST_cardData_t cardData;
ST_terminalData_t termData;


recieveTransactionData(ST_transaction_t* transData) {   
    strcpy(transData->cardHolderData.primaryAccountNumber, PAN_ARRAY);  
    strcpy(transData->cardHolderData.cardHolderName, cardHolder);
    strcpy(transData->cardHolderData.cardExpirationDate , expiry_array);
    transData->terminalData.maxTransAmount = var_MAX_trans_amount; 
    transData->terminalData.transAmount = var_trans_amount; 
    strcpy(transData->terminalData.transactionDate, trans_date);
    transData->transactionSequenceNumber = 0; 
    transData->transState = APPROVED; 
    


    
    if (strcmp(transData->cardHolderData.primaryAccountNumber, accounts[0].primaryAccountNumber) == 0) {
    
        if (transData->terminalData.transAmount > accounts[0].balance) {
            return  DECLINED_INSUFFECIENT_FUND;

        }

        else { 
            val_3 = (accounts[0].balance) -(transData->terminalData.transAmount);
            transData->transState = APPROVED; 
            return APPROVED;
        }
    }
    
      if (strcmp(transData->cardHolderData.primaryAccountNumber, accounts[1].primaryAccountNumber)==0) {


        if (transData->terminalData.transAmount > accounts[1].balance) {
            transData->transState = DECLINED_INSUFFECIENT_FUND;
            return  DECLINED_INSUFFECIENT_FUND;


        }
        else {
            val_3 = (accounts[1].balance) - (transData->terminalData.transAmount);
            transData->transState = APPROVED; 
            return APPROVED;
        }
    }
    else {
         transData->transState = DECLINED_STOLEN_CARD; 
        return DECLINED_STOLEN_CARD;
    }

     

   
    


}
isValidAccount(ST_cardData_t* cardData) {
    if (strcmp(cardData->primaryAccountNumber, accounts[0].primaryAccountNumber) == 0) {
     
        return OK; 
    } 
    if (strcmp(cardData->primaryAccountNumber, accounts[1].primaryAccountNumber) == 0) { 

    
        return OK; 
    
    } 
    else {
        return DECLINED_STOLEN_CARD; 
    
    }


}
isAmountAvailable(ST_terminalData_t* termData) {
    if (termData->transAmount > accounts[0].balance) {
        return   LOW_BALANCE;

    }

    else if (termData->transAmount > accounts[1].balance) {
        return   LOW_BALANCE;


    }
    else {
        return OK ;
    }

}
saveTransaction(ST_transaction_t* transData) {
    strcpy(transData->cardHolderData.primaryAccountNumber, PAN_ARRAY);
    strcpy(transData->cardHolderData.cardHolderName, cardHolder);
    strcpy(transData->cardHolderData.cardExpirationDate, expiry_array);
    transData->terminalData.maxTransAmount = var_MAX_trans_amount;
    transData->terminalData.transAmount = var_trans_amount;
    strcpy(transData->terminalData.transactionDate, trans_date); 
    transData->transactionSequenceNumber++;  
    FILE* fopen(const char* path, const char* mode);
    FILE* fp;
    fp = fopen("saved transaction.txt", "w");
    fprintf(fp, " %s \n ", "Transation info");
    fprintf(fp, " %s \n", "Transaction Date : ");
    //char* pts; /* pointer to time string*/
    time_t now; /* current time*/
    char* ctime();
    (void)time(&now);
    fprintf(fp, "%s", ctime(&now));
    fprintf(fp, "%s", "Name Holder :");
    fprintf(fp, "%s \n ", transData->cardHolderData.cardHolderName);
    fprintf(fp, "%s", "PAN Number : ");
    fprintf(fp, "%s\n", transData->cardHolderData.primaryAccountNumber);
    fprintf(fp, "%s", "Remind Money : ");
    fprintf(fp, "%f \n", val_3);
    fprintf(fp, "%s", "Order of transaction  : ");
    fprintf(fp, "%lu\n", transData->transactionSequenceNumber);  
    fprintf(fp, "%s", " transaction status  : ");
    fprintf(fp, "%f\n", transData->terminalData.transAmount);
    fprintf(fp, "%s", "Transation saved thanks for banking with us \n"); 
    fclose(fp); 


     
}
