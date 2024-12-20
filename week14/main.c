//
//  main.c
//  sharkGame
//

#include <stdio.h>
// ----- EX. 1 : Preparation------------
#include <stdlib.h>
#include <time.h>
// ----- EX. 1 : Preparation------------
#include "board.h"

// ----- EX. 4 : player ------------
#define N_PLAYER            3
// ----- EX. 4 : player ------------

#define MAX_CHARNAME        200

// ----- EX. 3 : board ------------
#define MAX_DIE             6

// ----- EX. 4 : player ------------
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"};
// ----- EX. 4 : player ------------

// ----- EX. 3 : board ------------
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}
// ----- EX. 3 : board ------------

// ----- EX. 1 : Preparation------------
void opening(void)
{
    printf("==============================================================\n");
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
    printf("==============================================================\n");
}
// ----- EX. 1 : Preparation------------

// ----- EX. 6 : game end ------------
int game_end(void)
{
    int i;
    int flag_end = 1;
    
    //if all the players are died?
    //or have reached the last position
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE && player_position[i]<N_BOARD -1)
        {
            flag_end = 0;
            break;
        }
    }
    
    // if all players die 
    if(flag_end)
    {
    	printf("no more moves allowed\n");
	}
    return flag_end;
}
// ----- EX. 6 : game end ------------

// ----- EX. 4 : player ------------
void printPlayerPosition(int player)
{
    int i;
    
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (player_position[player] == i)
            printf("%c", player_name[player][0]);
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
            else
                printf(" ");
        }
    }
    printf("|\n");
}

void printPlayerStatus(void)
{
    int i;
    printf("player status ---\n");
    for (i=0;i<N_PLAYER;i++)
    {
        printf("%s : pos %i, coin %i, status %s\n\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);
    }
    printf("-----------------\n");
}
// ----- EX. 4 : player ------------

// ----- EX. 5 : shark ------------
void checkDie(void)
{
    int i;
    for (i=0;i<N_PLAYER;i++)
    {
        if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
        {
            printf("%s in pos %i has died!! (coin %i)\n\n", player_name[i], player_position[i], player_coin[i]);
            player_status[i] = PLAYERSTATUS_DIE;
        }
    }
}
// ----- EX. 5 : shark ------------

// ----- EX. 6 : game end ------------
int getAlivePlayer(void)
{
   int i;
   int cnt=0;
   for (i=0; i<N_PLAYER;i++)
   {
   		if(player_status[i]==PLAYERSTATUS_END)
   			cnt++;
   }
   
   return cnt;
}

int getWinner(void)
{
 	int i;
	int winner=-1;
	int max_coin=-1;
	int usain_bolt = N_BOARD; // for find the fastest player
	
	for (i=0;i<N_PLAYER;i++) //find the winner after finding the living players
	{
		if(player_status[i]==PLAYERSTATUS_END){
		
			if(player_coin[i]>max_coin|| (player_coin[i]==max_coin &&player_position[i]<usain_bolt))
			{
				max_coin = player_coin[i];
				usain_bolt = player_position[i];
				winner = i;
			}
	   }   }
	   
	   
	   
	   return winner;
}
// ----- EX. 6 : game end ------------


int main(int argc, const char * argv[]) {
    srand(time(NULL));
    
    int i;
    int turn=0;

// ----- EX. 1 : Preparation------------
    srand(time(NULL));
    opening();
// ----- EX. 1 : Preparation------------

// ----- EX. 2 : structuring ------------
    //step1 : initialization
    //step1-1 : board initialization
    board_initBoard();

// ----- EX. 4 : player ------------
    //step1-2 : initialize player
    for (i=0;i<N_PLAYER;i++)
    {
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]);
    }
    
// ----- EX. 4 : player ------------
    
    //step 2. : game start, turn loop
    do {
        int dieResult;
        int coinResult;
        int dum;

// ----- EX. 4 : player ------------
        if (player_status[turn] != PLAYERSTATUS_LIVE)
        {
            turn = (turn + 1)%N_PLAYER; //skip to next player
            continue;
        }
// ----- EX. 4 : player ------------
        
        //step 2-1. status printing
// ----- EX. 3 : board ------------
        board_printBoardStatus();
// ----- EX. 3 : board ------------
// ----- EX. 4 : player ------------
        printPlayerStatus();
// ----- EX. 4 : player ------------

        //step 2-2. rolling die
// ----- EX. 4 : player ------------
        printf("%s turn!! ", player_name[turn]);
        printf("Press any key to roll a die!\n");
        scanf("%d", &dum);
        fflush(stdin);
        
        //if the player has reached the end of the board
        if(player_position[turn]>=N_BOARD-1){
        	player_status[turn] = PLAYERSTATUS_END; // set the players status to end
        	printf("%s has already reached the goal.\n", player_name[turn]);
        	turn = (turn +1)%N_PLAYER; //skip to the next
        	continue; //skip the die rolling 
		}
// ----- EX. 4 : player ------------
        dieResult = rolldie();
        
        
        //step 2-3. moving
   		player_position[turn]+=dieResult;
   		
   		//check if the player has reached the end of the board
   		if(player_position[turn]>=N_BOARD-1)
   			{
   				player_status[turn]=PLAYERSTATUS_END;
   				player_position[turn]=N_BOARD -1;
   				printf("Die result : %d, %s moved to %d!\n\n", dieResult, player_name[turn], player_position[turn]);
			   }
		else
			printf("Die result : %d, %s moved to %d!\n\n", dieResult, player_name[turn], player_position[turn]);
        
		
		//step 2-4. coin : coin collection
        
        
        coinResult =board_getBoardCoin(player_position[turn]);
        player_coin[turn]+=coinResult;
        if(coinResult!=0){
		
        	printf("coin : %d, the coin %s earned so far : %d\n", coinResult, player_name[turn], player_coin[turn]);}
        //step 2-5. end process
    
        turn= (turn+1)%N_PLAYER; //turn organization
    
// ----- EX. 5 : shark ------------
		if (turn == 0)
		        {
		            int shark_pos = board_stepShark();
		            printf("Shark moved to %i\n", shark_pos);
		            //check die
		            checkDie();
		        }
        
// ----- EX. 6 : game end ------------
    } while(game_end() == 0);
    
    //step 3. game end process
    printf("GAME END!!\n");
    if (getWinner() ==-1)
    	printf("no winner!\n");
	else
    printf("%i players are alive! winner is %s\n", getAlivePlayer(), player_name[getWinner()]);

// ----- EX. 6 : game end ------------
    
// ----- EX. 2 : structuring ------------

    return 0;
}
