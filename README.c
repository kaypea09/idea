# idea
#include<conio.h>
#include<stdio.h>

struct transaction{
	char accholder[20];
	double balance = 0;
	long int accno;
	int pin;
}acc[10];

int main(){
	int i, n, tempPin, accInput = 1, pinInput = 1, clickButton, mainLoop = 1, testDepo = 0;
	long int tempAccNo, tempAccNoId, depoAcc;
	double drawAmt, depoAmt;
	printf("\nEnter number of Accounts to add ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("\nEnter the following details for a new Account");
		printf("\nAccount number     : ");		scanf("%ld", &acc[i].accno);
		printf("Account holder name  : ");		scanf("%s", acc[i].accholder);
		printf("Balance              : ");		scanf("%lf", &acc[i].balance);
		printf("New PIN              : ");		scanf("%d", &acc[i].pin);
	}

	while(mainLoop != 5){

	accInput = 1, pinInput = 1;

	printf("\n----------------------------BANK OF XYZ----------------------------\n");

	while(accInput!=0){
		printf("\nPlease enter your account number : ");
		scanf("%ld", &tempAccNo);
		for(i=0; i<n ;i++){
			if(tempAccNo == acc[i].accno){
				tempAccNoId = i;
				accInput = 0;
				break;
			}	
		}
		if(accInput == 1)
			printf("\nAccount not found, Please try again...\n");	
	}

	while(pinInput!=0){
		printf("\nEnter PIN : ");
		scanf("%d", &tempPin);
		for(i=0; i<n; i++){
			if(tempPin == acc[tempAccNoId].pin){
				pinInput = 0;
				break;
			}			
		}
		if(pinInput == 1)
			printf("\nPIN is invalid, Please try again...\n");
	}

	printf("\nWELCOME %s,", acc[tempAccNoId].accholder);

	printf("\nFor Balance Inquiry - Click 1");
	printf("\nFor Withdrawal      - Click 2");
	printf("\nFor Deposit         - Click 3\n");
	scanf("%d", &clickButton);

	switch(clickButton){
		case 1:
		printf("\nYour Bank Balance is %lf", acc[tempAccNoId].balance);
		break;

		case 2:
		printf("\nEnter Amount	 ");
		scanf("%lf", &drawAmt);
		if(drawAmt <= acc[tempAccNoId].balance){
			printf("\n%lf was withdrawn from your Account", drawAmt);
			printf("\nAvailable balance is %lf", acc[tempAccNoId].balance -= drawAmt);
	    }
	    else
	    	printf("\nInsufficient Funds");
		break;

		case 3:
		printf("\nEnter Amount ");
		scanf("%lf", &depoAmt);
		printf("\nEnter the Account Number ");
		scanf("%ld", &depoAcc);
		for(i=0; i<n; i++){
			if(depoAcc == acc[i].accno){
				printf("\n%lf has been deducted from your account", depoAmt);
				acc[i].balance += depoAmt;  
				printf("\nAvailable balance is %lf", acc[tempAccNoId].balance -= depoAmt);
				testDepo = 1;
				break;
			}	
		}
		if(testDepo == 0)
			printf("\nAccount not found, Transaction Cancelled");
		break;

		default:
		printf("\nMake sure you select available options");
	}
	printf("\n\nTo Continue using Click 4 \t To Stop using Click 5 ");
	scanf("%d", &mainLoop);
    }
	return 0;
}
