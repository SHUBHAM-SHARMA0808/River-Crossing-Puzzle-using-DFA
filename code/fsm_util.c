#include"state_util.c"
typedef struct fsm
{ 
	int no_of_states;
	STATE *start_state;
	int *input_alphabet;
    int **delta;
    STATE *final_state;
}FSM;