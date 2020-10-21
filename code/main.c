/*
       Program to find possible moves to move man, goat, 
       wolf, cabagges from left bank to right bank.
*/

#include<stdio.h>
#include<stdlib.h>
#include"fsm_util.c"   // for fsm utilities like transition function

void display_state(STATE *s); // to print left bank and right bank status of a state

void read_state_status();     // to read status of left bank and right bank from a file for a state

void read_transition_table(); // to read transitoin function from a file

void print_all_possible(STATE *temp1); // to print possible solutions

void read_fsm();

STATE *s[11], *d1, *d2, *temp; /* d1 represent a state where either goat and wolf or goat
                                  wolf and cabagges are together.
                                  d2 represent a state where goat and cabaggegs are together.
                               */   
FSM *fsm;
int count = 0;  // to count the no. of possible solutions

int main()
	 {
		int m,ch = 0, *input_seq, input_seq_len;
		
		printf("\n                   OHH IT'S A GAME... \n\n ");
		printf("     M , G , W , C                _ , _ , _ , _ \n");
		printf("-------------------,            ,-----------------------\n"); 
		printf("                   | - - - - - -|\n");
		printf("                   |- - - - - - |\n");
		printf("                   | - - - - - -|\n");
		printf("\nYou have to move all four (man , goat , wolf , soak of cabbages) from left bank of river to it's right bank.\n");
		printf("\nRules :- \n");
		printf("1.Only one entity( animal or thing ) man can carry with him on the boat, therefore only following moves can be possible for a state :-\n  a.Only man : (M)\n  b.Man & Goat : (M,G)\n  c.Man & Wolf : (M,W)\n  d.Man & Cabbages : (M,C)\n");
		printf("2.All these moves are possible in two directions:- \n  a.From letf to right \n  b.From right to left\n\n");
		do
			 {
				printf("\n     M , G , W , C                _ , _ , _ , _ \n");
				printf("-------------------,            ,-----------------------\n"); 
				printf("                   | - - - - - -|\n");
				printf("                   |- - - - - - |\n");
				printf("                   | - - - - - -|\n");
				printf("\nPossible moves :- \n");
				printf("  1.Move (M) to right\n");
				printf("  2.Move (M,G) to right\n");
				printf("  3.Move (M,W) to right\n");
				printf("  4.Move (M,C) to right\n");
				printf("  5.Move (M) to left\n");
				printf("  6.Move (M,G) to left\n");
				printf("  7.Move (M,W) to left\n");
				printf("  8.Move (M,C) to left\n");

				printf("Enter no. of moves you want to use : ");
				scanf("%d",&input_seq_len);
				input_seq = (int *)malloc(sizeof(int)*input_seq_len);
			
				printf("Enter the input sequence : ");
				for(int i = 0 ; i<input_seq_len ; i++)
				scanf("%d",&input_seq[i]);

				read_fsm();

				temp = fsm->start_state;

				/*Taking sequence of moves as input from the user*/

				for(int i = 0 ; i<input_seq_len ; i++)
					 {
						switch(input_seq[i])
							 {
								case 1 : printf("\nMoving (M) to right\n");
												 temp = temp->move[0];
												 if(temp == NULL)
														{
														 printf("\nThis move is not possible\n\n");
														 goto L;
														}
											     if(temp == d1)
											            {
                                                         printf("\nWolf has eaten tha goat.\nUnsuccessful\n\n");
                                                         goto L;
											            }
											     if(temp == d2)
											            {
                                                         printf("\nGoat has eaten tha cabbages.\nUnsuccessful\n\n");
                                                         goto L;
											            }       			
												 break;

								case 2 : printf("\nMoving (M,G) to right\n");
												 temp = temp->move[1];
												 if(temp == NULL)
														{
														 printf("\nThis move is not possible\n\n");
														 goto L;
														}
											     if(temp == d1)
											            {
                                                         printf("\nWolf has eaten tha goat.\nUnsuccessful\n\n");
                                                         goto L;
											            }
											     if(temp == d2)
											            {
                                                         printf("\nGoat has eaten tha cabbages.\nUnsuccessful\n\n");
                                                         goto L;
											            }			
												 break;

								case 3 : printf("\nMoving (M,W) to right\n");
												 temp = temp->move[2];
												 if(temp == NULL)
														{
														 printf("\nThis move is not possible\n\n");
														 goto L;
														}
												 if(temp == d1)
											            {
                                                         printf("\nWolf has eaten tha goat.\nUnsuccessful\n\n");
                                                         goto L;
											            }
											     if(temp == d2)
											            {
                                                         printf("\nGoat has eaten tha cabbages.\nUnsuccessful\n\n");
                                                         goto L;
											            }		
												 break;

								case 4 : printf("\nMoving (M,C) to right\n");
												 temp = temp->move[3];
												 if(temp == NULL)
												    {
														 printf("\nThis move is not possible\n\n");
														 goto L;
												    } 
												 if(temp == d1)
											            {
                                                         printf("\nWolf has eaten tha goat.\nUnsuccessful\n\n");
                                                         goto L;
											            }
											     if(temp == d2)
											            {
                                                         printf("\nGoat has eaten tha cabbages.\nUnsuccessful\n\n");
                                                         goto L;
											            }   
												 break;

								case 5 : printf("\nMoving (M) to left\n");
												 temp = temp->move[4];
												 if(temp == NULL)
												    {
														 printf("\nThis move is not possible\n\n");
														 goto L;
												    }
												 if(temp == d1)
											            {
                                                         printf("\nWolf has eaten tha goat.\nUnsuccessful\n\n");
                                                         goto L;
											            }
											     if(temp == d2)
											            {
                                                         printf("\nGoat has eaten tha cabbages.\nUnsuccessful\n\n");
                                                         goto L;
											            }   
												 break;      

								case 6 : printf("\nMoving (M,G) to left\n");
												 temp = temp->move[5];
												 if(temp == NULL)
												    {
														 printf("\nThis move is not possible\n\n");
														 goto L;
												    }
												 if(temp == d1)
											            {
                                                         printf("\nWolf has eaten tha goat.\nUnsuccessful\n\n");
                                                         goto L;
											            }
											     if(temp == d2)
											            {
                                                         printf("\nGoat has eaten tha cabbages.\nUnsuccessful\n\n");
                                                         goto L;
											            }   
												 break;
												 
								case 7 : printf("\nMoving (M,W) to left\n");
												 temp = temp->move[6];
												 if(temp == NULL)
												    {
														 printf("\nThis move is not possible\n\n");
														 goto L;
												    }
												 if(temp == d1)
											            {
                                                         printf("\nWolf has eaten tha goat.\nUnsuccessful\n\n");
                                                         goto L;
											            }
											     if(temp == d2)
											            {
                                                         printf("\nGoat has eaten tha cabbages.\nUnsuccessful\n\n");
                                                         goto L;
											            }   
												 break;
												 
								case 8 : printf("\nMoving (M,C) to left\n");
												 temp = temp->move[7];
												 if(temp == NULL)
												    {
														 printf("\nThis move is not possible\n\n");
														 goto L;
												    }
												 if(temp == d1)
											            {
                                                         printf("\nWolf has eaten tha goat.\nUnsuccessful\n\n");
                                                         goto L;
											            }
											     if(temp == d2)
											            {
                                                         printf("\nGoat has eaten tha cabbages.\nUnsuccessful\n\n");
                                                         goto L;
											            }   
												 break; 
								
								default : printf("\nMove is not valid, select a move from 1 to 8 only.\n\n");
													goto L;                                                                  
						   }
						 
						display_state(temp);
			     }

		    if(temp == fsm->final_state)
						printf("\n\nSuccessful\n\n");
				else
						printf("\n\nUnsuccessful\n\n");

		    L : printf("\nWant to play again (1) or find all possible solutions(press any other digit) : ");
		    scanf("%d",&ch);      

	     }while(ch == 1);           

		
		printf("\nLets find out all possible solutions of this problem \n\n");
		print_all_possible(s[1]);
		printf("\nSo total %d solutions exist for this problem.\n\n",count);

	return 0;
}

/*
Reading the states inorder to provide a better visualization 
through GUI
*/

void read_state_status()
{
		FILE *fp;
		fp = fopen("state_status.txt","rb");
		for(int i = 1 ; i<=fsm->no_of_states ; i++)
		{
				fscanf(fp,"%c%c%c%c%c%c%c%c", &s[i]->left_bank[0], &s[i]->left_bank[1],
									 &s[i]->left_bank[2], &s[i]->left_bank[3], &s[i]->right_bank[0], 
									 &s[i]->right_bank[1], &s[i]->right_bank[2], &s[i]->right_bank[3]); 
		}
		fclose(fp);
}

/*
Displaying a visualization of moves that occur.
*/

void display_state(STATE *s)
{
	 printf("\n");
	 printf("\t\b\b%c , %c , %c , %c",s->left_bank[0], s->left_bank[1], s->left_bank[2], s->left_bank[3]);
	 printf("\t\t %c , %c , %c , %c\n",s->right_bank[0], s->right_bank[1], s->right_bank[2], s->right_bank[3]);
	 printf("-------------------,            ,-----------------------\n"); 
	 printf("                   | - - - - - -|\n");
	 printf("                   |- - - - - - |\n");
	 printf("                   | - - - - - -|\n");         
}

/*
Populating the state objects from the values of the transition table
*/


void read_transition_table()
{
		int temp;
		FILE *fp;
		fp = fopen("transition.txt","rb");
		for(int i = 1 ; i<=10 ; i++)
				for(int j = 0 ; j<8 ; j++)
				{
						fscanf(fp,"%d",&temp);
						//fsm->delta[i][j] = temp;
						//printf("%d\t",temp);
						switch(temp)
						{
								case 0 : s[i]->move[j] = NULL;
												 break;
								case 1 : s[i]->move[j] = s[1];
												 break;
								case 2 : s[i]->move[j] = s[2];
												 break;
								case 3 : s[i]->move[j] = s[3];
												 break;
								case 4 : s[i]->move[j] = s[4];
												 break; 
								case 5 : s[i]->move[j] = s[5];
												 break;
								case 6 : s[i]->move[j] = s[6];
												 break;
								case 7 : s[i]->move[j] = s[7];
												 break;
								case 8 : s[i]->move[j] = s[8];
												 break;
								case 9 : s[i]->move[j] = s[9];
												 break;
								case 10 : s[i]->move[j] = s[10];
												 break;         
								case 11 : s[i]->move[j] = d1;
												 break;
								case 12 : s[i]->move[j] = d2;
												 break;				                               
						}
				}
		fclose(fp);
}

/* Printing all possible states by taking first state as input and 
performing a DFS like search through the states of the finite state machine
and finding multiple paths between start state and final state.
*/
 
	
void print_all_possible(STATE *temp1)
{
		STATE *temp2 = NULL;
		int current_state;
					 for(int j=1 ; j<11 ; j++)
							 if(temp1==s[j])
							 {
									 if(temp1==s[8])
									 {
										count++;
										printf("\n\nNow we are at state %d (final state).\n",j);
										display_state(s[j]);
										printf("\nYeah we found a solution.\n");
										printf("\n--------------------------------------x-------------------------------------\n\n\n");
									 } 
									 else
									 {
										printf("\n\nNow we are at state %d.\n",j);
										display_state(s[j]);
									 }
								current_state = j;

							 }
			 
					 if(temp1->move[0]!=NULL && temp1->move[0]!=d1 && temp1->move[0]!=d2)
						{ 
							if(temp2!=NULL)
								printf("Trying another possible move from state %d \n",current_state);
							printf("\nTaking move 1 : Move (M) to right\n");
							temp2 = temp1->move[0];
							print_all_possible(temp2);
						}
						if(temp1->move[1]!=NULL && temp1->move[1]!=d1 && temp1->move[1]!=d2)
						{ 
							if(temp2!=NULL)
								printf("Trying another possible move from state %d \n",current_state);
							printf("\nTaking move 2 : Move (M,G) to right\n");;
							temp2 = temp1->move[1];
							print_all_possible(temp2);
						}         
						if(temp1->move[2]!=NULL && temp1->move[2]!=d1 && temp1->move[2]!=d2)
						{
							 if(temp2!=NULL)
								printf("Trying another possible move from state %d \n",current_state); 
							 printf("\nTaking move 3 : Move (M,W) to right\n");
							 temp2 = temp1->move[2];
							 print_all_possible(temp2);
						}
						if(temp1->move[3]!=NULL && temp1->move[3]!=d1 && temp1->move[3]!=d2)
						{
							 if(temp2!=NULL)
								printf("Trying another possible move from state %d \n",current_state); 
							 printf("\nTaking move 4 : Move (M,C) to right\n");;
							 temp2 = temp1->move[3];
							 print_all_possible(temp2);
						}
						if(temp1->move[4]!=NULL && temp1->move[4]!=d1 && temp1->move[4]!=d2)
						{
							 if(temp2!=NULL)
								printf("Trying another possible move from state %d \n",current_state); 
							 printf("\nTaking move 5 : Move (M) to left\n");;
							 temp2 = temp1->move[4];
							 print_all_possible(temp2);
						}
						if(temp1->move[5]!=NULL && temp1->move[5]!=d1 && temp1->move[5]!=d2)
						{
							 if(temp2!=NULL)
								printf("Trying another possible move from state %d \n",current_state); 
							 printf("\nTaking move 6 : Move (M,G) to left\n");;
							 temp2 = temp1->move[5];
							 print_all_possible(temp2);
						}
						if(temp1->move[6]!=NULL && temp1->move[6]!=d1 && temp1->move[6]!=d2)
						{
							 if(temp2!=NULL)
								printf("Trying another possible move from state %d \n",current_state); 
							 printf("\nTaking move 7 : Move (M,W) to left\n");;
							 temp2 = temp1->move[6];
							 print_all_possible(temp2);
						}
						if(temp1->move[7]!=NULL && temp1->move[7]!=d1 && temp1->move[7]!=d2) 
						{ 
								if(temp2!=NULL)
								printf("\nTrying another possible move from state %d \n",current_state);
								printf("\nTaking move 8 : Move (M,C) to left\n");;
								temp2 = temp1->move[7];
								print_all_possible(temp2);  
						} 


}
/*Construction of an FSM object, allocating memory and populating
it with the required states and state transition moves for each state.*/

void read_fsm()
   {
   	int inputs[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    fsm = (FSM *)malloc(sizeof(FSM));
	fsm->no_of_states = 10;

    int p = 1;
				while(p<11)
					 {
						s[p] = (STATE *)malloc(sizeof(STATE));
						for(int k = 0 ; k<8 ; k++)
							 {
								s[p]->move[k] = (STATE *)malloc(sizeof(STATE));
							 }
						p++;
					 }

			    d1 = (STATE *)malloc(sizeof(STATE));
			    d2 = (STATE *)malloc(sizeof(STATE)); 		 

				
	fsm->input_alphabet = inputs;

    fsm->start_state = s[1];
	fsm->final_state = s[8];

	read_state_status();
	read_transition_table();
   	
}


