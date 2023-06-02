/***************************************************************************
This is to certify that this project is my own work, based on my personal 
efforts in studying and applying the concepts learned. I have constructed 
the functions and their respective algorithms and corresponding code by 
myself. The program was run, tested, and debugged by my own efforts. 
I further certify that I have not copied in part or whole or otherwise 
plagiarized the work of other students and/or persons.

                               Mary Joselle M. Cabungcal, DLSU ID# 12149020
***************************************************************************/

/*
Description: A Programmed Pizza Vending Machine that has Change and Receipt Mechanism
Programmed By: Mary Joselle M. Cabungcal
Last Modified: 02/07/2022
Version: 1.0
*/

//START
#include <stdio.h>

//CONSTANT PRICES FOR PIZZA SIZES
#define SMALL 100.0
#define MEDIUM 175.0
#define LARGE 225.0


//CONSTANT PRICES FOR TOPPINGS
#define HAM 10.0
#define PINEAPPLE 6.0
#define SAUSAGE 15.0
#define CHEESE 12.0
#define OLIVES 10.0

//CONSTANT PRICES FOR STUFFINGS
#define CHSTUFF 30.0 //Cheese
#define SPSTUFF 25.0 //Spam
#define BTSTUFF 35.0 //Both

//SAMPLE
/* This function computes for the area of a triangle
Precondition: base and height are non-negative values
@param base is the base measurement of the triangle in cm
@param height is the height measurement of the triangle in cm
@return the resulting area of the triangle

float
getAreaTri (float base,
float height)
{
...
}
*/

/* This function prints the divider in the program */
void
printDivider()
{
		int x;

		for (x = 1; x <= 37; x++) {
				printf("=");
		}
}

/* This function prints the Pizza Vending Machine details
including the prices of each Pizza Sizes and Toppings
*/
void
printPizzaDets()
{
		int 	x, y, z, a;

		printDivider();
		printf("\nWELCOME TO MJ'S PIZZA VENDING MACHINE\n");
		printDivider();
		printf("\n\t\tMENU");
		
		printf("\nCRUST TYPE");
		for (x= 1; x <= 2; x++){
				switch (x) {
				case 1:
						printf("\nTHIN CRUST (1)");
						break;
				case 2:
						printf("\nTHICK CRUST (2)");
						break;
				}
		}

		printf("\n\nPIZZA SIZES");
		for (y = 1; y <= 3; y++){
				switch (y) {
				case 1:
						printf("\nSMALL (S)\t\t\t100.00");
						break;
				case 2:
						printf("\nMEDIUM (M)\t\t\t175.00");
						break;
				case 3:
						printf("\nLARGE (L)\t\t\t225.00");
						break;
				}
		}

		printf("\n\nTOPPINGS");
		for (z = 1; z <= 5; z++){
				switch (z) {
				case 1:
						printf("\nHAM (H)\t\t\t\t10.00");
						break;
				case 2:
						printf("\nPINEAPPLE (P)\t\t\t6.00");
						break;
				case 3:
						printf("\nSAUSAGE (S)\t\t\t15.00");
						break;
				case 4:
						printf("\nCHEESE (C)\t\t\t12.00 \n\tMOZZARELLA (M) \n\tGORGONZOLA (G) \n\tFONTINA (F) \n\tPARMESAN (P)");
						break;
				case 5:
						printf("\nOLIVES (O)\t\t\t10.00");
						break;
				}
		}

		printf("\n\nTHICK CRUST STUFFINGS");
		for (a = 1; a <= 3; a++){
				switch (a) {
				case 1:
						printf("\nCHEESE (C)\t\t\t30.00");
						break;
				case 2:
						printf("\nSPAM (S)\t\t\t25.00");
						break;
				case 3:
						printf("\nCH & SP (B)\t\t\t35.00\n");
						break;
				}
		}
		printDivider();
		printf("\n");
}

/* This function prints Invalid Input when the User 
entered an incorrect input.
*/
void
isInvalidIn()
{
	printf("Invalid Input\n");
}

/* This function checks the validity of User's input 
in the Crust Type.
Precondition: nInput is an integer
@param nInput is the user's input of Crust Type
@return 0 if the nInput is less than 1 or greater than 2
*/
int
isValidCr (int nInput)
{
		if (nInput > 2 ||
			nInput < 1)
				return 0;
		else
				return 1;
}

/* This function checks the validity of User's input 
in the character type input steps (2-5)
Precondition: nMode is an integer and cInput is a character
@param nMode is the step where the user is currently 
inputting a character.
@param cInput is the User's input for steps 2-5
@return 1 if cInput is within the choices in steps 2-5
@return 0 if cInput is not within the choices
*/
int
isValidChar (int 	nMode, 
			 char   cInput)
{
		if (nMode == 2){
				switch (cInput){
				case 's': case 'S': case 'm': case 'M':
				case 'l': case 'L': case 'x': case 'X':
						return 1;
						break;

				default:
						return 0;
						break;
				}
		}
		else if (nMode == 3){	
				switch (cInput){
				case 'h': case 'H': case 'p': case 'P':
				case 's': case 'S': case 'c': case 'C':
				case 'o': case 'O': case 'n': case 'N':
				case 'x': case 'X':
						return 1;
						break;

				default:
						return 0;
						break;  
				}
		}
		else if (nMode == 4){	
				switch (cInput){
				case 'm': case 'M': case 'p': case 'P':
				case 'f': case 'F': case 'g': case 'G': 
				case 'x': case 'X':
						return 1;
						break;

				default:
						return 0;
						break;  
				}
		}
		else if (nMode == 5){
				switch (cInput){
				case 'c': case 'C': case 's': case 'S':
				case 'b': case 'B': case 'n': case 'N':
				case 'x': case 'X':
						return 1;
						break;

				default:
						return 0;
						break;
				}
		}
		return 0;
}

/* This function checks the validity of User's input 
in the Money.
Precondition: nInput is an integer
@param nInput is the user's input of Money Num
@return 0 if the nInput is less than 1 or greater than 13
*/
int
isValidMon(int nInput)
{
		if (nInput > 13 ||
			nInput < 1)
				return 0;
		else
				return 1;
}

/* This function returns the price value of the Pizza Base
based on the size input
Precondition: cPizzaSize is a character
@param *fSizePrice is the price value of the Pizza Base
@param fMultiplier multiplier for toppings dependent on the size
@returns the value of constant SMALL and Multiplier 1.0 when
cPizzaSize is 's' or 'S'
@returns the value of constant MEDIUM and Multiplier 1.5 when
cPizzaSize is 'm' or 'M'
@returns the value of constant LARGE and Multiplier 1.0 when
cPizzaSize is 'l' or 'L'
*/
void
getBasePrice(float	*fSizePrice,
			 float	*fMultiplier,
			 char 	cPizzaSize)
{
		switch (cPizzaSize){
		case 's': case 'S':
				*fSizePrice = SMALL;
				*fMultiplier = 1.0;
				break;

		case 'm': case 'M':
				*fSizePrice = MEDIUM;
				*fMultiplier = 1.5;
				break;

		case 'l': case 'L':
				*fSizePrice = LARGE;
				*fMultiplier = 1.75;
				break;
		}
}

/* This function prints the Cheese Type based on User's Input
Precondition: cCheeseT is a character
@param cCheeseT is the User's cheese type input
*/
void
getCheeseType(char cCheeseT)
{
		switch (cCheeseT){
		case 'm': case 'M':
				printf("Mozzarella");
				break;

		case 'g': case 'G':
				printf("Gorgonzola");
				break;

		case 'f': case 'F':
				printf("Fontina");
				break;

		case 'p': case 'P':
				printf("Parmesan");
				break;

		}
}

/* This function prints the choice of the user from the Menu
Precondtion: nMode, nInputI & nTopCount are integers
			 cInputC & cChzType are characters
@param nMode is the Step where the user is in;
@param nInputI is the User's integer input
@param nTopCount is the number of topping that the User ordered
@param cInputC is the User's character input
@param cChzType is the User's chosen cheese type
*/
void
printChoice(int 	nMode, 
			int 	nInputI, 	
			int 	nTopCount,
			char 	cInputC,
			char 	cChzType)
{
		printf("You chose ");

		if (nMode == 1){
				switch (nInputI){
				case 1:
						printf("Thin Crust\n");
						break;

				case 2:
						printf("Thick Crust\n");
						break;
				}
		}

		else if (nMode == 2){
				switch (cInputC){
				case 's': case 'S':
						printf("Small Pizza\n");
						break;

				case 'm': case 'M':
						printf("Medium Pizza\n");
						break;

				case 'l': case 'L':
						printf("Large Pizza\n");
						break;
				}
		}
		else if (nMode == 3){
				switch (cInputC){
				case 'h': case 'H':
						printf("Ham Toppings\n");
						break;

				case 'p': case 'P':
						printf("Pineapple Toppings\n");
						break;

				case 's': case 'S':
						printf("Sausage Toppings\n");
						break;

				case 'o': case 'O':
						printf("Olives Toppings\n");
						break;

				case 'n': case 'N':
						printf("only %d Toppings\n", nTopCount);
						break;
				}
		}
		else if (nMode == 4){
				getCheeseType(cChzType);
				printf(" Cheese Toppings\n");
		}
		else if (nMode == 5){
				switch (cInputC){
				case 'c': case 'C':
						printf("Cheese Stuffing\n");
						break;

				case 's': case 'S':
						printf("Spam Stuffing\n");
						break;

				case 'b': case 'B':
						printf("Spam & Cheese Stuffing\n");
						break;

				case 'n': case 'N':
						printf("No Stuffing\n");
						break;
				}
		}
}

/* This function returns the price value of the toppings
based on the size input
Precondition: cTops is a character & fMult is a float
@param cTops is the chosen toppings of the user
@param fMultis the multiplier for toppings dependent on the size
@param fTPPrice is the computed price of the toppings
@returns the computed price of the toppings
*/
float
computeToppings(char 	cTops,
				float 	fMult)
{
		float 	fTPPrice = 0;
				switch (cTops){
				case 'h': case 'H':
						fTPPrice = HAM * fMult;
						break; 

				case 'p': case 'P':
						fTPPrice = PINEAPPLE * fMult;
						break;

				case 's': case 'S':
						fTPPrice = SAUSAGE * fMult;
						break; 

				case 'c': case 'C':
						fTPPrice = CHEESE * fMult;
						break;

				case 'o': case 'O': 
						fTPPrice = OLIVES * fMult;
						break; 

				case 'n': case 'N':
						break;

				}

				return fTPPrice;
}


/* This function returns the price value of the stuffings
Precondition: cStuffs is a character
@param cStuffs is the chosen stuffing of the user
@param fSTPrice is the price of the stuffing depending on cStuffs
@returns the price of the stuffings
*/
float
computeStuffings(char 	cStuffs)
{
		float 	fSTPrice = 0;

				switch (cStuffs){
				case 'c': case 'C':
						fSTPrice = CHSTUFF;
						break;

				case 's': case 'S':
						fSTPrice = SPSTUFF;
						break;

				case 'b': case 'B':
						fSTPrice = BTSTUFF;
						break;

				case 'n': case 'N':
						break;
				}

				return fSTPrice;
}

/* This function returns the value of the Money value based on the user's input
Precondition: nInput is an integer & fValue is a float
@param nInput is the input of the user
@param fValue is the value of the money
@returns the value of the money
*/
float
valMoney(int nInput)
{
		float	fValue;

				switch (nInput){
				case 1:
						fValue = 1000.0;
						break;

				case 2:
						fValue = 500.0;
						break;

				case 3:
						fValue = 200.0;
						break;

				case 4:
						fValue = 100.0;
						break;

				case 5:
						fValue = 50.0;
						break;

				case 6:
						fValue = 20.0;
						break;

				case 7:
						fValue = 10.0;
						break;

				case 8:
						fValue = 5.0;
						break;

				case 9:
						fValue = 1.0;
						break;

				case 10:
						fValue = 0.25;
						break;

				case 11:
						fValue = 0.10;
						break;

				case 12:
						fValue = 0.05;
						break;

				case 13:
						fValue = 0.01;
						break;
				}

				return fValue;
}

/* This function prints the toppings and its price
Precondition: cTops is a character & fTopP is a float
@param cTops is the input of the user
@param fTopP is the value of the toppings
@returns the value of the toppings
*/
void
printToppings(char cTops, float fTopP)
{
		switch (cTops){
		case 'h': case 'H':
				printf("Ham\t\t\t\t%.02f\n", fTopP);
				break;

		case 'p': case 'P':
				printf("Pineapple\t\t\t%.02f\n", fTopP);
				break;

		case 's': case 'S':
				printf("Sausage\t\t\t\t%.02f\n", fTopP);
				break;

		case 'o': case 'O':
				printf("Olives\t\t\t\t%.02f\n", fTopP);
				break;

		case 'm': case 'M':
				printf("Mozzarella\t\t\t%.02f\n", fTopP);
				break;

		case 'g': case 'G':
				printf("Gorgonzolan\t\t\t%.02f\n", fTopP);
				break;

		case 'f': case 'F':
				printf("Fontina\t\t\t\t%.02f\n", fTopP);
				break;

		case 'Z':
				printf("Parmesan\t\t\t%.02f\n", fTopP);
				break;
		}
}

/* This function prints the total prices of the User's Orders
Precondition: All int and float param is non-negative integer
@param nTransNum is the transaction number of the receipt
@param cTop1/2/3 is the chosen toppings of the user
@param fTop1/2/3 is the prices of the toppings
@param fSizePr is the price of Pizza based on the Size
@param fStuffsP is the price of the Stuffing depending on
       @param cStuffs
*/
void
printReceipt(int 	nTransNum, 
			 int 	nCrust,
			 float  fSizePr,
			 float  fTopP1,
			 float  fTopP2,
			 float  fTopP3,
			 float  fStuffsP,
			 float  fPZTotal, 
			 char 	cPizSize, 
			 char 	cTop1,
			 char 	cTop2,
			 char 	cTop3, 
			 char 	cStuffs)
{
		printDivider();
		printf("\n\t\tRECEIPT\n");
		printf("Transaction No. %d\n\n", nTransNum);
		switch (nCrust){
			case 1:
					printf("Thin Crust (%c)\t\t\t%.02f\n", cPizSize, fSizePr);
					break;

			case 2:
					printf("Thick Crust (%c)\t\t\t%.02f\n", cPizSize, fSizePr);
					break;
		}
		if (cTop1 != 'a'){
				printToppings(cTop1, fTopP1);
		}
		if (cTop2 != 'a'){
				printToppings(cTop2, fTopP2);
		}
		if (cTop3 != 'a'){
				printToppings(cTop3, fTopP3);
		}
		if (cStuffs != 'a'){
				if (fStuffsP == 30){
					printf("Cheese Stuffing\t\t\t%.02f\n", fStuffsP);
				}
				else if (fStuffsP == 25){
					printf("Spam Stuffing\t\t\t%.02f\n", fStuffsP);
				}
				else if (fStuffsP == 35){
					printf("C&H Stuffing\t\t\t%.02f\n", fStuffsP);
				}
		}
		printf("TOTAL:\t\t\t\t%.02f\n\n", fPZTotal);
}

/* This function prints the list of Money to input*/
void
printMon()
{
		int 	i;

				printDivider();
				printf("\n\t\tMONEY\n");
				for (i = 1; i <= 13; i ++){
						printf("[%d]\t%.02f\n", i, valMoney(i));
				}
				printDivider();
}

/* This function computes the change for the User's orders
Precondition: fTotal is a non-zero & non-negative value
@param fChange is the Change of the user
@param fUMoney is the Money of the user
*/
void
computeChange(float fTotal)
{
		int 	x, y = 1, z,
				nInsert;
		float 	fUMoney = 0,
				fChange;

				while (fUMoney < fTotal){
						printf("\nInsert Money: ");
						scanf(" %d", &nInsert);

						if (isValidMon(nInsert) == 0)
								isInvalidIn();
						else{
								fUMoney += valMoney(nInsert);
								printf("Total Money: %.02f\n", fUMoney);
						}
				}

				fChange = fUMoney - fTotal;
				printf("Total Change: %.02f\n", fChange);
				printf("DISPENSING CHANGE\n");

				while (fChange > 0 &&
					   y < 14){

						x = fChange / valMoney(y);
						if (x > 0){
							z = x;
							fChange -= valMoney(y) * x;
							printf("[%d] PHP %.02f\n", z, valMoney(y));
						}
						//printf("%.02f\n", fChange);
						y++;
				}

}

/* This function prints the Pizza Timer depending on the
Precondition: nTopCnt is a non-zero & non-negative value
@param nTopCnt is the number of toppings the user entered
@param nTotaltime, nMins & nSecs are the time values for
		total time, Minutes and seconds
*/
void
cookPizza(int nTopCnt, char cStuffs)
{
		int 	nTotaltime = 180,
				nMins,
				nSecs;

				printDivider();
				printf("\nCooking Pizza...\n");
				printf("Time Left| ");

				nTotaltime += nTopCnt * 2;
				if (cStuffs == 'c' ||
					cStuffs == 'C' ||
					cStuffs == 's' ||
					cStuffs == 'S'){
						nTotaltime += 5;
				}
				else if (cStuffs == 'b' ||
						 cStuffs == 'B'){
						nTotaltime += 10;
				}

				while (nTotaltime > 0){
						for (nMins = 3; nMins >= 0; nMins --){
								for (nSecs = nTotaltime % 60; nSecs >= 0; nSecs --){
										printf("%d:%02d\n", nMins, nSecs);
										nTotaltime --;
								}
						}
				}
}

int
main()
{
		int		nStep,
				nTopCnt = 0,
				nCrust = 0,
				nTransNum = 1;
		float	fSizePr,
				fTopMult,
				fTopP1,
				fTopP2,
				fTopP3,
				fStuffsP,
				fPZTotal = 0,
				fMoney = 0;
		char	cPizSize = 'a',
				cTops = 'a',
				cTop1 = 'a',
				cTop2 = 'a',
				cTop3 = 'a',
				cChType = 'a',
				cStuffs = 'a';


		while (nCrust != 80808 &&
			   fMoney != 80808) {

				printPizzaDets();

				//Asking for the Crust Type
				nStep = 1;
				while (nCrust != 1 &&
					   nCrust != 2 &&
					   nCrust != 80808){
						printf("Enter Crust Type: ");
						scanf(" %d", &nCrust);

						if (isValidCr(nCrust) == 0)
							isInvalidIn();
						else
							printChoice(nStep, nCrust, nTopCnt, cPizSize, cChType);
				}

				//GOES UNDER MAINTENCE IF nCRUST == 80808
				if (nCrust != 80808){

						//Asking for Pizza Size
						nStep = 2;
						while (isValidChar(nStep, cPizSize) != 1
							cPizSize != 'X' &&
							cPizSize != 'x'){
								printf("Enter Pizza Size: ");
								scanf(" %c", &cPizSize);

								if(isValidChar(nStep, cPizSize) == 0)
										isInvalidIn();
								else {
										getBasePrice(&fSizePr, &fTopMult, cPizSize);
										fPZTotal += fSizePr;
										printChoice(nStep, nCrust, nTopCnt, cPizSize, cChType);
										//printf("%f %f", fSizePr, fTopMult);
								}
						}

						//Asking for Toppings
						nStep = 3;
						while (nTopCnt < 3 &&
							   cTops != 'n' &&
							   cTops != 'N' &&
							   cTops != 'x' &&
							   cTops != 'X'){
								nStep = 3;
								printf("Pick Topping No. %d: ", nTopCnt + 1);
								scanf(" %c", &cTops);

								if (isValidChar (nStep, cTops) == 1){
										if (cTops == 'c' ||
											cTops == 'C'){
												//Asking for Cheese Type
												nStep = 4;
												cChType = 'a';
												while (isValidChar(nStep, cChType) != 1){
														printf("Enter Cheese Type: ");
														scanf(" %c", &cChType);
														if (isValidChar(nStep, cChType) == 0)
																isInvalidIn();
												}
										}

										printChoice(nStep, nCrust, nTopCnt, cTops, cChType);
										fPZTotal += computeToppings(cTops, fTopMult);
										//printf("%f\n", computeToppings(cTops, fTopMult));
										if (cTops != 'n' &&
											cTops != 'N'){
												nTopCnt ++;
												if (nTopCnt == 1){
														cTop1 = cTops;
														fTopP1 = computeToppings(cTops, fTopMult);
														if (cTops == 'c' ||
															cTops == 'C'){
																cTop1 = cChType;
																if (cChType == 'p' ||
																	cChType == 'P')
																		cTop1 = 'Z';
														}
												}
												else if (nTopCnt == 2){
														cTop2 = cTops;
														fTopP2 = computeToppings(cTops, fTopMult);
														if (cTops == 'c' ||
															cTops == 'C'){
																cTop2 = cChType;
															 	if (cChType == 'p' ||
																	cChType == 'P')
																		cTop2 = 'Z';
														}
												}
												else if (nTopCnt == 3){
														cTop3 = cTops;
														fTopP3 = computeToppings(cTops, fTopMult);
														if (cTops == 'c' ||
															cTops == 'C'){
																cTop3 = cChType;
																if (cChType == 'p' ||
																	cChType == 'P')
																		cTop3 = 'Z';
														}
												}
											}
								}
								else 
										isInvalidIn();

						}

						//If Thick Crust, Ask for Stuffing
						if (nCrust == 2){
								nStep = 5;
								while (isValidChar(nStep, cStuffs) != 1){
										printf("Enter Stuffing: ");
										scanf(" %c", &cStuffs);

										if (isValidChar(nStep, cStuffs) == 0)
												isInvalidIn();	
										else {
												fPZTotal += computeStuffings(cStuffs);
												fStuffsP = computeStuffings(cStuffs); 
												printChoice(nStep, nCrust, nTopCnt, cStuffs, cChType);
										}
								}
						}
						//Printing Receipt
						printReceipt(nTransNum, nCrust, fSizePr, fTopP1, fTopP2, fTopP3, fStuffsP,
									 fPZTotal, cPizSize, cTop1, cTop2, cTop3, cStuffs);

						//Printing Money Labels
						printMon();

						//Computing for Changes
						computeChange(fPZTotal);

						//Cooks Pizza w/ timer
						cookPizza(nTopCnt, cStuffs);

						//Increase Transaction Number
						nTransNum ++;

						//RESETTING VALUES
						nTopCnt = 0;
						nCrust = 0;
						fPZTotal = 0;
						fMoney = 0;
						cPizSize = 'a';
						cTops = 'a';
						cTop1 = 'a';
						cTop2 = 'a';
						cTop3 = 'a';
						cChType = 'a';
						cStuffs = 'a';
				}
		}
		printDivider();
		printf("\nTHE MACHINE IS NOW UNDER MAINTENANCE");
		return 0;
}
        