/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.
Ruiz, Chester Bryan C. - 12290190 - S19B
******************************************************************************/

/*   
     Description:      Running this program creates a turn-based tile shooter in the command prompt.
     Programmed by:    Ruiz, Chester Bryan C.   S19B
     Last modified:    Dec. 4, 2022
     Version:          3.2
*/

#include <stdio.h>
//"gcc -Wall RUIZMP.c -o run.exe"

/*   This function calculates the position of the enemies based on the value of nTurnX.
     Precondition: N/A
     @param nTurnX is the individual turn count of the enemy.
	 @param nXPosVal is the current position of the enemy.
     @return the new position of the enemy.
*/
int
calcXPos(int nTurnX, int nXPosVal)
{
	switch(nTurnX%4)
	{
		case 0: nXPosVal++; break;
		case 1: nXPosVal+=4; break;
		case 2: nXPosVal--; break;
		case 3: nXPosVal+=4; break;
	}
	return nXPosVal;
}

/*   This function increases the turn count of each individual enemy by 1.
     Precondition: N/A
     @param nTurnX is the individual turn count of the enemy.
     @return the new turn count of the enemy.
*/
int
increaseTurn(int nTurnX)
{
	nTurnX++;
	return nTurnX;
}

/*   This function checks to see if the enemy dies and adjusts the score accordingly, 
	 it also resets turn counter if enemy dies.
     Precondition: nXPosVal is a valid value (between 1-20), 
				   nPPosVal is a valid value (between 1-4).
     @param nXPosVal is the current position of the enemy.
	 @param nChoice is the action of the player.
	 @param nPPosVal is the current position of the player.
	 @param nScore is the current score of the player.
	 @param nTurnX is the individual turn count of the enemy.
     @return the position value of the enemy.
*/
int
checkDeath(int nXPosVal, int nChoice, int nPPosVal, int *nScore, int *nTurnX)
{
	if(nChoice == 3)
	{
		if(nPPosVal == 1 && (nXPosVal == 1 || nXPosVal == 5 || nXPosVal == 9 || nXPosVal == 13 || nXPosVal == 17))
		{
			nXPosVal = 1;
			*nScore += 10;
			*nTurnX = 0;
		}
		if(nPPosVal == 2 && (nXPosVal == 2 || nXPosVal == 6 || nXPosVal == 10 || nXPosVal == 14 || nXPosVal == 18))
		{
			nXPosVal = 1;
			*nScore += 10;
			*nTurnX = 0;
		}
		if(nPPosVal == 3 && (nXPosVal == 3 || nXPosVal == 7 || nXPosVal == 11 || nXPosVal == 15 || nXPosVal == 19))
		{
			nXPosVal = 1;
			*nScore += 10;
			*nTurnX = 0;
		}
		if(nPPosVal == 4 && (nXPosVal == 4 || nXPosVal == 8 || nXPosVal == 12 || nXPosVal == 16 || nXPosVal == 20))
		{
			nXPosVal = 1;
			*nScore += 10;
			*nTurnX = 0;
		}
	}	
	return nXPosVal;
}

/*   This function takes in the enemy position value and assigns enemy placement based on the value.
     Precondition: N/A
     @param nXPosVal is the current position of the enemy.
	 @param c1-c20 are the variable names for each tile on the enemy grid.
     @return [void function]
*/
void
putXOnBoard(int nXPosVal, char *c1, char *c2, char *c3, char *c4, char *c5, char *c6, char *c7, char *c8, char *c9, char *c10,
			char *c11, char *c12, char *c13, char *c14, char *c15, char *c16, char *c17, char *c18, char *c19, char *c20)
{
					
	switch(nXPosVal)
	{
		case 1:*c1 = 'X';break; case 2:*c2 = 'X';break; case 3:*c3 = 'X';break; case 4:*c4 = 'X';break;
		case 5:*c5 = 'X';break; case 6:*c6 = 'X';break; case 7:*c7 = 'X';break; case 8:*c8 = 'X';break;
		case 9:*c9 = 'X';break; case 10:*c10 = 'X';break; case 11:*c11 = 'X';break; case 12:*c12 = 'X';break;
		case 13:*c13 = 'X';break; case 14:*c14 = 'X';break; case 15:*c15 = 'X';break; case 16:*c16 = 'X';break;
		case 17:*c17 = 'X';break; case 18:*c18 = 'X';break; case 19:*c19 = 'X';break; case 20:*c20 = 'X';break;
	}
}

/*   This function calls the "putXonBoard" function and also prints the enemy grid.
     Precondition: N/A
     @param nX1PosVal is the current position of enemy 1.
	 @param nX2PosVal is the current position of enemy 2.
	 @param nX3PosVal is the current position of enemy 3.
     @return [void function]
*/
void
printEnemyBoard(int nX1PosVal, int nX2PosVal, int nX3PosVal)
{
	char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20;
	c1 = c2 = c3 = c4 = c5 = c6 = c7 = c8 = c9 = c10 = c11 = c12 = c13 = c14 = c15 = c16 = c17 = c18 = c19 = c20 = ' ';
	
	putXOnBoard(nX1PosVal, &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, &c10,
				 &c11, &c12, &c13, &c14, &c15, &c16, &c17, &c18, &c19, &c20);
	putXOnBoard(nX2PosVal, &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, &c10,
				 &c11, &c12, &c13, &c14, &c15, &c16, &c17, &c18, &c19, &c20);
	putXOnBoard(nX3PosVal, &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, &c10,
				 &c11, &c12, &c13, &c14, &c15, &c16, &c17, &c18, &c19, &c20);
	
    printf("     ----------------- *\n");
	printf("     | %c | %c | %c | %c | 1\n", c1, c2, c3, c4);
	printf("     | %c | %c | %c | %c | 2\n", c5, c6, c7, c8);
	printf("     | %c | %c | %c | %c | 3\n", c9, c10, c11, c12);
	printf("     | %c | %c | %c | %c | 4\n", c13, c14, c15, c16);
	printf("     | %c | %c | %c | %c | 5\n", c17, c18, c19, c20);
}

/*   This function calculates the position of the player and prints the player grid.
     Precondition: nPPosVal is a valid value (between 1-4).
     @param nChoice is the action of the player.
	 @param nPPosVal is the current position of the player.
     @return the player position value.
*/
int
calcPlayerMovement(int nChoice, int nPPosVal)
{
	char cLL, cLM, cRM, cRR;
	cLL = cLM = cRM = cRR = ' ';
	//left-left, left-middle, right-middle, right-right
	
	switch(nChoice)
	{
		case 1: nPPosVal--; break;	
		case 2: nPPosVal++; break;	
	}
	
	switch(nPPosVal)
	{
		case 0: cLL = 'P'; nPPosVal++;  break;
		case 1: cLL = 'P'; break;
		case 2: cLM = 'P'; break;
		case 3: cRM = 'P'; break;
		case 4: cRR = 'P'; break;
		case 5: cRR = 'P'; nPPosVal--; break;	
	}

	printf("     ----------------- *\n");
	printf("     | %c | %c | %c | %c |\n", cLL, cLM, cRM, cRR);
	printf("     ----------------- *\n");
			
	
	return nPPosVal;
}

/*   This function prints out the current score of the player.
     Precondition: N/A
     @param nScore is the current score of the player.
     @return [void function]
*/
void
showScore(int *nScore)
{
	printf("     Score: %03d\n", *nScore);
}

/*   This function asks the player for their next move, and checks if it's a valid action.
     Precondition: N/A
     @param nInvalidAct is the variable that stores the value of whether or not the user inputted an invalid action.
	 @param nAPoint is the current amount of ability points the player has.
     @return the player's action choice.
*/
int
askActions(int *nInvalidAct, int nAPoint)
{
	int nChoice;
	printf("\n Actions:\n");
	printf("     1 - Move left\n");
	printf("     2 - Move right\n");
	printf("     3 - Fire laser\n");
	printf("\n [Ability Points: %d]\n", nAPoint);
	printf("     4 - Freeze enemies (3 turns) [7 A-Points]\n");
	printf("         Note: A-Points won't generate in freeze mode.\n");
	printf("     5 - Bomb whole board [10 A-Points]\n");
	printf("\n Input Action: ");
	scanf("%d", &nChoice);
	
	if(nChoice != 1 && nChoice != 2 && nChoice != 3 && nChoice != 4 && nChoice != 5)
	{
		*nInvalidAct = 1;
		printf(" Invalid Action\n");
	}
	return nChoice;
}

/*   This function checks for whether or not the player has moved out of bounds.
     Precondition: N/A
	 @param nChoice is the action of the player.
	 @param nPPosVal is the current position of the player.
     @param nInvalidAct is the variable that stores the value of whether or not the user inputted an invalid action.
     @return [void function]
*/
void
checkOutofBounds(int nChoice, int nPPosVal, int *nInvalidAct)
{
	if(nChoice == 1 && nPPosVal == 1)
	{
		printf(" Out of bounds movement\n");
		*nInvalidAct = 1;
	} 
	if(nChoice == 2 && nPPosVal == 4)
	{
		printf(" Out of bounds movement\n");
		*nInvalidAct = 1;
	} 		
}

/*   This function checks for whether or not the player has won, lost, or tied.
     Precondition: N/A
	 @param nX1PosVal is the current position of enemy 1.
	 @param nX2PosVal is the current position of enemy 2.
	 @param nX3PosVal is the current position of enemy 3.
	 @param nScore is the current score of the player.
     @return [void function]
*/
void
checkVictory(int nX1PosVal, int nX2PosVal, int nX3PosVal, int *nScore)
{
	if(*nScore >= 100 && (nX1PosVal >= 21 || nX2PosVal >= 21 || nX3PosVal >= 21))
	{
		printf(" TIE!\n");//for the rare occasion that a tie occurs.
	}
	else if(*nScore >= 100)
	{
		printf(" VICTORY!\n");
		*nScore += 200;//in order to end the while loop.
	}
	else if(nX1PosVal >= 21 || nX2PosVal >= 21 || nX3PosVal >= 21)
	{
		printf(" DEFEATED!\n");
	}
}

/*   This function checks for whether or not two enemies share the same tile after death and readjusts the positions accordingly.
     Precondition: N/A
	 @param nX1PosVal is the current position of enemy 1.
	 @param nX2PosVal is the current position of enemy 2.
	 @param nX3PosVal is the current position of enemy 3.
     @return [void function]
*/
void
checkEnemyReposition(int *nX1PosVal, int *nX2PosVal, int *nX3PosVal)
{
	if(*nX1PosVal == 1 && *nX2PosVal == 1 && *nX3PosVal != 1)
	{
		*nX2PosVal = 2;//moves nX2PosVal to tile 2
	}	
	if(*nX2PosVal == 1 && *nX3PosVal == 1 && *nX1PosVal != 1)
	{
		*nX3PosVal = 2;
	}
	if(*nX1PosVal == 1 && *nX3PosVal == 1 && *nX2PosVal != 1)
	{
		*nX3PosVal = 2;
	}	
	if(*nX1PosVal == 1 && *nX2PosVal == 1 && *nX3PosVal == 1)
	{
		*nX2PosVal = 2;//moves nX2PosVal to tile 2
		*nX3PosVal = 3;//moves nX3PosVal to tile 3
	}
}

/*   This function checks if the player choses to use the freeze function; if yes, it checks if the player has accumulated
	 enough ability points and triggers freeze function (if yes) and prints warning (if not).
     Precondition: N/A
	 @param nAPoint is the current amount of ability points the player has.
	 @param nInvalidAct is the variable that stores the value of whether or not the user inputted an invalid action.
	 @param nFreezeCount is the current freeze turn count.
	 @param nChoice is the action of the player.
     @return [void function]
*/
void
purchaseFreeze(int *nAPoint, int *nInvalidAct, int *nFreezeCount, int nChoice)
{
	if(nChoice == 4)
	{
		if(*nAPoint < 7)
		{
			printf(" Not enough A-Points!\n");
			*nInvalidAct = 1;
		}
		else if(*nAPoint >= 7)
		{
			*nAPoint-=7;
			*nFreezeCount = 3;//3 turns of freeze.
		}
	}
}

/*   This function checks if the player choses to use the bomb function; if yes, it checks if the player has accumulated
	 enough ability points and triggers bomb function (if yes) and prints warning (if not).
     Precondition: N/A
	 @param nAPoint is the current amount of ability points the player has.
	 @param nInvalidAct is the variable that stores the value of whether or not the user inputted an invalid action.
	 @param nChoice is the action of the player.
	 @param nX1PosVal is the current position of enemy 1.
	 @param nX2PosVal is the current position of enemy 2.
	 @param nX3PosVal is the current position of enemy 3.
	 @param nTurnX1 is the individual turn count of enemy 1.
	 @param nTurnX2 is the individual turn count of enemy 2.
	 @param nTurnX3 is the individual turn count of enemy 3.
	 @param nScore is the current score of the player.
     @return [void function]
*/
void
purchaseBomb(int *nAPoint, int *nInvalidAct, int nChoice, int *nX1PosVal, int *nX2PosVal, int *nX3PosVal, int *nTurnX1, int *nTurnX2, int *nTurnX3, int *nScore)
{
	if(nChoice == 5)
	{
		if(*nAPoint < 10)
		{
			printf(" Not enough A-Points!\n");
			*nInvalidAct = 1;
		}
		else if(*nAPoint >= 10)
		{
			printf(" Board bombed!\n");
			*nAPoint-=10;
			//Changes the enemy's position to as if they were all shot.
			*nX1PosVal = 1;
			*nX2PosVal = 1; 
			*nX3PosVal = 1; 
			*nTurnX1 = 0;
			*nTurnX2 = 0;
			*nTurnX3 = 0;
			*nScore+=30;
		}
	}
}

int main(){
	int nChoice;
	int nInvalidAct = 0;
	int nPPosVal = 1;//Player Position Value
	int nTurnX1 = -1;//Enemy 1 Turn Count
	int nTurnX2 = -1;
	int nTurnX3 = -1;
	int nX1PosVal = 1;//Enemy 1 Position Value
	int nX2PosVal = 2;
	int nX3PosVal = 3;
	int nScore = 0;
	int nFreezeCount = 0;//Freeze Duration
	int nAPoint = -1;//Ability Point

	while(nX1PosVal < 21 && nX2PosVal < 21 && nX3PosVal < 21 && nScore < 150)
	{
		
		//if player input is invalid the portion won't be executed.
		if(nInvalidAct == 0 && nFreezeCount == 0)
		{
			nX1PosVal = calcXPos(nTurnX1, nX1PosVal);
			nX2PosVal = calcXPos(nTurnX2, nX2PosVal);
			nX3PosVal = calcXPos(nTurnX3, nX3PosVal);
			
			nTurnX1 = increaseTurn(nTurnX1);
			nTurnX2 = increaseTurn(nTurnX2);
			nTurnX3 = increaseTurn(nTurnX3);
			
			//[note: Can't generate ability points when in freeze mode otherwise it'll just be unbalanced.]
			nAPoint++;
		}
		
		if(nFreezeCount != 0)
		{//Freeze duration decrease per turn.
			if(nInvalidAct == 0)
			{
				nFreezeCount--;
			}
			printf(" Freeze turn remaining: %d!\n", nFreezeCount);
		}
		
		nInvalidAct = 0;//nInvalidAct gets reset back to 0.
		printEnemyBoard(nX1PosVal, nX2PosVal, nX3PosVal);//Prints enemy board.
		nPPosVal = calcPlayerMovement(nChoice, nPPosVal);//Prints player board.
		checkVictory(nX1PosVal, nX2PosVal, nX3PosVal, &nScore);//Checks for win/lose/tie.

		//Checks if this portion should be executed. [mostly here to follow the same game over screen format as the sample runs]
		if(nX1PosVal < 21 && nX2PosVal < 21 && nX3PosVal < 21 && nScore < 100)
		{
			showScore(&nScore);
			nChoice = askActions(&nInvalidAct, nAPoint);
			checkOutofBounds(nChoice, nPPosVal, &nInvalidAct);
				
			//Checks if the player has shot an enemy/if an enemy has died; if yes: resets enemy's position and turn count.
			nX1PosVal = checkDeath(nX1PosVal, nChoice, nPPosVal, &nScore, &nTurnX1);
			nX2PosVal = checkDeath(nX2PosVal, nChoice, nPPosVal, &nScore, &nTurnX2);
			nX3PosVal = checkDeath(nX3PosVal, nChoice, nPPosVal, &nScore, &nTurnX3);
			
			//Freeze Action
			purchaseFreeze(&nAPoint, &nInvalidAct, &nFreezeCount, nChoice);	
			
			//Bomb Board Action
			purchaseBomb(&nAPoint, &nInvalidAct, nChoice, &nX1PosVal, &nX2PosVal, &nX3PosVal, &nTurnX1, &nTurnX2, &nTurnX3, &nScore);	
		}	
		//Repositioning the other enemies in case more than 1 enemy die at a time.
		checkEnemyReposition(&nX1PosVal, &nX2PosVal, &nX3PosVal);
	}//end while loop
    return 0;
}